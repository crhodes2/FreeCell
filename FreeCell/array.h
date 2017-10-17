#ifndef ARRAY_H
#define ARRAY_H
/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         array.h

========================================================*/

#include "exception.h"

  //________________//
 //		ARRAY	   //
//________________//
template <typename T>
class Array
{
private:
	T * m_array;		
	int m_length;		
	int m_start_index;	
	
public:
	//CONSTRUCTOR
	Array();

	//CONSTRUCTOR
	Array(int length, int start_index = 0);

	//COPY CONSTRUCTOR
	Array(const Array<T> & copy);

	//DESTRUCTOR
	~Array();

	//OPERATOR=
	Array<T> & operator=(const Array<T> & rhs);

	//OPERATOR[]
	T & operator[](int index) const;

	//GET-SET
	int getStartIndex() const;
	int getLength() const;
	
	void setStartIndex(int start_index);
	void setLength(int length);


};


template <typename T>
Array<T>::Array() : m_array(nullptr), m_length(0),
m_start_index(0)
{}


template <typename T>
Array<T>::Array(int length, int start_index) : m_array(nullptr),
m_length(length), m_start_index(start_index)
{
	//If length is negative
	if (m_length < 0)
	{
		//Cannot have negative length
		m_length = 0;
		throw Exception("ERROR: Array of negative length not allowed.");
	}
	//Else if length is zero
	else if (m_length == 0)
	{
		m_array = nullptr;
	}
	//Else array is given desired length
	else
	{
		m_array = new T[m_length];
	}
}


template <typename T>
Array<T>::Array(const Array<T> & copy) : m_array(nullptr),
m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	*this = copy;	//Use assignment operator
}


template <typename T>
Array<T>::~Array()
{
	delete[] m_array;

	//Reset to default values
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}


template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	//If object addresses are not the same
	if (this != &rhs)
	{
		delete[] m_array;
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;

		//If lenth is zero
		if (rhs.m_length == 0)
		{
			m_array = nullptr;
		}
		//Else lhs array is given length of rhs array
		else
		{
			m_array = new T[rhs.m_length];

			for (int i = 0; i < m_length; i++)
				m_array[i] = rhs.m_array[i];
		}
	}

	return *this;
}


template <typename T>
T & Array<T>::operator[](int index) const
{
	//If accessing element smaller than first element
	if (index < m_start_index)
	{
		//Out of bounds of array
		throw Exception("ERROR: Index smaller than lower bound.");
	}
	//Else if accessing element larger than last element
	else if (index >= m_length + m_start_index)
	{
		//Out of bound of array
		throw Exception("ERROR: Index larger than upper bound.");
	}
	//Else return the real index of array
	else
		return m_array[index - m_start_index];
}


template <typename T>
int Array<T>::getStartIndex() const
{
	return m_start_index;
}


template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}


template <typename T>
int Array<T>::getLength() const
{
	return m_length;
}


template <typename T>
void Array<T>::setLength(int length)
{
	//If length is greater than zero
	if (length > 0)
	{
		T * newArray = new T[length];	//Give new array the new length
		int smallestLength = 0;			//Will store length of shortest array

										//If original array has shorter length
		if (m_length < length)
			smallestLength = m_length;

		//Else new array will have shorter length
		else
			smallestLength = length;

		//Assign contents of original array to new array
		for (int i = 0; i < smallestLength; i++)
			newArray[i] = m_array[i];

		delete[] m_array;
		m_array = newArray;
		m_length = length;
	}
	//Else length is zero
	else if (length == 0)
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = length;
	}
	//Else length cannot be negative
	else
		throw Exception("ERROR: Array of negative length not allowed.");
}





#endif