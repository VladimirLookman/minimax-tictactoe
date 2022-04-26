#include <iostream>
using namespace std;
char field[9] = { '*','*','*','*','*','*','*','*','*' };
int player = 0, bestMove = 0;

int aiWin()
{
	if (
		(field[0] == 'O' && field[1] == 'O' && field[2] == 'O') ||
		(field[3] == 'O' && field[4] == 'O' && field[5] == 'O') ||
		(field[6] == 'O' && field[7] == 'O' && field[8] == 'O') ||
		(field[0] == 'O' && field[3] == 'O' && field[6] == 'O') ||
		(field[1] == 'O' && field[4] == 'O' && field[7] == 'O') ||
		(field[2] == 'O' && field[5] == 'O' && field[8] == 'O') ||
		(field[0] == 'O' && field[4] == 'O' && field[8] == 'O') ||
		(field[2] == 'O' && field[4] == 'O' && field[6] == 'O')
		) {
		return 1;
	}
	else 
	{
		return 0;
	}
}

int huWin()
{
	if (
		(field[0] == 'X' && field[1] == 'X' && field[2] == 'X') ||
		(field[3] == 'X' && field[4] == 'X' && field[5] == 'X') ||
		(field[6] == 'X' && field[7] == 'X' && field[8] == 'X') ||
		(field[0] == 'X' && field[3] == 'X' && field[6] == 'X') ||
		(field[1] == 'X' && field[4] == 'X' && field[7] == 'X') ||
		(field[2] == 'X' && field[5] == 'X' && field[8] == 'X') ||
		(field[0] == 'X' && field[4] == 'X' && field[8] == 'X') ||
		(field[2] == 'X' && field[4] == 'X' && field[6] == 'X')
		) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int checkField()
{
	for (int i = 0; i < 9; i++)
	{
		if (field[i] != 'O')
		{
			if (field[i] != 'X')
			{
				return 0;
			}
		}
	}
	return 1;
}

void cleanboard()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "\n";
	}
}
void board1()
{
	cout << "----------Tic Tac Toe----------" << endl;
	cout << "   The computer plays with 0   " << endl;
	cout << "    The player plays with X    " << endl;
	cout << "Numbering of the playing fields" << endl;
	cout << "            |7|8|9|            " << endl;
	cout << "            |-+-+-|            " << endl;
	cout << "            |4|5|6|            " << endl;
	cout << "            |-+-+-|            " << endl;
	cout << "            |1|2|3|            " << endl;
	cout << "-------------------------------" << endl;
}
void board()
{
	cout << "\n";
	cout << "             " << field[6] << '|' << field[7] << '|' << field[8] << endl;
	cout << "             " << '-' << '+' << '-' << '+' << '-' << endl;
	cout << "             " << field[3] << '|' << field[4] << '|' << field[5] << endl;
	cout << "             " << '-' << '+' << '-' << '+' << '-' << endl;
	cout << "             " << field[0] << '|' << field[1] << '|' << field[2] << endl;
}
int get_move()
{
	int move;
	cout << "Your move: ";
	cin >> move;
	while (move > 9 || move < 1 || field[move - 1] != '*')
	{
		cout << "ERROR!!!" << endl;
		cin >> move;
	}
	return move;
}

int minimax(int player)
{
	int moves[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int bestScore1 = -10000;
	int bestScore2 = 10000;
	int i, j, score = 1;
	if (aiWin() == 1)
	{
		return 10;
	}
	if (huWin() == 1)
	{
		return -10;
	}
	if ((checkField() == 1))
	{
		return 0;
	}

	for (i = 0; i < 9; i++)
	{
		if (field[i] == '*')
		{
			if (bestScore2 > bestScore1)
			{
				if (player == 1)
				{
					field[i] = 'O';
					score = minimax(0);
				}
				else
				{
					field[i] = 'X';
					score = minimax(1);
				}
				field[i] = '*';
				moves[i] = score;
			}
		}
	}

	if (player == 1)
	{
		bestScore1 = -10000;
		for (int j = 0; j < 9; j++)
		{
			if (moves[j] > bestScore1 && moves[j] != 1)
			{
				bestScore1 = moves[j];
				bestMove = j;
			}
		}
		return bestScore1;
	}
	if (player == 0)
	{
		bestScore2 = 10000;
		for (int j = 0; j < 9; j++)
		{
			if (moves[j] < bestScore2 && moves[j] != 1)
			{
				bestScore2 = moves[j];
				bestMove = j;
			}
		}
		return bestScore2;
	}
}

int main()
{
	int firstMove, move;
	board1();
	cout << "Who goes first: 1-computer; 2-player" << endl;
	cin >> firstMove;
	if (firstMove == 2)
	{
		player = 0;
		cleanboard();
		board1();
		board();
	up:	move = get_move();
		if (field[move - 1] == '*')
		{
			field[move - 1] = 'X';
			board();
		}
		else
		{
			cout << "Wrong move! Move again: " << endl;
			goto up;
		}
		player = 1;
	}
	while (true)
	{
		minimax(1);
		field[bestMove] = 'O';
		cleanboard();
		board1();
		board();
		if (aiWin() == 1)
		{
			cout << "O Wins!" << endl;
			break;
		}
		if (checkField() == 1)
		{
			cout << "Draw!" << endl;
			break;
		}
		
	up2:move = get_move();
		if (field[move - 1] == '*')
		{
			field[move - 1] = 'X';
			board();
		}
		else
		{
			cout << "Wrong move! Move again: " << endl;
			goto up2;
		}
		if (huWin() == 1)
		{
			cout << "X Wins!" << endl;
			break;
		}
		if (checkField() == 1)
		{
			cout << "Draw!" << endl;
			break;
		}
	}

	return 0;
}