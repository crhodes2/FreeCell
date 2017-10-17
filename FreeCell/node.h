#ifndef NODE_H
#define NODE_H

/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         node.h

========================================================*/


   //_______________//
  //      NODE     //
 //_______________//	
template <typename T>
class Node
{
private:
	//Data Members
	T m_data;				
	Node<T> * m_next;		
	Node<T> * m_previous;	

public:
	
	//LinkedList is a friend class to Node
	template <typename T>
	friend class LinkedList;

	//   CONSTRUCTOR
	Node();

	//1-Arg Overloaded Ctor
	Node(T data);

	//   COPY CONSTRUCTOR
	Node(const Node<T> & copy);

	//   DESTRUCTOR
	~Node();

	//   OPERATOR=
	Node<T> & operator=(const Node<T> & rhs);


};

template<typename T>
Node<T>::Node() : m_next(nullptr), m_previous(nullptr)
{}


template<typename T>
Node<T>::Node(T data) : m_data(data), m_next(nullptr), m_previous(nullptr)
{}


template<typename T>
Node<T>::Node(const Node & copy) : m_data(copy.m_data), m_next(nullptr), m_previous(nullptr)
{
	*this = copy;	//Use assignment operator
}


template<typename T>
Node<T>::~Node()
{
	//Reset to initial default values
	m_next = nullptr;
	m_previous = nullptr;
}


template<typename T>
Node<T> & Node<T>::operator=(const Node<T> & rhs)
{
	//Check for self-assignment
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
		m_previous = rhs.m_previous;
	}

	return *this;
}

#endif //NODE_H