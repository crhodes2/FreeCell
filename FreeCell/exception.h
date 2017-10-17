/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         exception.h

========================================================*/




// exception.h : file for exception header,
// Includes code for specifying index smaller than lower bounds
// and index larger than upper bounds
//
#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <iostream>
#include <cstring>

using namespace std;

class Exception
{
public:
	// Default constructor
	Exception();

	// Constructor that accepts an error message as input
	Exception(char * msg);

	// Copy constructor
	Exception(const Exception & copy);

	// Destructor
	~Exception();

	// Overloaded operator= that copies the message from rhs
	Exception & operator=(const Exception & rhs);

	// Friend function stream insertion operator for an Exception (outputs error message)
	friend std::ostream & operator<<(std::ostream & stream, const Exception & except);

	// Retrieves the error message
	const char * getMessage();

	// Sets the error message
	void setMessage(char * msg);

private:
	char* m_msg; // The Exception error message (Default is nullptr).
};

#pragma region null terminator
  //________________________//
 //		NULL TERMINATOR	   //
//________________________//
/* 
	Adds an extra character in a null terminator. 
*/
const int NULL_TERMINATOR = 1;
#pragma endregion

#pragma region exception constructor
  //_____________________________//
 //     EXCEPTION CONSTRUCTOR   //
//_____________________________//
/*
	Empty constructor for the exception class definition.
	Nothing to be added there, but needed for compiling to work
*/
Exception::Exception()
{

}
#pragma endregion

#pragma region exception message
  //_____________________________//
 //     EXCEPTION CONSTRUCTOR   //
//_____________________________//
/*
	Used to create/set a specific message 
	for the exception error to be displayed.
*/
Exception::Exception(char * msg)
{
	setMessage(msg);
}
#pragma endregion

#pragma region exception copy constructor
  //__________________________________//
 //     EXCEPTION COPY CONSTRUCTOR   //
//__________________________________//
/*
	A copy constructor for the Exception class.
*/
Exception::Exception(const Exception & copy)
{
	*this = copy;
}
#pragma endregion

#pragma region exception destructor
  //____________________________//
 //     EXCEPTION DESTRUCTOR   //
//____________________________//

/*
	Destructor for the exception class definition.
	Used to delete any data stored in the exception
	object and free up memory
*/
Exception::~Exception()
{
}
#pragma endregion

#pragma region exception operator=
  //___________________________//
 //     EXCEPTION OPERATOR=   //
//___________________________//
/*
	Assign Exception's message data to this object.
	rhs is the Exception containing the data needed to copy.
	and it'll copy the message from rhs to this.
*/
Exception & Exception::operator=(const Exception & rhs)
{
	if (&rhs != this)
	{
		setMessage(rhs.m_msg);
	}

	return *this;
}
#pragma endregion 

#pragma region exception operator <<
  //____________________________//
 //     EXCEPTION OPERATOR<<   //
//____________________________//

/*
Purpose:
This overloaded stream insertion operator outputs the Exception's error message, provided it
exists.
*/

std::ostream & operator<<(std::ostream & stream, const Exception & except)
{
	if (except.m_msg != nullptr)
	{
		stream << except.m_msg;
	}
	return stream;
}
#pragma endregion

#pragma region set message
  //___________________//
 //     SET MESSAGE   //
//___________________//
/*
	Set the message
*/
void Exception::setMessage(char * msg)
{

	// if we have a current message, delete it
	if (m_msg != nullptr)
	{
		m_msg = nullptr;
	}

	// if our passed in message is not empty, copy it
	if (msg != nullptr)
	{
		// allocate memory for the message
		m_msg = new char[strlen(msg) + NULL_TERMINATOR];
		// if memory was successfully allocated, copy the string
		if (m_msg != nullptr)
		{
			strcpy_s(m_msg, strlen(m_msg), msg);
		}
	}
}
#pragma endregion 

#pragma region get message
  //___________________//
 //     GET MESSAGE   //
//___________________//
/*
	Get the error message by returning a constant pointer 
	to the Exception message.
*/
const char * Exception::getMessage()
{
	return m_msg;
}
#pragma endregion



#endif