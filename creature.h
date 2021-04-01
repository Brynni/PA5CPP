#ifndef CREATURE_12314123
#define CREATURE_12314123
#include <iostream>
#include "being.h"
using namespace std;

class Creature : public Being
{
    public:
        Creature();
        Creature(string name, int life, int strength, int intelligence, int dex, int con, int wis, int cha, bool natural, int disquiet);
        friend ostream& operator<<(ostream& out, const Creature c);
        //void updateLife(Creature& cre);
        void updateStrength();
        void updateDisquiet();
        void updateIntelligence();
        void updateNature();
        void printInfo();
        int getDisquiet();
        bool getNature();
    protected:
        string name;
        bool natural;
        int disquiet;

};

#endif