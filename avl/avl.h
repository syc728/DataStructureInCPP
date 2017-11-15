#ifndef __AVL_H__
#define __AVL_H__

#include <iostream>

using namespace std;

template<class T>
class AVL
{
private:
    T data;
    int height;
    AVL<T>* left;
    AVL<T>* right;

public:
	AVL(){}
    AVL(T data, AVL* left, AVL* right, int height=0):data(data), left(left),right(right),height(height){}
    ~AVL(){}
    
    int getHeight(AVL<T>* node)
    {
        return (node==NULL) ? -1:node->height;
    }

    void preOrder(AVL<T>* node)
    {
        if(node)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(AVL<T>* node)
    {
        if(node)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    AVL<T>* RR(AVL<T>* node)
    {
        AVL<T>* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;

        node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
        tmp->height = max(getHeight(tmp->left), node->height) + 1;
        return tmp;
    }

    AVL<T>* LL(AVL<T>* node)
    {
        AVL<T>* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;

        node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
        tmp->height = max(getHeight(tmp->right), node->height) + 1;
        return tmp;
    }

    AVL<T>* LR(AVL<T>* node)
    {
        node->left = LL(node->left);
        return RR(node);
    }

    AVL<T>* RL(AVL<T>* node)
    {
        node->right = RR(node->right);
        return LL(node);
    }

    AVL<T>* Insert(AVL<T>* node, T data)
    {
        if(node == NULL)
            return new AVL<T>(data, NULL, NULL);

        if(data < node->data)
            node->left = Insert(node->left, data);
        else
            node->right = Insert(node->right, data);

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        
        if(getHeight(node->left) - getHeight(node->right) == 2)
        {
            if(data < node->left->data) 
                node = RR(node);
            else
                node = LR(node);
        }
        else if(getHeight(node->right) - getHeight(node->left) == 2)
        {
            if(data >= node->right->data)
                node = LL(node);
            else
                node = RL(node);
        }

        return node;
    }

    AVL<T>* Delete(AVL<T>* node, T data)
    {
        if(node == NULL)
            return NULL;
        
        if(data == node->data)
        {
            if(node->right == NULL)
            {
                AVL<T>* tmp = node;
                node = node->left;
                delete tmp;
                return node;
            }
            else
            {
                AVL<T>* tmp = node->right;
                while(tmp->left)
                    tmp = tmp->left;
                node->data = tmp->data;
                node->right = Delete(node->right, tmp->data);
            }
        }
        else if(data < node->data)
            node->left = Delete(node->left, data);
        else
            node->right = Delete(node->right, data);

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        if(getHeight(node->left)-getHeight(node->right) == 2)
        {
            if(getHeight(node->left->left) >= getHeight(node->left->right))
                node = RR(node);
            else
                node = LR(node);
        }
        else if(getHeight(node->right) - getHeight(node->left) == 2)
        {
            if(getHeight(node->right->right) >= getHeight(node->right->left))
                node = LL(node);
            else
                node = RL(node);
        }
        return node;
    }
};

#endif

