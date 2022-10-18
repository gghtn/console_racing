#pragma once
#include "doublebuffer.h"

class CUser {
	int mTopScore;
	bool mbLife, mbInvicible;		//积粮咯何, 公利咯何
	int mUserX;
	const int mUserY;
	string mUserCar[4];
public:
	CUser();
	CUser(const CUser& Other);

	int GetUserX() { return mUserX; }
	int GetUserY() { return mUserY; }
	string GetUserCar(int i) { return mUserCar[i]; }
	bool GetLife() { return mbLife; }
	bool GetInvicible() { return mbInvicible; }

	void SetCrashCar();
	void SetInvicibleCar();
	void SetInitCar();
	void SetUserX(int num) { mUserX = num; }
	void SetLife() { mbLife = !mbLife; }
};