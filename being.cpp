#include "being.h"
#include <random>
#include <iostream>

using namespace std;

Being::Being(int life, int strength, int intelligence)
{
    this->life = life;
    this->strength = strength;
    this->intelligence = intelligence;
};

// Should be replaced with random values from 0-10 
Being::Being() : Being (5,5,5){};


ostream& operator<<(ostream& out, const Being b)
{
    out << "Being\n";
    out << "Life: " << b.life << endl;
    out << "Strength: " << b.strength << endl;
    out << "Intelligence: " << b.intelligence;
    return out;
}

void Being::updateLife()
{
   
    int newLife;
    cout << "Enter new life: " ;
    cin >> newLife;

    while(newLife > 10 || newLife < 0)
    {
        cout << "Please enter a valid life, the range is 0 -10" << endl;
        cin >> newLife;
    }
    this->life = newLife;

}

void Being::updateStrength()
{
   
    int newStrength;
    cout << "Enter new strength: " ;
    cin >> newStrength;

    while(newStrength > 10 || newStrength < 0)
    {
        cout << "Please enter a valid strength, the range is 0 -10" << endl;
        cin >> newStrength;
    }
    this->strength = newStrength;

}

void Being::updateInt()
{
   
    int newInt;
    cout << "Enter new Intelligence : " ;
    cin >> newInt;

    while(newInt > 10 || newInt < 0)
    {
        cout << "Please enter a valid Intelligence, the range is 0 -10" << endl;
        cin >> newInt;
    }
    this->intelligence = newInt;

}



int Being:: getLife()
{
    return this->life;
}

int Being ::getStrength()
{
    return this->strength;
};

int Being::getInt()
{
    return this->intelligence;
}