#ifndef PERSON_12314123
#define PERSON_12314123

#include <iostream>
#include "being.h"
#include "role.h"
#include <string>
using namespace std;

class Person : public Being
{
    public:
        Person();
        Person(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma, string gender, int fear);
        friend ostream& operator<<(ostream& out, const Person p);
        void updateGender();
        void updateFear();
        void updateName();
        int getFear();
        void updateCurrentLife(int newLifeStat);
        string getGender();
        

    protected:
        string name;
        string gender;
        int fear;
        
};

#endif