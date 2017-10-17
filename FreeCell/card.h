#ifndef CARD_H
#define CARD_H

/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         card.h

========================================================*/
#pragma once

#include <iostream>

using namespace std;

//===========================================================================//
//						THE ATTRIBUTES OF A CARD							//
/*		here is listed the attribute of a card for the free cell game	   */

enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, 
			EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum Suit { SPADE, HEART, CLUB, DIAMOND };

const int NUM_RANKS = 13;
const int NUM_SUITS = 4;

//======================================================================//
class Card
{

private:
	Rank m_rank;	
	Suit m_suit;
	
public:
	//CONSTRUCTOR
	Card();

	//OVERLOADED CONSTRUCTOR
	Card(Rank rank, Suit suit);

	//COPY CONSTRUCTOR
	Card(const Card & copy);

	//DESTRUCTOR
	~Card();

	//OPERATOR=
	Card & operator=(const Card & rhs);

	//OPERATOR!=
	bool operator!=(const Card & rhs);

	//GET-SET
	void SetRank(Rank rank);
	void SetSuit(Suit suit);
	Rank GetRank() const;
	Suit GetSuit() const;
};


Card::Card() : m_rank(ACE), m_suit(SPADE)
{}


Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{}


Card::Card(const Card & copy) : m_rank(ACE), m_suit(SPADE)
{
	*this = copy;	
}


Card::~Card()
{
	//Reset to default values
	m_rank = ACE;
	m_suit = SPADE;
}


Card & Card::operator=(const Card & rhs)
{
	//Check for self-assignment
	if (this != &rhs)
	{
		m_rank = rhs.m_rank;
		m_suit = rhs.m_suit;
	}

	return *this;
}


bool Card::operator!=(const Card & rhs)
{
	bool notEqual = false;	

	if (m_rank != rhs.m_rank || m_suit != rhs.m_suit)
		notEqual = true;

	return notEqual;
}


void Card::SetRank(Rank rank)
{
	m_rank = rank;
}


void Card::SetSuit(Suit suit)
{
	m_suit = suit;
}


Rank Card::GetRank() const
{
	return m_rank;
}


Suit Card::GetSuit() const
{
	return m_suit;
}




#endif