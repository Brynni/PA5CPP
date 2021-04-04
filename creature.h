#ifndef CREATURE_12314123
#define CREATURE_12314123
#include <iostream>
#include "being.h"
#include <vector>
using namespace std;

class Creature : public Being
{
    public:
        Creature();
        Creature(string name, int life, int strength, int intelligence, int dex, int con, int wis, int cha, bool natural, int disquiet, string type);
        friend ostream& operator<<(ostream& out, const Creature c);
        //void updateLife(Creature& cre);
        void updateDisquiet();
        void updateNature();
        void printInfo();
        int getDisquiet();
        string getType();
        bool getNature();

    protected:
        string name;
        string type;
        bool natural;
        int disquiet;

};

Creature createCreature(Creature sp);
void seeAllCreatures(vector<Creature> creatures);
void seeDetailCreatures(vector<Creature> creatures);
Creature createCustomCreature();
Creature selectCreature(vector<Creature> creatures);
Creature selectCreatureWithType(vector<Creature> creatures, string type);
vector<Creature> seeAllCreaturesOfType(vector<Creature> creatures, string type);
int countAllCreaturesOfType(vector<Creature> creatures, string type);
Creature selectCreatureWithName(vector<Creature> creatures, string name);

#endif