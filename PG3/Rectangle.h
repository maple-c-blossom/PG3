#pragma once
#include "IShape.h"
class Rectangle :public IShape
{
private:
	float width = 2.5f;
	float height = 2.5f;
	float area = 0;
public:
	float GetWidth() { return width; };
	float GetHeight() { return height; };
	void SetHeight(float h) { height = h; }
	void SetWidth(float w) { width = w; }
	void size() override;
	void draw() override;
};

