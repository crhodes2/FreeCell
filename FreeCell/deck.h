#ifndef DECK_H
#define DECK_H

/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         deck.h

========================================================*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#include "card.h"

// TOTAL NUMBER OF DECK OF CARDS
const int NUM_CARDS_DECK = 52;

   //________________//
  //	  DECK      //
 //________________//

class Deck
{
private:
	//TOTAL NUMBER OF CARDS
	Card m_deck[NUM_CARDS_DECK];
	
	//CURRENT CARD
	int m_current_card;
	
public:
	//CONSTRUCTOR
	Deck();

	//COPY CONSTRUCTOR
	Deck(const Deck & copy);

	//DESTRUCTOR
	~Deck();

	//OPERATOR=
	Deck & operator=(const Deck & rhs);

	//DEAL DECK
	Card Deal();

	//SHUFFLE DECK
	void Shuffle();

};

//CONSTRUCTOR
Deck::Deck() : m_current_card(0)
{
	int count = 0;

	//Initialize each Card to different rank/suit combination
	for (int row = 1; row <= NUM_RANKS; row++)
	{
		for (int column = 0; column < NUM_SUITS; column++)
		{
			m_deck[count].SetRank(static_cast<Rank>(row));
			m_deck[count].SetSuit(static_cast<Suit>(column));
			count++;
		}
	}

	//For shuffling purposes.
	srand((unsigned int)time(NULL));
}

//COPY CONSTRUCTOR
Deck::Deck(const Deck & copy) : m_current_card(0)
{
	*this = copy;
}

// DESTRUCTOR
Deck::~Deck()
{
	m_current_card = 0;
}

// OPERATOR =
Deck & Deck::operator=(const Deck & rhs)
{
	//Check for self-assignment
	if (this != &rhs)
	{
		m_current_card = rhs.m_current_card;
		
		for (int i = 0; i < NUM_CARDS_DECK; i++)
		{
			m_deck[i] = rhs.m_deck[i];	//Use Card's assignment operator
		}
	}

	return *this;
}

// SHUFFLE
void Deck::Shuffle()
{
	Rank rank = ACE;		//To hold value of random rank
	Suit suit = SPADE;		//To hold value of random suit
	int numCards = 0;		//To count number of randomized cards
	bool sameCard = false;	//Flags whether rank and suit combo already exists

	//While not all cards have been assigned a rank and suit combo
	while (numCards < NUM_CARDS_DECK)
	{
		sameCard = false;	

		int rankInt = (rand() % NUM_RANKS) + 1;	//Add one, since Rank skips zero and starts at 1
		rank = static_cast<Rank>(rankInt);		//Randomly generate a rank
		suit = static_cast<Suit>(rand() % NUM_SUITS);	//Randomly generate a suit

		//For all cards that have been assigned a rank and suit combo
		for (int i = 0; i < numCards && sameCard == false; i++)
		{
			//Check if the random rank and suit combo already exists
			if (m_deck[i].GetRank() == rank && m_deck[i].GetSuit() == suit)
			{
				sameCard = true;
			}
		}

		//If new rank and suit combo
		if (sameCard == false)
		{
			//Assign next card in deck that rank and suit combo
			m_deck[numCards].SetRank(rank);
			m_deck[numCards].SetSuit(suit);
			numCards++;
		}
	}

	//Reset current card to first card in deck
	m_current_card = 0;
}


Card Deck::Deal()
{
	return m_deck[m_current_card++];
}


#endif //DECK_H