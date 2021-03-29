#include "speciesEldritchHorror.h"
#include <string>

using namespace std;

speciesEldritchHorror::speciesEldritchHorror(string name, int life, int strength, int intelligence, int traumtism)
{
    this->name =name;
    this->life =life;
    this->strength =strength;
    this->intelligence = intelligence;
    this->natural = false;
    this->disquiet = 10;
    this->traumtism = traumtism;

}

speciesEldritchHorror::speciesEldritchHorror() : speciesEldritchHorror("N'Zoth", 4, 4, 4, 1){};


ostream& operator<<(ostream& out, const speciesEldritchHorror seh)
{
    out << seh.name << endl;
    out << "\t Eldritch Horror " << endl;
    out << "\t Life: " << seh.life << endl;
    out << "\t Strength: " << seh.strength << endl;
    out << "\t Intelligence: " << seh.intelligence << endl;
    out << "\t Disquiet: " <<  seh.disquiet << endl;
    out << "\t Unnatural " << endl;
    out << "\t Traumatism: " << seh.traumtism << endl;
    return out;
}

void speciesEldritchHorror::printInfo()
{
    cout << this->name << endl;
}

string speciesEldritchHorror::getName()
{
    return this->name;
}

int speciesEldritchHorror::getLife()
{
    return this->life;
}

int speciesEldritchHorror:: getStrength()
{
    return this->strength;
}

int speciesEldritchHorror::getIntelligence()
{
    return this->intelligence;
}

int speciesEldritchHorror::getDisquiet()
{
    return this->disquiet;
}

int speciesEldritchHorror::getTraumatism()
{
    return this->traumtism;
}

bool speciesEldritchHorror:: getNature()
{
    return false;
}