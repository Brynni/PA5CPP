#include <iostream>
#include "investigator.h"
#include <string>

using namespace std;

Investigator::Investigator(string name, int life, int strength, int intelligence, string gender, int fear, int terror) : Person(name,life,strength,intelligence,gender,fear)
{
    this->terror = terror;
}

Investigator::Investigator() : Investigator("James Bond", 5, 5, 5, "Male", 5, 1) {};


void Investigator::updateTerror()
{
    int newTerror;
    cout << "Current terror is: " << this->terror << endl;
    cout << "Enter new terror: ";
    cin >>newTerror;

    while (newTerror > 3 || newTerror < 0)
    {
        cout << "Invalid value for terror the range is 0-3" << endl;
        cout << "Enter new terror: ";
        cin >>newTerror;
    }

    this->terror = terror;
}

int Investigator::getTerror()
{
    return this->terror;
}


ostream& operator <<(ostream& out, const Investigator i)
{
    out << "Investigator" << endl;
    out << "Name : " << i.name << endl;
    out << "Gender: " << i.gender << endl;
    out << "Life: " << i.life << endl;
    out << "Strength: " << i.strength << endl;
    out << "Intelligence: " << i.intelligence << endl;
    out << "Fear: " << i.fear << endl;
    out << "Terror: " << i.terror << endl;
    out << endl;
    return out;
}

