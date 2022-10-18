#include "gold.h"

int CGold::TotalGold = 0;

CGold::CGold() :CObject(0) { mbGold = 0; }

void CGold::Init(int num) {
	mObjectStr = "       (จำ)       ";
	mbGold = 0;
	mbExist = true, mbCrash = false;
	mY = 0;
	switch (num) {
	case 0:
		mX = 17;
		break;
	case 1:
		mX = 37;
		break;
	case 2:
		mX = 57;
		break;
	default:
		break;
	}
}

void CGold::SetCrash() {
	mbExist = false;
	mbGold = 1;
	TotalGold += mbGold;
}