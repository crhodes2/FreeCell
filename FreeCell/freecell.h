#ifndef FREECELL_H
#define FREECELL_H


/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         freecell.h

========================================================*/

#include <iostream>
#include "board.h"

using namespace std;


   //____________________//
  //	  FREECELL      //
 //____________________//
class freeCell
{

	private:
		Board m_gameBoard;
		bool m_endGame;

	public:
		//   CONSTRUCTOR
		freeCell();
		
		//   COPY CONSTRUCTOR
		freeCell(const freeCell & copy);

		//   DESTRUCTOR
		~freeCell();

		//   OPERATOR=
		freeCell & operator=(const freeCell & rhs);

		//	 PLAY GAME
		void RunGame();

		//	RUNS GAMEPLAY
		void GameLoop();

		void ChooseAction();

		void playerChoice(int choice);

		// move card from play area to same
		void MovePlayToPlay();

		// move card from play area to free area
		void MovePlayToFree();

		// move card from play area to home area
		void MovePlayToHome();
		
		// move card from freecell area to play area
		void MoveFreeToPlay();
		
		// move card from freecell area to home area
		void MoveFreeToHome();


};

freeCell::freeCell() : m_endGame(false)
{}


freeCell::freeCell(const freeCell & copy) : m_endGame(false)
{
	*this = copy;
}


freeCell::~freeCell()
{
	m_endGame = false;
}


freeCell & freeCell::operator=(const freeCell & rhs)
{

	if (this != &rhs)
	{
		m_gameBoard = rhs.m_gameBoard;
		m_endGame = rhs.m_endGame;
	}

	return *this;
}


void freeCell::RunGame()
{
	char playAgain = '\0';

	do
	{
		// the game
		system("cls");

		cout << "\t\tWelcome to FreeCell!\n\n";

		GameLoop();

		cout << "\nPlay again? (y/n): ";
		cin >> playAgain;

	}
	while (playAgain == 'y');

	cout << "\nThanks for playing!\n\n";
}


void freeCell::GameLoop()
{
	m_gameBoard.DisplayBoard();

	while (m_endGame != true)
	{
		ChooseAction();
	}

	m_gameBoard.ResetNewBoard();
	m_endGame = false;
}


void freeCell::ChooseAction()
{
	int choice = 0;		

	cout << "\n\nPlease select an action for moving the cards:\n"
		<< "1) Move from play area to play area\n"
		<< "2) Move from play area to free cell area\n"
		<< "3) Move from play area to home cell area\n"
		<< "4) Move from free cell area to play area\n"
		<< "5) Move from free cell area to home area\n"
		<< "6) Quit this game\n";
	cout << "Your choice: ";
	cin >> choice;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	

	while (choice < 1 || choice > 6)
	{
		cout << "\nChoice must be a number between 1 and 6. Please try again: ";
		cin >> choice;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	
	}

	playerChoice(choice);
}


void freeCell::playerChoice(int choice)
{

	switch (choice)
	{
	case 1:
		MovePlayToPlay();
		break;
	case 2:
		MovePlayToFree();
		break;
	case 3:
		MovePlayToHome();
		break;
	case 4:
		MoveFreeToPlay();
		break;
	case 5:
		MoveFreeToHome();
		break;
	case 6:
		m_endGame = true;
		break;
	}
}


void freeCell::MovePlayToPlay()
{
	
	int column1 = -1;	
	int column2 = -1;	
	int numCards = 0;	


	m_gameBoard.DisplayBoard();


	cout << "\nPlease enter which column (0-7) to move the card(s) FROM: ";
	cin >> column1;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	

	while (column1 < 0 || column1 > 7)
	{
		cout << "\nChoice must be a number between 0 and 7. Please try again: ";
		cin >> column1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	
	}

	cout << "\nPlease enter which column (0-7) to move the card(s) TO: ";
	cin >> column2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	

	while (column2 < 0 || column2 > 7 || column2 == column1)
	{
		cout << "\nChoice must be a number between 0 and 7, different from the first column value. Please try again: ";
		cin >> column2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	
	}

	
	cout << "\nPlease enter the number of cards to move: ";
	cin >> numCards;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	


	if (numCards <= 0)
	{
		m_gameBoard.DisplayBoard();
		cout << "\nERROR: Cannot move zero cards.";
	}
	else
	{
		try
		{
		
			m_gameBoard.MovePlayToPlay(column1, column2, numCards);
			m_gameBoard.DisplayBoard();
		}
		catch (Exception & ex)
		{
		
			m_gameBoard.DisplayBoard();
			cout << "\n" << ex;
		}
	}
}


void freeCell::MovePlayToFree()
{
	//-1 protects from specifying a cell if a char gets stored into int
	int column = -1;	//User specified column to move card from
	int index = -1;		//User specified free cell index to move card to

	//Display current game board and key symbols on board
	m_gameBoard.DisplayBoard();

	//Prompt for which column to move from
	cout << "\nPlease enter which column (0-7) to move the card FROM: ";
	cin >> column;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (column < 0 || column > 7)
	{
		cout << "\nChoice must be a number between 0 and 7. Please try again: ";
		cin >> column;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	//Prompt for which free cell to move card to
	cout << "\nPlease enter which free cell (0-3) to move the card TO: ";
	cin >> index;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (index < 0 || index > 3)
	{
		cout << "\nChoice must be a number between 0 and 3. Please try again: ";
		cin >> index;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	try
	{
		//Move cards from a column to a free cell, and re-display board
		m_gameBoard.MovePlayToFree(column, index);
		m_gameBoard.DisplayBoard();
	}
	catch (Exception & ex)
	{
		//Re-display board and display exception
		m_gameBoard.DisplayBoard();
		cout << "\n" << ex;
	}
}


void freeCell::MovePlayToHome()
{
	//-1 protects from specifying a cell if a char gets stored into int
	int column = -1;	//User specified column to move card from
	int index = -1;		//User specified home cell index to move card to

	//Display current game board and key symbols on board
	m_gameBoard.DisplayBoard();

	//Prompt for which column to move from
	cout << "\nPlease enter which column (0-7) to move the card FROM: ";
	cin >> column;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (column < 0 || column > 7)
	{
		cout << "\nChoice must be a number between 0 and 7. Please try again: ";
		cin >> column;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	//Prompt for which home cell to move card to
	cout << "\nPlease enter which home cell (0-3) to move the card TO: ";
	cin >> index;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (index < 0 || index > 3)
	{
		cout << "\nChoice must be a number between 0 and 3. Please try again: ";
		cin >> index;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	try
	{
		//Move cards from a column to a free cell, and re-display board
		m_gameBoard.MovePlayToHome(column, index);
		m_gameBoard.DisplayBoard();
	}
	catch (Exception & ex)
	{
		//Re-display board and display exception
		m_gameBoard.DisplayBoard();
		cout << "\n" << ex;
	}

	//Check if user won game
	if (m_gameBoard.WonGame() == true)
	{
		m_endGame = true;
		cout << "\n\nYou won!\n\n";
	}
}


void freeCell::MoveFreeToPlay()
{
	//-1 protects from specifying a cell if a char gets stored into int
	int column = -1;	//User specified column to move card to
	int index = -1;		//User specified free cell index to move card from

	//Display current game board and key symbols on board
	m_gameBoard.DisplayBoard();

	//Prompt for which free cell to move card from
	cout << "\nPlease enter which free cell (0-3) to move the card FROM: ";
	cin >> index;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (index < 0 || index > 3)
	{
		cout << "\nChoice must be a number between 0 and 3. Please try again: ";
		cin >> index;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	//Prompt for which column to move card to
	cout << "\nPlease enter which column (0-7) to move the card TO: ";
	cin >> column;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (column < 0 || column > 7)
	{
		cout << "\nChoice must be a number between 0 and 7. Please try again: ";
		cin >> column;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	try
	{
		//Move cards from a free cell to a play area column, and re-display board
		m_gameBoard.MoveFreeToPlay(index, column);
		m_gameBoard.DisplayBoard();
	}
	catch (Exception & ex)
	{
		//Re-display board and display exception
		m_gameBoard.DisplayBoard();
		cout << "\n" << ex;
	}
}


void freeCell::MoveFreeToHome()
{
	//-1 protects from specifying a cell if a char gets stored into int
	int freeCellIndex = -1;		//User specified free cell index to move card from
	int homeCellIndex = -1;		//User specified home cell index to move card to

	//Display current game board and key symbols on board
	m_gameBoard.DisplayBoard();

	//Prompt for which free cell to move card from
	cout << "\nPlease enter which free cell (0-3) to move the card FROM: ";
	cin >> freeCellIndex;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (freeCellIndex < 0 || freeCellIndex > 3)
	{
		cout << "\nChoice must be a number between 0 and 3. Please try again: ";
		cin >> freeCellIndex;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	//Prompt for which home cell to move card to
	cout << "\nPlease enter which home cell (0-3) to move the card TO: ";
	cin >> homeCellIndex;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int

	while (homeCellIndex < 0 || homeCellIndex > 3)
	{
		cout << "\nChoice must be a number between 0 and 3. Please try again: ";
		cin >> homeCellIndex;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());	//In case char goes into an int
	}

	try
	{
		//Move cards from a free cell to a home cell, and re-display board
		m_gameBoard.MoveFreeToHome(freeCellIndex, homeCellIndex);
		m_gameBoard.DisplayBoard();
	}
	catch (Exception & ex)
	{
		//Re-display board and display exception
		m_gameBoard.DisplayBoard();
		cout << "\n" << ex;
	}

	//Check if user won game
	if (m_gameBoard.WonGame() == true)
	{
		m_endGame = true;
		cout << "\n\nYou won!\n\n";
	}
}

#endif 