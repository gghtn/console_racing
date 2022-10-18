#include "obstacle.h"

void CObstacle::Init(int num) {
	mObjectStr = "[�ܡܡܡܡܡܡܡ�]";
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

void CObstacle::Render(bool invincible) {
	if (mbCrash) {
		if (invincible) {		//������ ������ ���
			mObjectStr = "[�ܡ�        �ܡ�]";
			ScreenPrint(mX, mY, mObjectStr);
		}
		else {
			ScreenPrint(mX, mY, mObjectStr);
		}
	}
	else ScreenPrint(mX, mY, mObjectStr);
}