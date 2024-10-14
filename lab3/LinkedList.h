#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class Node {
	T value;
	Node* next;
};

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:

	size_t m_size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr; 
	tail = nullptr;
	m_size = 0;
	
}

template <typename T>
void LinkedList<T>::append(T v)
{
	Node<T>* new_node = new Node<T>(v);
    if (empty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    m_size++;
}

template <typename T>
void LinkedList<T>::insert(size_t idx, T v)
{
	if (idx > m_size) {
        cout << "Error. Out of Bounds. " << endl;
		return 0;
    }
    Node<T>* new_node = new Node<T>(v);
    if (idx == 0) {
        new_node->next = head;
        head = new_node;
        if (empty()) {
            tail = new_node;
        }
    } else {
        Node<T>* current = head;
        for (size_t i = 0; i < idx - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (idx == m_size) {
            tail = new_node;
        }
    }
    m_size++;
	
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	if (idx >= m_size) {
        cout << "Error. Out of Bounds. " << endl;
		return 0;
    }
    Node<T>* current = head;
    for (size_t i = 0; i < idx; i++) {
        current = current->next;
    }
    return current->value;
	
}

template <typename T>
void LinkedList<T>::set(T v)
{
	return value[v];
}

template <typename T>
void LinkedList<T>::remove(size_t idx)
{
	Node<T>* deleter;
    if (idx == 0) {
        deleter = head;
        head = head->next;
        if (m_size == 1) {
            tail = nullptr;
        }
    } else {
        Node<T>* current = head;
        for (size_t i = 0; i < idx - 1; i++) {
            current = current->next;
        }
        deleter = current->next;
        current->next = deleter->next;
        if (idx == m_size - 1) {
            tail = current;
        }
    }
    delete deleter;
    m_size--;
	
}

template <typename T>
size_t LinkedList<T>::find(T v)
{
	Node<T>* current = head;
    for (size_t i = 0; i < m_size; i++) {
        if (current->value == v) {
            return i;
        }
        current = current->next;
    }
    return -1;
	
}

template <typename T>
size_t LinkedList<T>::size()
{
	return m_size;
	
}

template <typename T>
bool LinkedList<T>::empty()
{
	return m_size == 0;
	
}

#endif
