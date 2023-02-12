#pragma once
#include "Task.h"
#include "PersonManager.h"
#include <list>
#include <memory>
class TaskManager
{
private:
    TaskManager(){};
    ~TaskManager(){};
    PersonManager* picManager = PersonManager::GetInstance();
	std::list<std::unique_ptr<Task>> tasks;
public:
    TaskManager(const TaskManager& manager) = delete;
    TaskManager& operator= (const TaskManager& manager) = delete;
    static TaskManager* GetInstance();
    Task* GetTask(unsigned int id);
    unsigned int AddTask(unsigned int picId, std::string name,
        std::string content, std::string priority, Date deadline, bool status);
    unsigned int AddTask(unsigned int id, unsigned int picId, std::string name,
        std::string content, std::string priority, Date deadline,  bool status);//id手動設定用(ロード時に使用する)
    void DeleteTask(unsigned int id);
    void PrintAllId();
    void SetPic(unsigned int id,Person* pic);
    void SetStatus(unsigned int id, bool status);
    void SetPriority(unsigned int id, std::string priority);
    void SetContent(unsigned int id, std::string content);
    void SetDate(unsigned int id, Date deadline);
    void OutPut();
    void InPut();
};

