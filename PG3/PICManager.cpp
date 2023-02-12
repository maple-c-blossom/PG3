#include "PICManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
PersonManager* PersonManager::GetInstance()
{
    static PersonManager instance;
    return &instance;
}
void PersonManager::PrintAllId()
{
    for (auto& itr : pics)
    {
        cout << "ID:" << itr->GetId() << "’S“–ŽÒ–¼:" << itr->GetName() << endl;
    }

}
void PersonManager::OutPut()
{
    ofstream file;
    file.open("pic.txt", std::ios::out);
    if (file.fail())
    {
        return;
    }
    for (auto& itr : pics)
    {
        file << "ID" << " " << itr->GetId() << endl;
        file << "Name" << " " << itr->GetName() << endl;
        file << "ClassName" << " " << itr->GetClass() << endl;
        file << "End" << " " << "End" << endl;
    }
    file.close();
}
void PersonManager::InPut()
{

    unsigned int id;
    std::string name;
    std::string className;
    ifstream file;
    file.open("task.txt", std::ios::in);
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
        else if (key == "ClassName")
        {
            line_stream >> className;
        }
        else if (key == "End")
        {
            AddPIC(id, name, className);
        }
    }
    file.close();
}
Person* PersonManager::GetPicPtr(unsigned int id)
{
    Person* ptr;
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            ptr = itr.get();
            return ptr;
        }
    }
    cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
    return nullptr;
}

unsigned int PersonManager::AddPIC(std::string name, std::string className)
{
    for (unsigned int id = 0 ; id < pics.size(); id++)
    {
        bool success = true;//id‚ª”í‚Á‚Ä–³‚¯‚ê‚ÎtrueA”í‚Á‚½‚çfalse
        id++;
        for (auto& itr : pics)
        {
            if (itr->GetId() == id)
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            unique_ptr<Person> temp = make_unique<Person>(id, name, className);
            pics.push_back(move(temp));
            return id;
        }

    }
    if (pics.size() == 0)
    {
        int id = 0;
        unique_ptr<Person> temp = make_unique<Person>(id, name, className);
        pics.push_back(move(temp));
        return id;
    }
    return -1;
}

unsigned int PersonManager::AddPIC(unsigned int id, std::string name, std::string className)
{
    unique_ptr<Person> temp = make_unique<Person>(id, name, className);
    pics.push_back(move(temp));
    return id;
}

void PersonManager::SetName(unsigned int id, std::string _name)
{
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            itr->SetName(_name);
            return;
        }
    }
    cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void PersonManager::SetClass(unsigned int id, std::string _class)
{
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            itr->SetClass(_class);
            return;
        }
    }
    cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void PersonManager::DeletePic(unsigned int id)
{
    pics.remove_if([=](auto& itr) {return itr->GetId() == id; });
}
