#pragma once
#include "object.h"

class CGold : public CObject {
	bool  mbGold;
	static int TotalGold;
public:
	CGold();

	void Init(int);
	void SetCrash();
	void SetTotalGold() { TotalGold = 0; }

	int GetGold() { return TotalGold; }
};