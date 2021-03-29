#ifndef ROLE_12314123
#define ROLE_12314123

#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <chrono>
#include <random>
using namespace std;

class Role
{
    public:
        Role();
        Role(string roleName ,int lifeMax, int lifeMin, int strengthMin, int strengthMax, int intelligenceMin, int intelligenceMax);
        friend ostream& operator<<(ostream& out, const Role r);
        Role generateNewRole();
        string getName();
        void printInfo();
        int generateHealth();
        int generateStrength();
        int generateIntelligence();
        int getFear();
        int getTerror();
        



    protected:
        string roleName;
        int lifeMax;
        int lifeMin;
        int strengthMax;
        int strengthMin;
        int intelligenceMax;
        int intelligenceMin;
        int fear;
        int terror;
};

#endif

