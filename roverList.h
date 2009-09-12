#ifndef roverList_H
#define roverList_H

#include "linkedListNode.h"

template <typename K, typename V> class roverList
{
public:

	roverList(void)
	{
		m_current = NULL;
	}

	~roverList(void)
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
		rewind();
		while (m_current != NULL)
		{
			linkedListNode<K, V>* tmp = m_current;
			m_current = tmp->next;
			delete tmp;
		}
	}

	void rewind()
	{
		if (m_current == NULL)
			return;
		while (m_current->prev != NULL)
		{
			m_current = m_current->prev;
		}
	}

protected:
	linkedListNode<K, V>* m_current;

	linkedListNode<K, V>* find(const K& key)
	{
		if (m_current == NULL)
			return NULL;
		while (1)
		{
			if (key == m_current->key)
				return m_current;
			if (key > m_current->key)
			{
				if (m_current->next == NULL)
					return NULL;
				else
				{
					m_current = m_current->next;
					continue;
				}
			}
			if (key < m_current->key)
			{
				if (m_current->prev == NULL)
					return NULL;
				else
				{
					m_current = m_current->prev;
					continue;
				}
			}
			return NULL;
		}
	}

	linkedListNode<K, V>* insert(const K& key)
	{
		linkedListNode<K, V>* newNode = new linkedListNode<K, V>(key);
		if (m_current == NULL)
		{
			m_current = newNode;
			return m_current;
		}
		while (1)
		{
			if (key > m_current->key)
			{
				if (m_current->next == NULL)
				{
					m_current->next = newNode;
					newNode->prev = m_current;
					m_current = newNode;
					break;
				}
				else
				{
					if (key < m_current->next->key)
					{
						linkedListNode<K, V>* tmp = m_current->next;
						m_current->next = newNode;
						newNode->prev = m_current;
						tmp->prev = newNode;
						newNode->next = tmp;
						m_current = newNode;
						break;
					}
					else
					{
						m_current = m_current->next;
						continue;
					}
				}
			}
			if (key < m_current->key)
			{
				if (m_current->prev == NULL)
				{
					m_current->prev = newNode;
					newNode->next = m_current;
					m_current = newNode;
					break;
				}
				else
				{
					if (key > m_current->prev->key)
					{
						linkedListNode<K, V>* tmp = m_current->prev;
						m_current->prev = newNode;
						newNode->next = m_current;
						tmp->next = newNode;
						newNode->prev = tmp;
						m_current = newNode;
						break;
					}
					else
					{
						m_current = m_current->prev;
						continue;
					}
				}
			}
			throw "Unexpected error!";
		}
		return m_current;
	}
};

#endif