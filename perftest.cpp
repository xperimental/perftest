// perftest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include "time.h"

using std::cout;
using std::endl;

#define MAX_ELEMENTS 100000

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Small performance comparison of different dynamic datastructures." << endl;

	cout << "std::map:" << endl
		<< "\tinsertion: ";
	long time = clock();
	std::map<int, int> map;
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		map[i] = MAX_ELEMENTS - i;
	}
	time = (clock() - time) / CLOCKS_PER_MS;
	cout << time << "ms" << endl;

	cout << "Press <RETURN>." << endl;
	std::cin.get();
	return 0;
}

