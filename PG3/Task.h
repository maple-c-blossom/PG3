#pragma once
#include <string>
#include "Person.h"
#include "UtilStruct.h"
class Task
{
private:
    unsigned int id;
    Person* pic;
    std::string name;
    std::string content;
    std::string priority;
    Date deadline;
    bool status;
public:
    Task(unsigned int _id, Person* _pic, std::string _name,
        std::string _content, std::string _priority, Date _deadline, bool _status);
    unsigned int GetId();
    std::string GetName();
    std::string GetContent();
    std::string GetPriority();
    Date GetDeadLine();
    bool GetStatus();
    Person* GetPic();
    void SetPic(Person* _pic);
    void SetStatus(bool _status);
    void SetPriority(std::string _priority);
    void SetContent(std::string _content);
    void SetDeadLine(Date _deadline);
};

