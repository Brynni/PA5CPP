#ifndef ELDRITCHHORROR_12314123
#define ELDRITCHHORROR_12314123
#include <iostream>
#include "creature.h"

class EldritchHorror : public Creature
{
    public:
        EldritchHorror();
        EldritchHorror(int life, int strength, int intelligence, int traumtism);
        friend ostream& operator<<(ostream& out, const EldritchHorror eh);
        void updateLife();
        void updateStrength();
        void updateInt();
        void updateTrauma();
        int getTraumatism();
    protected:
        int traumatism;

};

#endif