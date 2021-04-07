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
        Creature(const string& name, int life, int strength, int intelligence, int dex, int con, int wis, int cha, bool natural, int disquiet, const string & type);
        friend ostream& operator<<(ostream& out, const Creature &c);
        //void updateLife(Creature& cre);
        void updateDisquiet();
        void updateNature();
        void printInfo();
        void seeDetailCreatures(vector<Creature> creatures);
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
void seeAllCreatures(const vector<Creature>& creatures);
void seeDetailCreatures(vector<Creature> creatures);
Creature createCustomCreature();
Creature selectCreature(const vector<Creature> &creatures);
Creature selectCreatureWithType(const vector<Creature>& creatures, const string& type);
vector<Creature> seeAllCreaturesOfType(const vector<Creature>& creatures, const string& type);
int countAllCreaturesOfType(const vector<Creature> & creatures, const string & type);
Creature selectCreatureWithName(const vector<Creature> &creatures, const string & name);

#endif