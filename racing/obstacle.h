#pragma once
#include "object.h"

class CObstacle : public CObject {
public:
	CObstacle() :CObject(0) {}

	void Init(int);

	void Render(bool);
};

