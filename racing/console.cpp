#include "console.h"
#pragma warning(disable:4996)

void gotoxy(SHORT x, SHORT y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//콘솔창 크기 조절
void SetConsoleSize(int x, int y) {
	char command[100];
	sprintf(command, "mode con lines=%d cols=%d", y, x);
	system(command);
}

//커서설정
void CursorView(bool b) {
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1;			//커서 굵기
	cursor.bVisible = b;	    //커서 visible
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}