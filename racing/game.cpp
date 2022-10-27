#include "game.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable:4996)

#define MAX_OBSTACLE 8
#define MAX_GOLD 10
#define MAX_LEFT 23
#define MAX_RIGHT 63

enum { LEFT = 75, RIGHT = 77, INVICIBLE_TIME = 2000 };

CGame::CGame() {
	mScore = 0, mGold = 0, mTime = 0.0;
	p[0] = NULL;
	p[1] = NULL;
}
CGame::~CGame() {
	delete[] p[0];
	delete[] p[1];
	p[0] = NULL;
	p[1] = NULL;
}

void CGame::GameStart() {
	Init();
	SetConsoleSize(120, 50);
	ScreenInit();
	CUser user;

	p[0] = new CObstacle[MAX_OBSTACLE];
	if (p[0] == NULL) return;

	p[1] = new CItem;
	if (p[1] == NULL) return;

	CObject** pp = new CObject * [MAX_GOLD];	//�θ� Ŭ������ �ڽ� Ŭ������ ũ�Ⱑ �ٸ��� ������ ������ �Ҵ�
	if (pp == NULL) return;
	for (int i = 0; i < MAX_GOLD; i++) {
		pp[i] = new CGold;
	}
	CGold* pG = static_cast<CGold*>(pp[0]);
	pG->SetTotalGold();

	srand((unsigned)time(NULL));
	//�ӵ� ���� ����, �����ð� ����, ���ǵ� ����
	int count = 0, time = INVICIBLE_TIME + 1, speed = 0, i;
	//�ð� ���� ����
	clock_t start, end;

	while (1) {
		start = clock();
		if (!user.GetLife()) {		//������ �׾��� ���
			Sleep(1000);
			break;
		}

		if (user.GetInvicible() && time > INVICIBLE_TIME) {
			user.SetInitCar();
		}

		if (count % 100 == 0) mScore++;

		if (count % 1000 == 999) speed = min(++speed, 10);

		ScreenClear();

		//��ֹ� ����
		if (count % (200 - speed * 10) == 0) {
			int create = 0, pos_x = 0;
			for (i = 0; i < MAX_OBSTACLE; i++) {
				if (!p[0][i].GetExist()) {
					p[0][i].Init(rand() % 3);
					if (p[0][i].GetX() == pos_x) p[0][i].SetExist();	//������ ��ֹ��� x��ǥ�� ���� �� ����
					else pos_x = p[0][i].GetX();
					create++;
				}
				if (create == 2) break;
			}
		}
		// ������ ����
		if (count % 8000 == 200) {
			int pos_x = 0;
			p[1]->Init(rand() % 3);
			pos_x = p[1]->GetX();
			for (int j = 0; j < MAX_OBSTACLE; j++) {
				if (p[0][j].GetExist() && p[0][j].GetY() == 0 && p[0][j].GetX() == pos_x) {
					p[0][j].SetExist();
					break;
				}
			}
		}
		// ��� ����
		if (count % (100 - speed * 5) == 0) {
			int pos_x = 0;
			for (i = 0; i < MAX_GOLD; i++) {

				if (!(pp[i]->GetExist())) {
					pp[i]->Init(rand() % 3);
					pos_x = pp[i]->GetX();
					for (int j = 0; j < MAX_OBSTACLE; j++) {
						if (p[0][j].GetExist() && p[0][j].GetY() == 0 && p[0][j].GetX() == pos_x) {
							pp[i]->SetExist();
							break;
						}
					}
					if (p[1]->GetExist() && p[1]->GetY() == 0 && p[1]->GetX() == pos_x)
						pp[i]->SetExist();

					break;
				}

			}
		}

		//������Ʈ �̵�
		if (count % 11 - speed == 0) {
			for (i = 0; i < MAX_OBSTACLE; i++) {
				if (p[0][i].GetExist()) {
					p[0][i].SetY(1);
					if (p[0][i].GetY() == 50) p[0][i].SetExist();
				}
			}
			if (p[1]->GetExist()) {
				p[1]->SetY(1);
				if (p[1]->GetY() == 50) p[1]->SetExist();
			}
			for (i = 0; i < MAX_GOLD; i++) {
				if (pp[i]->GetExist()) {
					pp[i]->SetY(1);
					if (pp[i]->GetY() == 50) pp[i]->SetExist();
				}
			}

		}


		//���� �̵�
		if (_kbhit()) {
			switch (_getch()) {
			case LEFT:
				user.SetUserX(max(user.GetUserX() - 20, MAX_LEFT));
				break;
			case RIGHT:
				user.SetUserX(min(user.GetUserX() + 20, MAX_RIGHT));
				break;
			}
		}


		//��ֹ� �浹
		int userX = user.GetUserX();
		int crashY = 0;
		for (i = 0; i < MAX_OBSTACLE; i++) {
			if (p[0][i].GetExist()) {
				if ((48 >= p[0][i].GetY() && p[0][i].GetY() >= 45) && userX - p[0][i].GetX() == 6) {
					p[0][i].SetCrash();
					if (!user.GetInvicible()) {
						user.SetLife();
						user.SetCrashCar();
					}
					crashY = p[0][i].GetY();
					break;
				}
			}
		}
		//������ �浹
		if (p[1]->GetExist()) {
			if ((48 >= p[1]->GetY() && p[1]->GetY() >= 45) && userX - p[1]->GetX() == 6) {
				p[1]->SetExist();
				user.SetInvicibleCar();
				time = 0;
			}
		}
		//��� �浹
		for (i = 0; i < MAX_GOLD; i++) {
			if (pp[i]->GetExist()) {
				if ((48 >= pp[i]->GetY() && pp[i]->GetY() >= 45) && userX - pp[i]->GetX() == 6) {
					pp[i]->SetCrash();
					break;
				}
			}
		}

		Display(user, p, pp, count, crashY);//����, ������Ʈ, ī��Ʈ, ��ֹ� �浹 y��ǥ

		end = clock();
		mTime += (double)end - start;
		RenderInf(pG->GetGold(), time, mTime / CLOCKS_PER_SEC);

		ScreenFlipping();
		count++, time++;
	}

	mGold = pG->GetGold();
	delete[] pp;

	ScreenRelease();
	GameOver();
}

void CGame::GameOver() {
	system("cls");
	char exitPrint[200];
	sprintf(exitPrint, "Time: %.2lf��,Gold: %d��(%d��),TotalScore: %d��", mTime / CLOCKS_PER_SEC, mGold, mGold * 10, mScore + mGold * 10);
	int y = 5;
	gotoxy(5, y);
	for (unsigned int i = 0; i < strlen(exitPrint); i++) {
		if (_kbhit()) {
			if (_getch() == 27) break;
		}
		if (exitPrint[i] == ',') {
			y += 3;
			gotoxy(5, y);
			continue;
		}
		cout << exitPrint[i];
		Sleep(50);
	}

	Sleep(1000);
}

void CGame::Display(CUser& user, CObject** p, CObject** pp, int count, int crashY) {
	int i;
	string strLine1 = "��                  ��                  ��                  ��";
	string strLine2 = "��                  ��                  ��                  ��";
	if (count % 2 == 1) count = 1;
	else count = 0;
	for (i = 0; i < 50; i++) {
		if ((i + count) % 2 == 0) ScreenPrint(15, i, strLine1);
		else ScreenPrint(15, i, strLine2);
	}

	//��ֹ� Render
	for (i = 0; i < MAX_OBSTACLE; i++) {
		CObstacle* obsPtr = static_cast<CObstacle*> (*(p)+i);
		if (p[0][i].GetExist()) obsPtr->Render(user.GetInvicible());
	}
	//��� Render
	for (i = 0; i < MAX_GOLD; i++) {
		if (pp[i]->GetExist()) pp[i]->Render();
	}
	//������ Render
	if (p[1]->GetExist())
		p[1]->Render();

	//���� Render
	int userX = user.GetUserX(), userY = user.GetUserY();
	for (i = 0; i < 4; i++) {
		if (user.GetInvicible() || crashY == 0)
			ScreenPrint(userX, userY + i, user.GetUserCar(i));
		else
			if (crashY - 45 != i) ScreenPrint(userX, userY + i, user.GetUserCar(i));
	}
}

void CGame::RenderInf(int g, int invicible, double time) {
	string str1 = "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";
	string str2 = "��                             ��";
	string str3 = "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";
	ScreenPrint(82, 5, str1);
	for (int i = 6; i < 20; i++) ScreenPrint(82, i, str2);
	ScreenPrint(82, 20, str3);

	char info[15];
	memset(info, '\0', 15);
	sprintf(info, "���� : %d", mScore);
	ScreenPrint(85, 7, info);

	memset(info, '\0', 15);
	sprintf(info, "��� : %d", g);
	ScreenPrint(85, 10, info);

	memset(info, '\0', 15);
	if (invicible <= INVICIBLE_TIME) {
		sprintf(info, "���� : %d", (INVICIBLE_TIME - invicible) / 10);
	}
	else sprintf(info, "���� : %d", 0);
	ScreenPrint(85, 13, info);

	memset(info, '\0', 15);
	sprintf(info, "Time: %.2lf", time);
	ScreenPrint(85, 16, info);
}