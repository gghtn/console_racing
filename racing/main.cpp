#include <iostream>
#include <conio.h>
#include "game.h"
using namespace std;

int main() {

	gotoxy(3, 10);
	cout << "������ �������� ESC Ű��, ������ �����Ϸ��� �ƹ�Ű�� �����ʽÿ�.";
	int key = _getch();

	while (1) {
		if (key != 27) {
			CGame game;
			game.GameStart();
		}
		else break;

		system("cls");
		gotoxy(3, 10);
		cout << "������ �������� ESC Ű��, �ٽ� �����Ϸ��� �ƹ�Ű�� �����ʽÿ�.";
		if (_getch() == 27) break;
	}


	return 0;
}