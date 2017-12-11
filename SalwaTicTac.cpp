// SalwaTicTac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
int tableWinner[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //tableWinner[x] = 1 means that player1 has won in table x, 0 means draw, -1 not finished
int player1score = 0, player2score = 0;

char square[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab1[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab2[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab3[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab4[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab5[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab6[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab7[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab8[10] = { '0','1','2','3','4','5','6','7','8','9' };
char tab9[10] = { '0','1','2','3','4','5','6','7','8','9' };

vector< char* >  vec;

int main()
{
	

	vec.push_back(square);
	vec.push_back(tab1);
	vec.push_back(tab2);
	vec.push_back(tab3);
	vec.push_back(tab4);
	vec.push_back(tab5);
	vec.push_back(tab6);
	vec.push_back(tab7);
	vec.push_back(tab8);
	vec.push_back(tab9);

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

int moveInTable(char  ActiveTable[])
{
	state tableState;
	int choice;
	char mark;


	cout << "Player " << currentPlayer << ", enter a number:  ";

	while(1)
	{
		cin >> choice;
		if (choice > 0 && choice < 10)
			break;
		cout << "Wrong choice. Once again..." << endl;
	} 

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

state checkTableStatus(char tab[])
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
	cout << "\n\n\tTic Tac Toe\n\n" << endl;

	cout << "Player 1 (X) score: " << player1score << endl << "Player 2 (O) score: " << player2score << endl;

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "Current active table: " << currentActiveTable << endl << endl;

	cout << endl;
	cout << endl;
	int indexTable = 1, indexVector = 1, tableNumber = 1, tmp;

	for (int a = 1; a <= 3; a++)// 3 rows of tables
	{
		indexTable = 1;
		for (int b = 1; b <= 3; b++)// 3 rows of single table
		{
			for (int c = 1; c <= 3; c++)  //1
				cout << "|     |     |     |    ";
			cout << endl;
			for (int d = 1; d <= 3; d++) //2
			{
				tmp = indexTable;
				for (int e = 1; e <= 3; e++) //single cell
				{
					cout << "|  " << vec[indexVector][indexTable++] << "  ";
				}
				indexTable = tmp;
				indexVector++;
				cout << "|    ";
			}
			indexVector -= 3;
			
			cout << endl;
			for (int c = 0; c < 3; c++) //3
				cout << "|_____|_____|_____|    ";
			
			cout << endl;
			indexTable += 3;
		}
		indexVector += 3;
		for (int c = 0; c < 3; c++)
		{
			if(currentActiveTable == tableNumber)
				cout << "=========" << tableNumber++ << "=========    ";
			else 
				cout << "        =" << tableNumber++ << "=            ";
		}
		cout << endl;
	}
}