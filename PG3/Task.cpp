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
	return id;
}

std::string Task::GetName()
{
	return name;
}

std::string Task::GetContent()
{
	return content;
}

std::string Task::GetPriority()
{
	return priority;
}

Date Task::GetDeadLine()
{
	return deadline;
}

bool Task::GetStatus()
{
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
