#include "Task.h"

Task::Task(unsigned int _id, Person* _pic, std::string _name, std::string _content, std::string _priority, Date _deadline, bool _status)
{
	id = _id;
	pic = _pic;
	name = _name;
	content = _content;
	priority = _priority;
	deadline = _deadline;
	status = _status;
}

unsigned int Task::GetId()
{
	if (this == nullptr) return -1;
	return id;
}

std::string Task::GetName()
{
	if (this == nullptr) return  "NULL";
	return name;
}

std::string Task::GetContent()
{
	if (this == nullptr) return  "NULL";
	return content;
}

std::string Task::GetPriority()
{
	if (this == nullptr) return "NULL";
	return priority;
}

Date Task::GetDeadLine()
{
	if (this == nullptr) return Date();
	return deadline;
}

bool Task::GetStatus()
{
	if (this == nullptr) return false;
	return status;
}

Person* Task::GetPic()
{
	return pic;
}

void Task::SetPic(Person* _pic)
{
	pic = _pic;
}

void Task::SetStatus(bool _status)
{
	status = _status;
}

void Task::SetPriority(std::string _priority)
{
	priority = _priority;
}

void Task::SetContent(std::string _content)
{
	content = _content;
}

void Task::SetDeadLine(Date _deadline)
{
	deadline = _deadline;
}
