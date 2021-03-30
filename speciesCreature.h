#ifndef SPECIESCREATURE_12341155555
#define SPECIESCREATURE_12341155555


#include <iostream>
#include "creature.h"
#include "string"
#include <random>
#include <vector>
using namespace std;


class speciesCreature
{
    public:
        speciesCreature(string name, int life, int strength, int intelligence, bool natural, int disquiet);
        friend ostream& operator<<(ostream& out, const speciesCreature sc);
        void printInfo();
        string getName();
        speciesCreature();

        int getLife();
        int getStrength();
        int getInt();
        bool getNature();
        int getDisquiet();



    protected:
        string name;
        int life;
        int strength;
        int intelligence;
        bool natural;
        int disquiet;
};

#endif