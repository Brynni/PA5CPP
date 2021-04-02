#include "creature.h"

using namespace std;


Creature::Creature(string name, int life, int strength, int intelligence, int dex, int con, int wis, int cha, bool natural, int disquiet) : Being(name, life, strength, intelligence, dex, con, wis, cha)
{
    this->name = name;
    this->natural = natural;
    this->disquiet = disquiet;
};


// Calls the constructor above
Creature::Creature() : Creature("animal" , 5, 5, 5, 5, 5, 5, 5, true, 5){};

ostream& operator<<(ostream& out, const Creature c)
{
    out << "Creature: " << c.name << endl;
    out << "Life: " << c.life << endl;
    out << "Current hitpoints are: " << c.currentLife << endl;
    out << "Strength: " << c.strength << endl;
    out << "Intelligence: " << c.intelligence << endl;
    out << "Dexterity: " << c.dexterity << endl;
    out << "Constitution: " << c.constitution << endl;
    out << "Wisdom: " << c.wisdom << endl;
    out << "Charisma: " << c.charisma << endl;
    if(c.natural)
    {
        out << "Natural: True" << endl;
    }

    else
    {
        out << "Natural: False" << endl;
    }
    out << "Disquiet: " << c.disquiet;
    return out;
}

void Creature::printInfo()
{
    cout << this->name << endl;
}


void Creature::updateDisquiet()
{
    int newDisq;
    cout << "Enter new disquiet: ";
    cin >> newDisq;
    while(newDisq > 10 || newDisq < 0)
    {
        cout << "Please enter a valid Disquiet, the range is 0 -10" << endl;
        cin >> newDisq;
    }
    disquiet=newDisq;
}
    
void Creature::updateNature()
{
    natural = !natural;
}

bool Creature::getNature()
{
    return this->natural;
}

int Creature::getDisquiet()
{
    return this->disquiet;
}