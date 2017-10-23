// header file lqueue.h
// linked queue

#ifndef LinkedQueue_
#define LinkedQueue_
#include <iostream>
#include "node.h"
#include "xcept.h"

using namespace std; 

template<class T>
class LinkedQueue {
// FIFO objects
	public:
		LinkedQueue() {front = rear = 0; count = 0;} // constructor
		~LinkedQueue(); // destructor
		bool IsEmpty() const
           {return ((front) ? false : true);}
		bool IsFull() const;
		T First() const; // return first element
		T Last() const; // return last element
		LinkedQueue<T>& Add(const T& x);
		LinkedQueue<T>& Delete(T& x);

		// IMPLEMENT THESE TWO METHODS
		int Size() const; // return current size of queue (number of nodes)
		void Print() const;	// print the queue in order

   private:
      Node<T> *front;  // pointer to first node
      Node<T> *rear;   // pointer to last node
      int count;
};

template<class T>
LinkedQueue<T>::~LinkedQueue()
{// Queue destructor.  Delete all nodes.
   Node<T> *next;
   while (front) {
      next = front->link; 
      delete front; 
      front = next;
      }
}

template<class T>
bool LinkedQueue<T>::IsFull() const
{// Is the queue full?
   Node<T> *p;
   try {p = new Node<T>;
        delete p;
        return false;}
   catch (NoMem) {return true;}
}

template<class T>
T LinkedQueue<T>::First() const
{// Return first element of queue.  Throw
 // OutOfBounds exception if the queue is empty.
   if (IsEmpty()) throw OutOfBounds();
   return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const
{// Return last element of queue.  Throw
 // OutOfBounds exception if the queue is empty.
   if (IsEmpty()) throw OutOfBounds();
   return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{// Add x to rear of queue.  Do not catch
 // possible NoMem exception thrown by new.

   // create node for new element
   Node<T> *p = new Node<T>;
   p->data = x;
   p->link = 0;

   // add new node to rear of queue
   if (front) rear->link = p;  // queue not empty
   else front = p;             // queue empty
   rear = p;
   count++;
   return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{// Delete first element and put it in x.  Throw
 // OutOfBounds exception if the queue is empty.

   if (IsEmpty()) throw OutOfBounds();

   // save element in first node
   x = front->data;

   // delete first node
   Node<T> *p = front;
   front = front->link;
   delete p;
   count--;
   return *this;
}

template<class T>
int LinkedQueue<T>::Size() const
{
//Your code here
  return count;
}

template<class T>
void LinkedQueue<T>::Print() const
{
//Your code here
  if (IsEmpty()) throw OutOfBounds();
  Node<T> *p = front;
  while(p != NULL)
  {
    cout << p->data << endl;
    p = p->link;
  }
}

#endif
