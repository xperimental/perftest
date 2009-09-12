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