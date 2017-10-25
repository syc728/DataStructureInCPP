//Singly Linked List

#include <iostream>
#include "ChainNode.h"

using namespace std;

template<class T> class Chain
{
	public:
		Chain() { first = 0; }
		~Chain();
		bool IsEmpty() const { return first == 0; }
		int Length() const;
		bool Find(int k, T& x) const;
		int Search(const T& x) const;
		Chain<T>& Delete(int k, T& x);
		Chain<T>& Insert(int k, const T& x);
		Chain<T>& MakeCircle(int k);
		bool DetectCircle1();
		bool DetectCircle2();
		void Output(ostream& out);
	
	private:
		ChainNode<T>* first; //Pointer to first node
};

/*######################################################
# Destructor
######################################################*/
template<class T> Chain<T>::~Chain()
{
	ChainNode<T>* next;
	while (first)
	{
		next = first -> link;
		delete first;
		first = next;
	}
};

/*######################################################
# Return the length of the list
######################################################*/
template<class T> int Chain<T>::Length() const
{
	ChainNode<T>* current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current -> link;
	}
	return len;
};

/*######################################################
# Find
######################################################*/
template<class T> bool Chain<T>::Find(int k, T& x) const
{
	if (k < 1) 
		return false;
	
	ChainNode<T>* current = first;
	int index = 1; //Index of current
	
	while (index < k && current) {
		current = current -> link;
		index++;
	}
	
	if (current) {
		x = current -> data;
		return true;
		
	}
	
	return false; //No k'th element
};

/*######################################################
# Search
######################################################*/
template<class T> int Chain<T>::Search(const T& x) const
{
	ChainNode<T> *current = first;
	int index = 1;  //Index of current
	while (current && current->data != x) {
		current = current->link;
		index++;
	}
	if (current)
		return index;
	
	return 0;
};

/*######################################################
# Set x to the k'th element and delete it
######################################################*/
template<class T> Chain<T>& Chain<T>::Delete(int k, T& x)
{
	if (k < 1 || !first)
		throw "OutOfBounds Exception!"; //No k'th element
	
	ChainNode<T>* p = first;//p will eventually point to k'th node

	//Move p to k'th & remove from chain
	if (k == 1) //Only one item in the list
		first = first->link; // remove
	else 
	{
		ChainNode<T> *q = first; //Use q to get to k-1
		
		for (int index = 1; index < k - 1 && q; index++) //k - 1
			q = q->link;
		
		if (!q || !q->link) 
			throw "OutOfBounds Exception!"; //No k'th
		p = q->link; //k'th
		q -> link = p -> link;//Remove from chain
	}
	
	//Save k'th element and free node p
	x = p -> data;
	delete p;

	return *this;
};

/*######################################################
# Insert x after index k + 1
######################################################*/
template<class T> Chain<T>& Chain<T>::Insert(int k, const T& x)
{
	if (k < 0) throw "OutOfBounds Exception!";
	
	ChainNode<T> *p = first; //p will eventually point to k'th node
	
	for (int index = 1; index < k && p; index++)  
		p = p->link;//Move p to k'th
	
	if (k > 0 && !p) throw "OutOfBounds Exception!"; //No k'th

	//Insert
	ChainNode<T> *y = new ChainNode<T>;
	y -> data = x;
	if (k) {
		//Insert after p
		y->link = p->link;
		p->link = y;
	}
	else {
		//Insert as first element
		y -> link = first;
		first = y;
	}
	return *this;
};

template<class T> Chain<T>& Chain<T>::MakeCircle(int k)
{
	if(k < 0 || k >= Length()) throw "OutOfBounds Exception";
	ChainNode<T> *current = first, *insertPos = first;
	for(current; current->link; current=current->link);
	for(int i=0;i<k;i++)	insertPos = insertPos->link;

	current->link = insertPos->link;

	return *this;
}

template<class T> bool Chain<T>::DetectCircle1(ChainNode)
{
	ChainNode<T> *s = first, *f = first;
	while(s && f && f->link)
	{
		s = s->link;
		f= f->link->link;

		if(s == f)
			return true;
	}
	return false;
}

/*######################################################
# Output
######################################################*/
template<class T> void Chain<T>::Output(ostream& out)
{
	ChainNode<T> *current;
	
	for (current = first; current; current = current->link)
		out << current->data << "  ";
};

/*######################################################
# Override (<<)
######################################################*/
template <class T> ostream& operator<<(ostream& out, const Chain<T>& x)
{
	 x.Output(out); 
	 return out;
};






