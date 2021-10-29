#include <iostream>
#include <conio.h>
#include <stdlib.h>

bool gameOver = false, playerTurn, result ;
char gSpace[3][3];

void showResult(char res)
{
	gameOver = true;
	if (result == false)
	{
		if (res == 'D') std::cout << "Draw! \"\\_('o')_/\"";
		else std::cout << "Player " << res << " won!";
		result = true;
	}
}
void Logic()
{
	for (int i = 0; i < 3; i++)
	{
		int valrow = (gSpace[i][0] + gSpace[i][1] + gSpace[i][2]);
		if (valrow == 264) showResult('X');
		else if (valrow == 237) showResult('O');
	}
	for (int i = 0; i < 3; i++)
	{
		int valrow = (gSpace[0][i] + gSpace[1][i] + gSpace[2][i]);
		if (valrow == 264) showResult('X');
		else if (valrow == 237) showResult('O');
	}
	if ((gSpace[0][0] + gSpace[1][1] + gSpace[2][2]) == 264 || (gSpace[0][2] + gSpace[1][1] + gSpace[2][0]) == 264) showResult('X');
	if ((gSpace[0][0] + gSpace[1][1] + gSpace[2][2]) == 237 || (gSpace[0][2] + gSpace[1][1] + gSpace[2][0]) == 237) showResult('O');

	bool draw = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
            if (gSpace[i][j] == '-') 
                draw = false;
	
    if (draw) showResult('D');
}
void Draw()
{
	system("CLS");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << gSpace[i][j] << '\t';
		}
		std::cout << std::endl << std::endl;
	}
	if (playerTurn) std::cout << "Turn player O " <<std::endl;
	else std::cout << "Turn player X " << std::endl;
}
int Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '7': return 0;
		case '8': return 1;
		case '9': return 2;
		case '4': return 10;
		case '5': return 11;
		case '6': return 12;
		case '1': return 20;
		case '2': return 21;
		case '3': return 22;
		}
	}
	else return -1;
}
void Set()
{
	int input = -1;
	while (input == -1) input = Input();
	if (gSpace[input/10][input%10] == '-')
	{
		if (playerTurn == false)
		{
			gSpace[input / 10][input % 10] = 'X';
		}
		else
		{
			gSpace[input / 10][input % 10] = 'O';
		}
        playerTurn = !playerTurn;
	}
}
void Game()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			gSpace[i][j] = '-';
	Draw();
	result = false;
	while (!gameOver)
	{
		Set();
		Draw();
		Logic();
	}
}
int main()
{
	Draw();
	Game();
	while (_getch() != 'e')
	{
		if (_getch() == 'r')
		{
			gameOver = false;
			Game();
		}
	}
	return 0;
}
