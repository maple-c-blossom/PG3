#include "Person.h"

Person::Person(unsigned int _id, std::string _name, std::string _className)
{
	id = _id;
	name = _name;
	className = _className;
}

unsigned int Person::GetId()
{
	return id;
}

std::string Person::GetName()
{
	return name;
}

std::string Person::GetClass()
{
	return className;
}

void Person::SetName(std::string _name)
{
	name = _name;
}

void Person::SetClass(std::string _class)
{
	className = _class;
}
