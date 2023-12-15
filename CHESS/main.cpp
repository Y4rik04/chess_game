#include <iostream>
#include <string>
#include "chess.h"
using namespace std;
int main() //основна програма для запуску гри
{
	Board b;
	string start;
	bool game = true;
	cout << "Enter any key to begin" << endl;
	cin >> start;

	while (game) //цикл запуску
	{
		b.setBoard(); //створюємо дошку
		while (b.playGame());
		cout << "Do you want to play again? (Press y if you want) ";
		cin >> start;
		if (start!= "y")
			game = false;
	}	
	return 0;
}