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
#ifndef linkedListNode_H
#define linkedListNode_H

template <typename K, typename V> class linkedListNode
{
public:
	linkedListNode(void)
		: key(), value(), prev(0), next(0)
	{
	}

	linkedListNode(const K& newKey)
		: key(newKey), value(), prev(0), next(0)
	{
	}

	K key;
	V value;

	linkedListNode<K, V>* prev;
	linkedListNode<K, V>* next;
};

#endif