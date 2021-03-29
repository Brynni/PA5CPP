#include "speciesCreature.h"

using namespace std;

speciesCreature::speciesCreature(string name, int life, int strength, int intelligence,
bool natural, int disquiet)
{
    this->name =name;
    this->life =life;
    this->strength =strength;
    this->intelligence = intelligence;
    this->natural = natural;
    this->disquiet = disquiet;

}

speciesCreature::speciesCreature() : speciesCreature("Default", 5, 5, 5, true, 5){};



void speciesCreature::printInfo()
{
    cout << this->name << endl;
}

ostream& operator<<(ostream& out, const speciesCreature sc)
{
    out << sc.name << endl;
    out << "\t Creature " << endl;
    out << "\t Life: " << sc.life << endl;
    out << "\t Strength: " << sc.strength << endl;
    out << "\t Intelligence: " << sc.intelligence << endl;
    out << "\t Disquiet: " <<  sc.disquiet << endl;
    if (sc.natural)
    {
        out << "\t Natural" << endl;
    }
    else
    {
        out << "\t Unnatural " << endl;
    }
    return out;
}

string speciesCreature::getName()
{
    return this->name;
}

int speciesCreature::getLife()
{
    return this->life;
}

int speciesCreature::getStrength()
{
    return this->strength;
}

int speciesCreature::getInt()
{
    return this->intelligence;
}

int speciesCreature::getDisquiet()
{
    return this->disquiet;
}

bool speciesCreature::getNature()
{
    return this->natural;
}
