#include "Task.h"

Task::Task(unsigned int _id, PIC* _pic, std::string _name, std::string _content, std::string _priority, Date _deadline, std::string _status)
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

std::string Task::GetStatus()
{
	return status;
}

void Task::SetPic(PIC* _pic)
{
	pic = _pic;
}

void Task::SetStatus(std::string _status)
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
