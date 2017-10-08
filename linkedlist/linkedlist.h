#ifndef NODE_H
#define NODE_H

#include "node.h"
template <class T>
class LinkedList
{
private:
    Node<T>* head;
public:
    LinkedList():head(new Node<T>){};
    ~LinkedList(){ clear(); delete head; }
public:
    int len();
    bool insert(T item, int i);
    T remove(int i);
    T get(int i);
    bool find(T item);
    void clear();
    void output();
};

template <class T>
int LinkedList<T>::len()
{
    int cnt = 0;
    Node<T>* tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
        ++cnt;
    }
    return cnt;
}

template <class T>
bool LinkedList<T>::insert(T item, int i)
{
    if(i <= 0)
        return false;
    
    Node<T>* newNode = new Node<T>(item);
    Node<T>* tmp = head;

    for(int index=1; index<i; ++index)
    {
        if(tmp->next == nullptr)
            return false;
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
    return true;
}

template <class T>
T LinkedList<T>::remove(int i)
{
    if(i <= 0)
        return false;
    
    Node<T>* tmp = head;
    for(int index=1; index<i; ++index)
    {
        if(tmp->next == nullptr)
            return false;
        tmp = tmp->next;
    }

    Node<T>* delNode = tmp->next;
    tmp->next = delNode->next;
    T delData = delNode->data;
    delete delNode;
    return delData;
}

template <class T>
T LinkedList<T>::get(int i)
{
    if(i <= 0)
        return false;
    Node<T>* tmp = head->next;
    for(int index=1; index<i; ++index)
    {
        if(tmp->next == nullptr)
            return false;
        tmp = tmp->next;
    }

    return tmp->data;
}

template <class T>
bool LinkedList<T>::find(T item)
{
    Node<T>* tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
        if(tmp->data == item)
        {
            return true;
        }
    }
    return false;
}

#ifndef IOSTREAM_H
#define IOSTREAM_H

#include <iostream>
template <class T>
void LinkedList<T>::output()
{
    Node<T>* tmp = head->next;
    std::cout << "head";
    while(tmp)
    {
        std::cout << "--->" << tmp->data;
        tmp = tmp->next; 
    }
    std::cout << "--->NULL" << std::endl;
    delete tmp;
}

#endif

template <class T>
void LinkedList<T>::clear()
{
    Node<T>* tmp = nullptr;
    while(head->next)
    {
        tmp = head->next;
        head->next = tmp->next;
        delete tmp;
    }
}

#endif