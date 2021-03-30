#include "role.h"
#include "vector"
#include <random>
#include <chrono>
#include "person.h"
#include <string>

using namespace std;

Role::Role(string roleName ,int lifeMin, int lifeMax, int strengthMin, 
int strengthMax, int intelligenceMin, int intelligenceMax,
int dexMin, int dexMax, int wisMin, int wisMax, int conMin, int conMax, int chaMin, int chaMax)
{
    this->roleName = roleName;
    this->lifeMax =lifeMax;
    this->lifeMin =lifeMin;
    this->strengthMax =strengthMax;
    this->strengthMin =strengthMin;
    this->intelligenceMax = intelligenceMax;
    this->intelligenceMin = intelligenceMin;
    this->dexMax = dexMax;
    this->dexMin = dexMin;
    this->wisMax = wisMax;
    this->wisMin = wisMin;
    this->conMax = conMax;
    this->conMin = conMin;
    this->chaMax = chaMax;
    this->chaMin = chaMin;
    this->fear = 0;
    this->terror = 0;

}

Role::Role() : Role("Default", 3, 18, 3,18,3,18,3,18,3,18,3,18,3,18){};

Role Role::generateNewRole()
{
    return Role(roleName ,lifeMax, lifeMin, strengthMin, 
                    strengthMax, intelligenceMax, intelligenceMin,
                    dexMin, dexMax, wisMin, wisMax, 
                    conMin, conMax, chaMin, chaMax);
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

int Role::generateDex()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (dexMax - dexMin + 1);
    return randNum + dexMin;
}

int Role::generateWis()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (wisMax - wisMin + 1);
    return randNum + wisMin;
}

int Role::generateCon()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (conMax - conMin + 1);
    return randNum + conMin;
}

int Role::generateCha()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % (chaMax - chaMin + 1);
    return randNum + chaMin;
}


ostream& operator<<(ostream& out, const Role r)
{
    out << r.roleName << endl;
    out << "\t Person " << endl;
    out << "\t Life is between " << r.lifeMin << " and "<< r.lifeMax << endl;
    out << "\t Strength is between " << r.strengthMin << " and " << r.strengthMax << endl;
    out << "\t Intelligence is between " << r.intelligenceMin << " and " << r.intelligenceMax << endl;
    out << "\t Dexterity is between " << r.dexMin << " and "<< r.dexMax << endl;
    out << "\t Wisdom is between " << r.wisMin << " and "<< r.wisMax << endl;
    out << "\t Constitution is between " << r.conMin << " and "<< r.conMax << endl;
    out << "\t Charisma is between " << r.chaMin << " and "<< r.chaMax << endl;
    out << "\t Fear and terror are both default 0" << endl;
    return out;
}