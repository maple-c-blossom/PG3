#include "PICManager.h"
using namespace std;
PICManager* PICManager::GetInstance()
{
    static PICManager instance;
    return &instance;
}

PIC* PICManager::GetPicPtr(unsigned int id)
{
    PIC* ptr;
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            ptr = itr.get();
            return ptr;
        }
    }
    return nullptr;
}

unsigned int PICManager::AddPIC(std::string name, std::string className)
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
            unique_ptr<PIC> temp = make_unique<PIC>(id, name, className);
            pics.push_back(move(temp));
            return id;
        }

    }
    return -1;
}

void PICManager::SetName(unsigned int id, std::string _name)
{
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            itr->SetName(_name);
            return;
        }
    }
}

void PICManager::SetClass(unsigned int id, std::string _class)
{
    for (auto& itr : pics)
    {
        if (itr->GetId() == id)
        {
            itr->SetClass(_class);
            return;
        }
    }
}

bool PICManager::DeletePic(unsigned int id)
{
    pics.remove_if([=](auto& itr) {return itr->GetId() == id; });
}
