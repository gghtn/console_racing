#pragma once
#include "doublebuffer.h"

class CObject
{
protected:
	int mX, mY;
	bool mbCrash, mbExist;
	string mObjectStr;
public:
	CObject(int x) { mX = x, mY = 0, mbCrash = false, mbExist = false, mObjectStr = ""; }

	virtual void Init(int) = 0;	//순수 가상 함수

	int GetX() { return mX; }
	int GetY() { return mY; }
	bool GetCrash() { return mbCrash; }
	bool GetExist() { return mbExist; }

	virtual void SetCrash() { mbCrash = !mbCrash; }
	void SetX(int num) { mX = num; }
	void SetY(int num) { mY += num; }
	void SetExist() { mbExist = !mbExist; }

	void Render() {
		ScreenPrint(mX, mY, mObjectStr);
	}
};