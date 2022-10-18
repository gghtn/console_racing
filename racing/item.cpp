#include "item.h"

void CItem::Init(int num) {
	mObjectStr = "       (¡Ú)       ";
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