/*
This file is part of perftest.

perftest is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

perftest is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with perftest.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef linkedList_H
#define linkedList_H

#include "linkedListNode.h"

template <typename K, typename V> class linkedList
{
public:

	linkedList(void)
	{
		m_head = NULL;
	}

	~linkedList(void)
	{
		clear();
	}

	V& operator[](const K& key)
	{
		linkedListNode<K, V>* node = find(key);
		if (node == NULL)
		{
			node = insert(key);
		}
		return node->value;
	}

	void clear()
	{
		while (m_head != NULL)
		{
			linkedListNode<K, V>* tmp = m_head;
			m_head = tmp->next;
			delete tmp;
		}
	}

protected:
	linkedListNode<K, V>* m_head;

	linkedListNode<K, V>* find(const K& key) const
	{
		linkedListNode<K, V>* node = m_head;
		if (node == NULL)
			return NULL;
		while ((key > node->key) && (node->next != NULL))
		{
			node = node->next;
		}
		if (key == node->key)
			return node;
		return NULL;
	}

	linkedListNode<K, V>* insert(const K& key)
	{
		if (m_head == NULL)
		{
			m_head = new linkedListNode<K, V>(key);
			return m_head;
		}
		linkedListNode<K, V>* node = m_head;
		while ((key > node->key) && (node->next != NULL))
		{
			node = node->next;
		}
		linkedListNode<K, V>* newNode = new linkedListNode<K, V>(key);
		newNode->prev = node->prev;
		if (newNode->prev != NULL)
			newNode->prev->next = newNode;
		newNode->next = node;
		node->prev = newNode;
		return newNode;
	}
};

#endif