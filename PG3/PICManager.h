#pragma once
#include "PIC.h"
#include <list>
#include <memory>
class PICManager
{
private:
	PICManager() {};
	~PICManager() {};
	std::list<std::unique_ptr<PIC>> pics;
public:
    PICManager(const PICManager& manager) = delete;
    PICManager& operator= (const PICManager& manager) = delete;
    static PICManager* GetInstance();
    PIC* GetPicPtr(unsigned int id);
    unsigned int AddPIC(std::string name, std::string className);
    void SetName(unsigned int id, std::string _name);
    void SetClass(unsigned int id, std::string _class);
    bool DeletePic(unsigned int id);
};

