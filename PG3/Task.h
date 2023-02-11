#pragma once
#include <string>
#include "PIC.h"
#include "UtilStruct.h"
class Task
{
private:
    unsigned int id;
    PIC* pic;
    std::string name;
    std::string content;
    std::string priority;
    Date deadline;
    std::string status;
public:
    Task(unsigned int _id, PIC* _pic, std::string _name,
        std::string _content, std::string _priority, Date _deadline, std::string _status);
    unsigned int GetId();
    std::string GetName();
    std::string GetContent();
    std::string GetPriority();
    Date GetDeadLine();
    std::string GetStatus();
    void SetPic(PIC* _pic);
    void SetStatus(std::string _status);
    void SetPriority(std::string _priority);
    void SetContent(std::string _content);
};

