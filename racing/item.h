#pragma once
#include "object.h"

class CItem : public CObject {
public:
	CItem() : CObject(0) {}

	void Init(int);

};