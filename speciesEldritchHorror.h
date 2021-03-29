#ifndef SPECIESELDRITCHORROR_123456
#define SPECIESELDRITCHORROR_123456


#include <iostream>
#include "eldritch_horror.h"
#include "string"
#include <vector>
using namespace std;


class speciesEldritchHorror
{
    public:
        speciesEldritchHorror(string name, int life, int strength, int intelligence, int traumtism);
        speciesEldritchHorror();
        friend ostream& operator<<(ostream& out, const speciesEldritchHorror seh);
        void generateHorror();
        void printInfo();
        string getName();
        int getLife();
        int getStrength();
        int getIntelligence();
        int getDisquiet();
        bool getNature();
        int getTraumatism();

    protected:
        string name;
        int life;
        int strength;
        int intelligence;
        bool natural;
        int disquiet;
        int traumtism;
};

#endif