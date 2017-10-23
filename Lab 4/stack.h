// file stack.h
// formula-based stack

#ifndef Stack_
#define Stack_


template<class T>
class Stack {
// LIFO objects
   public:
      Stack(int MaxStackSize = 10);
      ~Stack() {delete [] stack;}
      bool IsEmpty() const {return top == -1;}
      bool IsFull() const {return top == MaxTop;}
      T Top() const;
      Stack<T>& Add(const T& x);
      Stack<T>& Delete(T& x);
   private:
      int top;    // current top of stack
      int MaxTop; // max value for top
      T *stack;   // element array
};

template<class T>
Stack<T>::Stack(int MaxStackSize)
{// Stack constructor.
   MaxTop = MaxStackSize - 1;
   stack = new T[MaxStackSize];
   top = -1;
}

template<class T>
T Stack<T>::Top() const
{// Return top element.
   if (IsEmpty()) throw "OutOfBounds Exception!"; // Top fails
   else return stack[top];
}

template<class T>
Stack<T>& Stack<T>::Add(const T& x)
{// Add x to stack.
   if (IsFull()) throw "NoMemory Exception!"; // add fails
   stack[++top] = x;
   return *this;
}

template<class T>
Stack<T>& Stack<T>::Delete(T& x)
{// Delete top element and put in x.
   if (IsEmpty()) throw "OutOfBounds Exception!"; // delete fails
   x = stack[top--];
   return *this;
}

#endif
