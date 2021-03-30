#include <iostream>
#include "person.h"
#include "role.h"
using namespace std;

Person::Person(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma, string gender, int fear) : Being(life, strength, intelligence, constitution, dexterity, wisdom, charisma)
{
    this->name = name;
    this->fear = fear;
    this->gender = gender;
};

// empty constructor just calls the other constructor with randomized or default values
Person::Person() {};

ostream& operator<<(ostream& out, const Person p)
{
    out << "Person\n";
    out << "Name: " << p.name << endl;
    out << "Life: " << p.life << endl;
    out << "Strength: " << p.strength << endl;
    out << "Intelligence: " << p.intelligence << endl;
    out << "Gender: " << p.gender << endl;
    out << "Fear: " << p.fear << endl;
    return out;
}

void Person::updateFear()
{
    int newFear;
    cout << "Enter new Fear: " << endl;
    cin >> newFear;
    while (newFear > 10 || newFear < 0)
    {
        cout << "Enter a valid Fear the range is 0 - 10" << endl;
        cout << "Enter new Fear: " << newFear;
        cin >> newFear;
    }
    this->fear = newFear;
}

void Person:: updateGender()
{
    string newGender;
    cout << "Enter new Gender: ";
    cin >> newGender;
    this->gender = newGender;
}

string Person:: getGender()
{
    return this->gender;
}

int Person::getFear()
{
    return this->fear;
}
        
void Person:: updateName()
{
    string newName;
    cout << "Current name is: " << this->name << endl;
    cout << "Enter new name: ";
    cin >> newName;
    this->name = newName;
}

string Person:: getName()
{
    return this->name;
}
