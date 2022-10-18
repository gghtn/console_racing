#include <iostream>
#include <conio.h>
#include "game.h"
using namespace std;

int main() {

	gotoxy(3, 10);
	cout << "게임을 끝내려면 ESC 키를, 게임을 시작하려면 아무키나 누르십시오.";
	int key = _getch();

	while (1) {
		if (key != 27) {
			CGame game;
			game.GameStart();
		}
		else break;

		system("cls");
		gotoxy(3, 10);
		cout << "게임을 끝내려면 ESC 키를, 다시 시작하려면 아무키나 누르십시오.";
		if (_getch() == 27) break;
	}


	return 0;
}