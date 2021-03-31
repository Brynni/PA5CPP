#ifndef SPELL_123321
#define SPELL_123321
#include <iostream>

using namespace std;

class Spell
{
    public:
        Spell(string name, string description, int level, int roll);

        friend ostream& operator << (ostream & out, const Spell s);
        string getName();
        string getDescription();
        int getLevel();
        int rollDice();

        string name;
        string description;
        int level; 
        int roll;
};




#endif