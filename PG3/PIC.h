#pragma once
#include <string>
class Person
{
private:
    unsigned int id;
    std::string name;
    std::string className;
public:
    Person(unsigned int _id,std::string _name, std::string _className);
    unsigned int GetId();
    std::string GetName();
    std::string GetClass();
    void SetName(std::string _name);
    void SetClass(std::string _class);
};

