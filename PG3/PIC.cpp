#include "PIC.h"

PIC::PIC(unsigned int _id, std::string _name, std::string _className)
{
	id = _id;
	name = _name;
	className = _className;
}

unsigned int PIC::GetId()
{
	return id;
}

std::string PIC::GetName()
{
	return name;
}

std::string PIC::GetClass()
{
	return className;
}

void PIC::SetName(std::string _name)
{
	name = _name;
}

void PIC::SetClass(std::string _class)
{
	className = _class;
}
