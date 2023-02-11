#pragma once
#include "Task.h"
#include "PICManager.h"
#include <list>
#include <memory>
class TaskManager
{
private:
	std::list<std::unique_ptr<Task>> tasks;
    TaskManager();
    ~TaskManager();
    PICManager* picManager = PICManager::GetInstance();
public:
    TaskManager(const TaskManager& manager) = delete;
    TaskManager& operator= (const TaskManager& manager) = delete;
    static TaskManager* GetInstance();
    Task* GetTask(unsigned int id);
    unsigned int AddTask(unsigned int picId, std::string name,
        std::string content, std::string priority, Date deadline, PIC* pic, std::string status);
    void DeleteTask(unsigned int id);
    void SetStatus(unsigned int id, std::string status);
    void SetPriority(unsigned int id, std::string priority);
    void SetContent(unsigned int id, std::string content);
};

