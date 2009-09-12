// perftest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include "time.h"

#include "linkedList.h"

using std::cout;
using std::endl;

#define MAX_ELEMENTS 1000000
#define RAND_ACCESS 100000

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

int randomIndex()
{
	return (int)((double)rand() / (RAND_MAX + 1) * (MAX_ELEMENTS - 1));
}

void stdMap(int* access)
{
	std::map<int, int> map;

	cout << "std::map:" << endl
		<< "\tinsertion (" << MAX_ELEMENTS << " elements): ";
	long time = clock();
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		map[i] = MAX_ELEMENTS - i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	cout << "\trandom access (" << RAND_ACCESS <<" accesses): ";
	time = clock();
	for (int i = 0; i < RAND_ACCESS; i++)
	{
		map[access[i]] = i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	cout << "\tsequential access: ";
	time = clock();
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		map[i] = MAX_ELEMENTS - i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	map.clear();
}

void list(int* access)
{
	linkedList<int, int> list;

	cout << "doubly linked list:" << endl
		<< "\tinsertion (" << MAX_ELEMENTS << " elements): ";
	long time = clock();
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		list[i] = MAX_ELEMENTS - i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	cout << "\trandom access (" << RAND_ACCESS <<" accesses): ";
	time = clock();
	for (int i = 0; i < RAND_ACCESS; i++)
	{
		list[access[i]] = i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	cout << "\tsequential access: ";
	time = clock();
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		list[i] = MAX_ELEMENTS - i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Small performance comparison of different dynamic datastructures." << endl;

	cout << "Creating random access pattern..." << endl;
	srand( (unsigned)time( NULL ) );
	int* access = new int[RAND_ACCESS];
	for (int i = 0; i < RAND_ACCESS; i++)
	{
		access[i] = randomIndex();
	}

	stdMap(access);
	list(access);

	delete[] access;
	return 0;
}

