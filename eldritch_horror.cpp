#include <iostream>
#include "eldritch_horror.h"

using namespace std;

EldritchHorror::EldritchHorror(int life, int strength, int intelligence, int traumatism) : Creature("bla", life, strength, intelligence, 0, 0, 0, 0, false, 10)
{
    this->traumatism = traumatism;
};


EldritchHorror::EldritchHorror() : EldritchHorror(5, 5, 5, 2){};

ostream& operator<<(ostream& out, const EldritchHorror eh)
{
    out << "Eldritch Horror\n";
    out << "Life: " << eh.life << endl;
    out << "Strength: " << eh.strength << endl;
    out << "Intelligence: " << eh.intelligence << endl;
    out << "Natural: False" << endl;
    out << "Disquiet: " << eh.disquiet << endl;
    out << "Traumtism: " << eh.traumatism << endl;
    return out;
}

void EldritchHorror:: updateLife(){
    int newLife;
    cout << "Enter new life: " << endl;
    cin >> newLife;
    while (newLife > 10 || newLife < 0)
    {
        cout << "Enter a valid life the range is 0 - 10" << endl;
        cout << "Enter new life: " << endl;
        cin >> newLife;
    }
    this->life = newLife;
}


void EldritchHorror:: updateStrength()
{
    int newStr;
    cout << "Enter new Strength: " << endl;
    cin >> newStr;
    while (newStr > 10 || newStr < 0)
    {
        cout << "Enter a valid Strength the range is 0 - 10" << endl;
        cout << "Enter new strength: " << newStr;
        cin >> newStr;
    }
    this->strength = newStr;
}

void EldritchHorror:: updateInt()
{
    int newInt;
    cout << "Enter new Intelligence: " << endl;
    cin >> newInt;
    while (newInt > 10 || newInt < 0)
    {
        cout << "Enter a valid Intelligence the range is 0 - 10" << endl;
        cout << "Enter new Intelligence: " << newInt;
        cin >> newInt;
    }
    this->intelligence = newInt;
}


void EldritchHorror:: updateTrauma()
{
    int newTrauma;
    cout << "Enter new Traumatism: " << endl;
    cin >> newTrauma;
    while (newTrauma > 3 || newTrauma < 0)
    {
        cout << "Enter a valid Traumatism the range is 0 - 3" << endl;
        cout << "Enter new Traumatism: " << newTrauma;
        cin >> newTrauma;
    }
    this->traumatism = newTrauma;

}

int EldritchHorror::getTraumatism()
{
    return this->traumatism;
}