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