#ifndef CREATURE_12314123
#define CREATURE_12314123
#include <iostream>
#include "being.h"
using namespace std;

class Creature : public Being
{
    public:
        Creature();
        Creature(int life, int strength, int intelligence, bool natural, int disquiet);
        friend ostream& operator<<(ostream& out, const Creature c);
        //void updateLife(Creature& cre);
        void updateStrength();
        void updateDisquiet();
        void updateIntelligence();
        void updateNature();
        int getLife();
        int getStrength();
        int getDisquiet();
        int getIntelligence();
        bool getNature();
    protected:
        bool natural;
        int disquiet;

};

#endif