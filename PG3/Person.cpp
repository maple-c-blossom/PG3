#include "Person.h"

Person::Person(unsigned int _id, std::string _name, std::string _className)
{
	id = _id;
	name = _name;
	className = _className;
}

unsigned int Person::GetId()
{
	if (this == nullptr) return -1;
	return id;
}

std::string Person::GetName()
{
	if (this == nullptr) return "NULL";
	return name;
}

std::string Person::GetClass()
{
	if (this == nullptr) return "NULL";
	return className;
}

void Person::SetName(std::string _name)
{
	if (this == nullptr) return;
	name = _name;
}

void Person::SetClass(std::string _class)
{
	if (this == nullptr) return;
	className = _class;
}
