#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         stackarray.h

========================================================*/

#include "array.h"

template <typename T>
class StackArray
{
private:
	Array<T> m_stack;
	int m_top;		
	
public:
	//   CONSTRUCTOR
	StackArray();

	//1-Arg Overloaded Ctor
	StackArray(int size);

	//   COPY CONSTRUCTOR
	StackArray(const StackArray<T> & copy);

	//   DESTRUCTOR
	~StackArray();

	//   OPERATOR=
	StackArray<T> & operator=(const StackArray<T> & rhs);

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

	//Returns true if the stack is full
	bool isFull();


};


template<typename T>
StackArray<T>::StackArray()	 
{
	m_top = -1;
}


template<typename T>
StackArray<T>::StackArray(int size) : m_top(-1)		//-1 indicates no items on stack since indicies cannot be < 0 
{
	if (size < 0)
	{
		//Cannot have negative sized stack
		throw Exception("ERROR: Stack of negative size not allowed.");
	}

	//Give stack desired size
	m_stack.setLength(size);
}


template<typename T>
StackArray<T>::StackArray(const StackArray<T> & copy) : m_top(-1)	//-1 indicates no items on stack since elements cannot be < 0 
{
	*this = copy;	  
}


template<typename T>
StackArray<T>::~StackArray()
{
	//Reset to default value
	m_top = -1;
}

template<typename T>
StackArray<T>& StackArray<T>::operator=(const StackArray<T>& rhs)
{
	//Check for self assignment
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;	//Use Array's assignment operator
		m_top = rhs.m_top;
	}

	return *this;
}


template<typename T>
void StackArray<T>::Push(const T & data)
{
	//Check if stack is already full
	if (isFull())
		throw Exception("ERROR: Stack overflow detected.");

	m_top++;	//Increment index of top of stack to next index in array
	m_stack[m_top] = data;		//Place item on top of stack
}

template<typename T>
T StackArray<T>::Pop()
{
	//Check if stack is already empty
	if (isEmpty())
		throw Exception("ERROR: Stack underflow detected.");

	//Return value of top of stack & then decrement index of top of stack to previous index in array
	return m_stack[m_top--];
}


template<typename T>
T StackArray<T>::Peek()
{
	//Check if stack is already empty
	if (isEmpty())
		throw Exception("ERROR: Cannot access top of empty stack.");

	//Return value of top of stack
	return m_stack[m_top];
}


template<typename T>
int StackArray<T>::Size()
{
	//Return index value plus one to reference actual number of items on stack
	return (m_top + 1);
}


template<typename T>
bool StackArray<T>::isEmpty()
{
	//Returns true if index of top element of stack is less than first index of array
	return (m_top == -1);
}


template<typename T>
bool StackArray<T>::isFull()
{
	//Returns true if index of top element of stack is at the last index of array
	return (m_top == (m_stack.getLength() - 1));
}

#endif