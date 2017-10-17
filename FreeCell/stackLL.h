#ifndef STACK_LL_H
#define STACK_LL_H

/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         stacklinkedlist.h

========================================================*/


#include "linkedList.h"
#include "exception.h"

template <typename T>
class StackLL
{
private:
	LinkedList<T> m_stack;	
	int m_size;	
	
public:
	//   CONSTRUCTOR
	StackLL();

	//   COPY CONSTRUCTOR
	StackLL(const StackLL<T> & copy);

	//   DESTRUCTOR
	~StackLL();

	//   OPERATOR=
	StackLL<T> & operator=(const StackLL<T> & rhs);

	//Pushes its parameter onto the top of the stack
	void Push(const T & data);

	//Removes and returns the data from the top of the stack
	T Pop();

	//Returns the element on the top of the stack but does not remove it
	T Peek();

	//Returns the number of items currently on the stack
	int Size();

	//Returns true if the stack is empty
	bool isEmpty();

	
};



template<typename T>
StackLL<T>::StackLL() : m_size(0)
{}



template<typename T>
StackLL<T>::StackLL(const StackLL<T>& copy)
{
	m_size = 0;
	*this = copy;
}



template<typename T>
StackLL<T>::~StackLL()
{
	m_size = 0;
}



template<typename T>
StackLL<T>& StackLL<T>::operator=(const StackLL<T>& rhs)
{
	if (this != &rhs)
		m_stack = rhs.m_stack;

	return *this;
}



template<typename T>
void StackLL<T>::Push(const T & data)
{
	m_stack.Prepend(data);	
	m_size++;	
}



template<typename T>
T StackLL<T>::Pop()
{
	
	if (isEmpty())
		throw Exception("ERROR: Stack underflow detected.");

	T top = m_stack.First();
	m_stack.Extract(top);	
	m_size--;	

	return top;		
}



template<typename T>
T StackLL<T>::Peek()
{
	if (isEmpty())
		throw Exception("ERROR: Cannot access top of an empty stack.");

	return (m_stack.First());		
}



template<typename T>
int StackLL<T>::Size()
{
	return m_size;
}



template<typename T>
bool StackLL<T>::isEmpty()
{
	return (m_stack.isEmpty());		
}

#endif //STACK_LL_H