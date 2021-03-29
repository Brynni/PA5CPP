#include "role.h"
#include "vector"
#include <random>
#include <chrono>
#include "person.h"
#include <string>

using namespace std;

Role::Role(string roleName ,int lifeMin, int lifeMax, int strengthMin, 
int strengthMax, int intelligenceMin, int intelligenceMax)
{
    this->roleName = roleName;
    this->lifeMax =lifeMax;
    this->lifeMin =lifeMin;
    this->strengthMax =strengthMax;
    this->strengthMin =strengthMin;
    this->intelligenceMax = intelligenceMax;
    this->intelligenceMin = intelligenceMin;
    this->fear = 0;
    this->terror = 0;

}

Role::Role() : Role("Default", 0, 10, 0,10,0,10){};

Role Role::generateNewRole()
{
    return Role(roleName ,lifeMax, lifeMin, strengthMin, 
                    strengthMax, intelligenceMax, intelligenceMin);
};

void Role::printInfo()
{
    cout << this->roleName << endl;
}

int Role::getFear()
{
    return this->fear;
}

int Role::getTerror()
{
    return this->terror;
}



string Role::getName()
{
    return this->roleName;
}

int Role::generateHealth()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (lifeMax - lifeMin + 1);
    return randNum + lifeMin;
}

int Role::generateStrength()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (strengthMax - strengthMin + 1);
    return  randNum + strengthMin;
}

int Role::generateIntelligence()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (intelligenceMax - intelligenceMin + 1);
    return randNum + intelligenceMin;
}


ostream& operator<<(ostream& out, const Role r)
{
    out << r.roleName << endl;
    out << "\t Person " << endl;
    out << "\t Life is between " << r.lifeMin << " and "<< r.lifeMax << endl;
    out << "\t Strength is between " << r.strengthMin << " and " << r.strengthMax << endl;
    out << "\t Intelligence is between " << r.intelligenceMin << " and " << r.intelligenceMax << endl;
    out << "\t Fear and terror are both default 0" << endl;
    return out;
}