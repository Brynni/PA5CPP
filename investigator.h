#ifndef INVESTIGATOR_12314123
#define INVESTIGATOR_12314123

#include <iostream>
#include "person.h"
#include <string>

class Investigator :public Person
{
    public:
        Investigator();
        Investigator(string name, int life, int strength, int intelligence, string gender, int fear, int terror);
        friend ostream& operator <<(ostream& out, const Investigator i);
        void updateTerror();
        int getTerror();
        int terror;
};


#endif

