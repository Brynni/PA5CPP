#include "creature.h"

using namespace std;


Creature::Creature(string name, int life, int strength, int intelligence, int dex, int con, int wis, int cha, bool natural, int disquiet) : Being(life, strength, intelligence, dex, con, wis, cha)
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
// void Creature::updateLife(Creature& cre){
//     int newLife;
//     cout << "Enter new life: " ;
//     cin >> newLife;

//     while(newLife > 10 || newLife < 0)
//     {
//         cout << "Please enter a valid life, the range is 0 -10" << endl;
//         cin >> newLife;
//     }
//     cre.life = newLife;
// }
bool Creature::getNature()
{
    return this->natural;
}

void Creature::updateStrength()
{
    int newStr;
    cout << "Enter new strength: ";
    cin  >> newStr;
     while(newStr > 10 || newStr < 0)
    {
        cout << "Please enter a valid Strength, the range is 0 -10" << endl;
        cin >> newStr;
    }
    strength = newStr;   
}

void Creature::updateIntelligence()
{
    int newInt;
    cout << "Enter new intelligence: ";
    cin >> newInt;
    while(newInt > 10 || newInt < 0)
    {
        cout << "Please enter a valid Intelligence, the range is 0 -10" << endl;
        cin >> newInt;
    }
    intelligence = newInt;  
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

int Creature::getLife()
{
    return this->life;
}

int Creature::getStrength()
{
    return this->strength;
}

int Creature::getIntelligence()
{
    return this->intelligence;
}

int Creature::getDisquiet()
{
    return this->disquiet;
}