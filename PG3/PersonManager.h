#pragma once
#include "Person.h"
#include <list>
#include <memory>
class PersonManager
{
private:
	PersonManager() {};
	~PersonManager() {};
	std::list<std::unique_ptr<Person>> pics;
public:
    PersonManager(const PersonManager& manager) = delete;
    PersonManager& operator= (const PersonManager& manager) = delete;
    static PersonManager* GetInstance();
    void PrintAllId();
    void OutPut();
    void InPut();
    Person* GetPicPtr(unsigned int id);
    unsigned int AddPIC(std::string name, std::string className);
    unsigned int AddPIC(unsigned int id, std::string name, std::string className);//id手動設定用(ロード時に使用する)
    void SetName(unsigned int id, std::string _name);
    void SetClass(unsigned int id, std::string _class);
    void DeletePic(unsigned int id);
  
};

