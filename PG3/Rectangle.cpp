#include "Rectangle.h"
#include <iostream>
void Rectangle::size()
{
	area = width * height;
}

void Rectangle::draw()
{
	std::cout << "‹éŒ`‚Ì–ÊÏ:" << area << std::endl;
}
