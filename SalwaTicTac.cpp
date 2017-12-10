// SalwaTicTac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

enum state
{
win,
draw,
undecided
};

state checkTableStatus(char ActiveTable[]);
void boardUpdate();
int moveInTable(char ActiveTable[]);

int currentActiveTable = 5; //start by default from middle table
int gameFinished = -1;
int tableState[9];
int currentPlayer = 1;
int tableWinner[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1}; //tableWinner[x] = 1 means that player1 has won in table x, 0 means draw, -1 not finished

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab1[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab2[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab3[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab4[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab5[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab6[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab7[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab8[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char tab9[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int main()
{
	vector< char* >  vec;
	char chuj = 'y';
	vec.push_back( square );
	vec.push_back( tab1 );
	vec.push_back( &chuj );
	cout << &tab2 << endl;
	cout << &chuj << endl;
	cout <<  sizeof("bhgjh") <<endl;
	cout << undecided << endl;
	system("pause");
	return 0;
	vec.push_back( tab2 );
	vec.push_back( tab3 );
	vec.push_back( tab4 );
	vec.push_back( tab5 );
	vec.push_back( tab6 );
	vec.push_back( tab7 );
	vec.push_back( tab8 );
	vec.push_back( tab9 ); 

	boardUpdate();
	//=============================PROJECT MAIN LOOP==========================================
	while (gameFinished == -1)
	{
		boardUpdate();
		tableState[currentActiveTable] = moveInTable(vec[currentActiveTable]);

		for (int i = 1; i <= 10; i++)
		{
			if (tableWinner[i] == -1)
				break;
			else
				gameFinished = 1;
		}
	}
	cin.ignore();
	cin.get();
}

int moveInTable(char  ActiveTable [])
{
	state tableState;
	int choice;
	char mark;

	
	cout << "Player " << currentPlayer << ", enter a number:  ";
	cin >> choice;

	mark = (currentPlayer == 1) ? 'X' : 'O';

	ActiveTable[choice] = mark;  //update table data after player has made his choice
	tableState = checkTableStatus(ActiveTable);
	currentActiveTable = choice;


	if (tableState == win) //if table is finished then current player wins it
	{
		tableWinner[currentActiveTable] = currentPlayer;
		cout << "==>\aPlayer " << currentPlayer << " wins in table nr " << currentActiveTable << endl;
	}
	if (tableState == draw) //if table is finished without winner then noone wins it
	{
		tableWinner[currentActiveTable] = 0;
		cout << "==>\Table nr " << currentActiveTable << " ended up with draw" << endl;
	}
	if (tableState == undecided) //table in progress, change current player number
	{
		if (currentPlayer == 1)
			currentPlayer = 2;
		else
			currentPlayer = 1;
	}

	return tableState;
}

/*********************************************

FUNCTION TO RETURN TABLE STATUS
1 FOR TABLE IS OVER WITH RESULT
-1 FOR TABLE IS IN PROGRESS
O TABLE IS OVER AND NO RESULT
**********************************************/

state checkTableStatus(char tab[] )
{

	if (tab[1] == tab[2] && tab[2] == tab[3])

		return win;
	else if (tab[4] == tab[5] && tab[5] == tab[6])

		return win;
	else if (tab[7] == tab[8] && tab[8] == tab[9])

		return win;
	else if (tab[1] == tab[4] && tab[4] == tab[7])

		return win;
	else if (tab[2] == tab[5] && tab[5] == tab[8])

		return win;
	else if (tab[3] == tab[6] && tab[6] == tab[9])

		return win;
	else if (tab[1] == tab[5] && tab[5] == tab[9])

		return win;
	else if (tab[3] == tab[5] && tab[5] == tab[7])

		return win;
	else if (tab[1] != '1' && tab[2] != '2' && tab[3] != '3'
		&& tab[4] != '4' && tab[5] != '5' && tab[6] != '6'
		&& tab[7] != '7' && tab[8] != '8' && tab[9] != '9')

		return draw; 
	else
		return undecided;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void boardUpdate()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "Current active table: "<< currentActiveTable << endl <<endl;

	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab1[1] << "  |  " << tab1[2] << "  |  " << tab1[3] <<"  |    |  " << tab2[1] << "  |  " << tab2[2] << "  |  " << tab2[3] << "  |    |  " << tab3[1] << "  |  " << tab3[2] << "  |  " << tab3[3] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab1[4] << "  |  " << tab1[5] << "  |  " << tab1[6] <<"  |    |  " << tab2[4] << "  |  " << tab2[5] << "  |  " << tab2[6] << "  |    |  " << tab3[4] << "  |  " << tab3[5] << "  |  " << tab3[6] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab1[7] << "  |  " << tab1[8] << "  |  " << tab1[9] <<"  |    |  " << tab2[7] << "  |  " << tab2[8] << "  |  " << tab2[9] << "  |    |  " << tab3[7] << "  |  " << tab3[8] << "  |  " << tab3[9] << "  ||" << endl;

	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;
	cout << "||========1=========    =========2=========    =========3========||\n\n" << endl;
	//================================================================================================================
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab4[1] << "  |  " << tab4[2] << "  |  " << tab4[3] << "  |    |  " << tab5[1] << "  |  " << tab5[2] << "  |  " << tab5[3] << "  |    |  " << tab6[1] << "  |  " << tab6[2] << "  |  " << tab6[3] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab4[4] << "  |  " << tab4[5] << "  |  " << tab4[6] << "  |    |  " << tab5[4] << "  |  " << tab5[5] << "  |  " << tab5[6] << "  |    |  " << tab6[4] << "  |  " << tab6[5] << "  |  " << tab6[6] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab4[7] << "  |  " << tab4[8] << "  |  " << tab4[9] << "  |    |  " << tab5[7] << "  |  " << tab5[8] << "  |  " << tab5[9] << "  |    |  " << tab6[7] << "  |  " << tab6[8] << "  |  " << tab6[9] << "  ||" << endl;

	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;
	cout << "||========4=========    =========5=========    =========6========||\n\n" << endl;
	//================================================================================================================
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab7[1] << "  |  " << tab7[2] << "  |  " << tab7[3] << "  |    |  " << tab8[1] << "  |  " << tab8[2] << "  |  " << tab8[3] << "  |    |  " << tab9[1] << "  |  " << tab9[2] << "  |  " << tab9[3] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab7[4] << "  |  " << tab7[5] << "  |  " << tab7[6] << "  |    |  " << tab8[4] << "  |  " << tab8[5] << "  |  " << tab8[6] << "  |    |  " << tab9[4] << "  |  " << tab9[5] << "  |  " << tab9[6] << "  ||" << endl;

	cout << "||_____|_____|_____|    |_____|_____|_____|    |_____|_____|_____||" << endl;
	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;

	cout << "||  " << tab7[7] << "  |  " << tab7[8] << "  |  " << tab7[9] << "  |    |  " << tab8[7] << "  |  " << tab8[8] << "  |  " << tab8[9] << "  |    |  " << tab9[7] << "  |  " << tab9[8] << "  |  " << tab9[9] << "  ||" << endl;

	cout << "||     |     |     |    |     |     |     |    |     |     |     ||" << endl;
	cout << "||========7=========    =========8=========    =========9========||\n\n" << endl;
	//================================================================================================================
}

/*******************************************************************
END OF PROJECT
********************************************************************/