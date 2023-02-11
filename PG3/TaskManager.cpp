#include "TaskManager.h"
using namespace std;

TaskManager::~TaskManager()
{
}

TaskManager* TaskManager::GetInstance()
{
    static TaskManager instance;
    return &instance;
}

Task* TaskManager::GetTask(unsigned int id)
{
    Task* ptr;
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            ptr = itr.get();
            return ptr;
        }
    }
    return nullptr;
}

unsigned int TaskManager::AddTask(unsigned int picId, std::string name, std::string content, std::string priority, Date deadline, PIC* pic, std::string status)
{
    for (unsigned int id = 0; id < tasks.size(); id++)
    {
        bool success = true;//id‚ª”í‚Á‚Ä–³‚¯‚ê‚ÎtrueA”í‚Á‚½‚çfalse
        id++;
        for (auto& itr : tasks)
        {
            if (itr->GetId() == id)
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            unique_ptr<Task> temp = make_unique<Task>(id,picManager->GetPicPtr(picId), name, content, priority, deadline, status);
            tasks.push_back(move(temp));
            return id;
        }

    }
    return -1;
}

void TaskManager::DeleteTask(unsigned int id)
{
    tasks.remove_if([=](auto& itr) {return itr->GetId() == id; });
}

void TaskManager::SetStatus(unsigned int id, std::string status)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetStatus(status);
            return;
        }
    }
}

void TaskManager::SetPriority(unsigned int id, std::string priority)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetPriority(priority);
            return;
        }
    }
}

void TaskManager::SetContent(unsigned int id, std::string content)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetContent(content);
            return;
        }
    }
}
