#include "Rectangle.h"
#include <iostream>
void Rectangle::size()
{
	area = width * height;
}

void Rectangle::draw()
{
	std::cout << "��`�̖ʐ�:" << area << std::endl;
}
