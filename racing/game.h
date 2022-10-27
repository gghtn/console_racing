#pragma once
#include "console.h"
#include "user.h"
#include "object.h"
#include "obstacle.h"
#include "item.h"
#include "gold.h"

class CGame {
	int mScore, mGold;
	double mTime;
	CObject* p[2];
public:
	CGame();
	~CGame();
	void GameStart();
	void GameOver();
	void Init(){ mScore = 0, mGold = 0, mTime = 0.0; }

	//유저, 오브젝트(장애물,아이템), 오브젝트(골드), 카운트, 장애물 충돌 y좌표
	void Display(CUser& user, CObject** p, CObject** pp, int count, int crashY);
	void RenderInf(int, int, double);
};