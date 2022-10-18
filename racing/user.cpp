#include "user.h"

CUser::CUser() :mUserY(45) {
	mTopScore = 0;
	mbLife = true, mbInvicible = false;
	mUserX = 43;
	mUserCar[0] = "�� �� ��";
	mUserCar[1] = "��  ��";
	mUserCar[2] = "��   ��";
	mUserCar[3] = "�ۦ� ��";
}

CUser::CUser(const CUser& Other) :mUserY(45) {
	mTopScore = Other.mTopScore;
	mbLife = Other.mbLife;
	mbInvicible = Other.mbInvicible;
	mUserX = Other.mUserX;
	mUserCar[0] = Other.mUserCar[0];
	mUserCar[1] = Other.mUserCar[1];
	mUserCar[2] = Other.mUserCar[2];
	mUserCar[3] = Other.mUserCar[3];
}

void CUser::SetCrashCar() {
	mUserCar[0] = " ��";
	mUserCar[1] = "�� �� ��   ��";
	mUserCar[2] = " /  �� ��";
	mUserCar[3] = "��    ��";
}

void CUser::SetInvicibleCar() {
	mbInvicible = true;
	mUserCar[0] = "�� �� ��";
	mUserCar[1] = "��  ��";
	mUserCar[2] = "�� �ڦ�";
	mUserCar[3] = "�ܦ� ��";
}

void CUser::SetInitCar() {
	mbInvicible = false;
	mUserCar[0] = "�� �� ��";
	mUserCar[1] = "��  ��";
	mUserCar[2] = "��   ��";
	mUserCar[3] = "�ۦ� ��";
}