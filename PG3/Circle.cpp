#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

void Circle::size()
{
	area = rudius * rudius * M_PI;
}

void Circle::draw()
{
	std::cout << "�~�̖ʐ�:" << area << std::endl;
}
