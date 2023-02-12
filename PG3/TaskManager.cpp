#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



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
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
    return nullptr;
}

unsigned int TaskManager::AddTask(unsigned int picId, std::string name, std::string content, std::string priority, Date deadline,bool status)
{
    int id = 1;
    for (unsigned int i = 0; i < tasks.size(); i++)
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
    if (tasks.size() == 0)
    {
        int id = 1;
        unique_ptr<Task> temp = make_unique<Task>(id, picManager->GetPicPtr(picId), name, content, priority, deadline, status);
        tasks.push_back(move(temp));
        return id;
    }
    return -1;
}

unsigned int TaskManager::AddTask(unsigned int id, unsigned int picId, std::string name, std::string content, std::string priority, Date deadline,  bool status)
{
    unique_ptr<Task> temp = make_unique<Task>(id, picManager->GetPicPtr(picId), name, content, priority, deadline, status);
    tasks.push_back(move(temp));
    return id;
}

void TaskManager::DeleteTask(unsigned int id)
{
    tasks.remove_if([=](auto& itr) {return itr->GetId() == id; });
}

void TaskManager::PrintAllId()
{
    for (auto& itr : tasks)
    {
        cout << "ID:" << itr->GetId() << "ƒ^ƒXƒN–¼:" << itr->GetName() << endl;
    }

}

void TaskManager::SetPic(unsigned int id, Person* pic)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetPic(pic);
            return;
        }
    }
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetStatus(unsigned int id, bool status)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetStatus(status);
            return;
        }
    }
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
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
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
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
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetDate(unsigned int id, Date deadline)
{
    for (auto& itr : tasks)
    {
        if (itr->GetId() == id)
        {
            itr->SetDeadLine(deadline);
            return;
        }
    }
    cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::OutPut()
{
    ofstream file;
    file.open("Data\\task.txt", std::ios::out);
    if (file.fail())
    {
        return;
    }
    for (auto& itr : tasks)
    {
        file << "ID" << " " << itr->GetId() << endl;
        file << "Name" << " " << itr->GetName() << endl;
        file << "Content" << " " << itr->GetContent() << endl;
        file << "Priority" << " " << itr->GetPriority() << endl;
        file << "Status" << " " << itr->GetStatus() << endl;
        if (itr->GetPic())
        {
            file << "PicID" << " " << itr->GetPic()->GetId() << endl;
        }
        else
        {
            file << "PicID" << " " << -1 << endl;
        }
        file << "DeadLineMonth" << " " << itr->GetDeadLine().month << endl;
        file << "DeadLineDay" << " " << itr->GetDeadLine().day << endl;
        file << "End" << " " << endl;
        file << endl;
    }
    file << "EOF" << endl;
    file.close();
}

void TaskManager::InPut()
{
    unsigned int id;
    unsigned int pic;
    std::string name;
    std::string content;
    std::string priority;
    Date deadline;
    bool status;
    ifstream file;
    file.open("Data\\task.txt", std::ios::in);
    if (file.fail())
    {
        return;
    }
    string line;
    while (getline(file, line))
    {
        std::istringstream line_stream(line);
        string key;
        getline(line_stream, key, ' ');
        if (key == "ID")
        {
            line_stream >> id;
        }
        else if (key == "Name")
        {
            line_stream >> name;
        }
        else if (key == "Content")
        {
            line_stream >> content;
        }
        else if (key == "Priority")
        {
            line_stream >> priority;
        }
        else if (key == "Status")
        {
            line_stream >> status;
        }
        else if (key == "PicID")
        {
            line_stream >> pic;
        }
        else if (key == "DeadLineMonth")
        {
            line_stream >> deadline.month;
        }
        else if (key == "DeadLineDay")
        {
            line_stream >> deadline.day;
        }
        else if (key == "End")
        {
            AddTask(id,pic, name, content, priority, deadline, status);
        }
    }

    file.close();
}
