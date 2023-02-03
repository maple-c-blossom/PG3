#pragma once
#include "IShape.h"
class Circle:public IShape
{
private:
	float rudius = 2.5f;
	float area = 0;
public:
	float GetRudius() { return rudius; };
	void SetRudius(float r) { rudius = r; }
	void size() override;
	void draw() override;
};

