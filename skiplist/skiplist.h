#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <iostream>
#include <iomanip>

template<class E, class K>
class skipNode{
public:
    E key;
    K data;
    skipNode<E, K> **link;

public:
    skipNode(int size = 100)
    {
        link = new skipNode<E, K> *[size];
        if(link == nullptr)
        {
            std::cerr << "Failed to allocate memory!" << std::endl;
            exit(1);
        }
    }

    ~skipNode(){ delete []link; }
};

template<class E, class K>
class skipList{
public:
    skipList(int maxLevel);
    ~skipList();
    void insertNode(E key, K data);
    void deleteNode(E key);
    bool findKey(E key);
    void display();
private:
    int randomLevel();

private:
    int MAX_LEVEL;
    skipNode<E,K> *head;
    skipNode<E,K> *tail;
};

template<class E, class K>
skipList<E,K>::skipList(int maxLevel)
{
    MAX_LEVEL = maxLevel;
    head = new skipNode<E,K>;
    tail = new skipNode<E,K>;

    head->link = new skipNode<E,K> *[MAX_LEVEL];
    for(int i=0; i<MAX_LEVEL; i++)
        head->link[i] = tail;
}

template<class E, class K>
skipList<E,K>::~skipList()
{
    skipNode<E,K> *current = nullptr;
    while(head->link[0] != tail)
    {
        current = head->link[0];
        head->link[0] = current->link[0];
        delete current->link;
        delete current;
    }

    delete head->link;
    delete head;
    delete tail;
}

template<class E, class K>
void skipList<E,K>::insertNode(E key, K data)
{
    skipNode<E,K> *update[MAX_LEVEL];
    skipNode<E,K> *current = head;

    for(int i = MAX_LEVEL-1; i>=0; i--)
    {
        if(current->link[i] == tail || current->link[i]->key > key)
            update[i] = current;
        else
        {
            while(current->link[i] != tail && current->link[i]->key < key)
                current = current->link[i];
            if(current->link[i] != tail && current->link[i]->key == key)
            {
                current->link[i]->data = data;
                return;
            }
            update[i] = current;
        }
    }

    int level = randomLevel();
    skipNode<E,K> *tmp = new skipNode<E,K>;
    tmp->key = key;
    tmp->data = data;
    tmp->link = new skipNode<E,K> *[level+1];

    for(int i=0; i<=level; i++)
    {
        tmp->link[i] = update[i]->link[i];
        update[i]->link[i] = tmp;
    }
}

template<class E, class K>
void skipList<E,K>::deleteNode(E key)
{
    skipNode<E,K> *update[MAX_LEVEL];
    skipNode<E,K> *current = head;

    for(int i=MAX_LEVEL-1; i>=0; i--)
    {
        if(current->link[i] == tail || current->link[i]->key > key)
            update[i] = nullptr;
        else
        {
            while(current->link[i] != tail && current->link[i]->key < key)
                current = current->link[i];
            if(current->link[i] != tail && current->link[i]->key == key)
                update[i] = current;
            else
                update[i] = nullptr;
        }
    }

    skipNode<E,K> *tmp = nullptr;

    for(int i=0; i<MAX_LEVEL; i++)
    {
        if(update[i])
        {
            tmp = update[i]->link[i];
            update[i]->link[i] = tmp->link[i];
        }
    }
}

template<class E, class K>
bool skipList<E,K>::findKey(E key)
{
    skipNode<E,K> *current = head;

    for(int i=MAX_LEVEL-1; i>=0; i--)
    {
        if(current->link[i] == tail || current->link[i]->key > key)
            continue;
        else
        {
            while(current->link[i] != tail && current->link[i]->key < key)
                current = current->link[i];
            if(current->link[i] != tail && current->link[i]->key == key)
                return true;
        }
    }
    return false;
}

template<class E, class K>
int skipList<E,K>::randomLevel()
{
    int level = 0;
    while(rand()%2 && level < MAX_LEVEL - 1)    level++;
    return level;
}

template<class E, class K>
void skipList<E,K>::display()
{
    for(int i=MAX_LEVEL-1; i>=0; i--)
    {
        skipNode<E,K> *current = head->link[i];
        skipNode<E,K> *bottom = head->link[0];

        std::cout << "Layer " << i << ":";
        while(bottom != tail)
        {
            if(current == bottom)
            {
                std::cout << std::setw(7) << current->key << ":" << current->data;
                current = current->link[i];
            }
            else
                std::cout << std::setw(7) << "   ";
            bottom = bottom->link[0];
        }
        std::cout << std::endl;
    }
}

#endif