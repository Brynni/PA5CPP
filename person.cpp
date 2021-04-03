#include <iostream>
#include "person.h"
#include "role.h"
using namespace std;

Person::Person(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma, string gender, int fear) : Being(name ,life, strength, intelligence, constitution, dexterity, wisdom, charisma)
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
    out << "Current life: " << p.currentLife << endl;
    out << "Strength: " << p.strength << endl;
    out << "Intelligence: " << p.intelligence << endl;
    out << "Dexterity: " << p.dexterity << endl;
    out << "Constitution: " << p.constitution << endl;
    out << "Wisdom: " << p.wisdom << endl;
    out << "Charisma: " << p.charisma << endl;
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

void Person:: updateCurrentLife(int newLifeStat)
{
    this->currentLife = newLifeStat;
};

Person createCustomPerson()
{
    string name;
    int life;
    int strength;
    int intelligence;
    int dex, con, wis, cha;
    string gender;
    int fear;
    int terror;

    
    cout << endl;

    cout << "Enter name: "; 
    //Clear the input buffer before hand
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;

    cout << "Enter life for Person: " <<  endl;
    cin >> life;
    while (life < 0 || life > 10)
    {
        cout << "Invalid value for life - the range is 0 - 10" << endl;
        cout << "Enter life for Person: " <<  endl;
        cin >> life;
        cout << endl;
    }   
    cout << "Enter strength for Person: " <<  endl;
    cin >> strength;
    while (strength < 0 || strength > 10)
    {
        cout << "Invalid value for Person - the range is 0 - 10" << endl;
        cout << "Enter life for Person: " <<  endl;
        cin >> strength;
        cout << endl;
    }   
    cout << "Enter Intelligence for Person: " <<  endl;
    cin >> intelligence;
    while (intelligence < 0 || intelligence > 10)
    {
        cout << "Invalid value for Person - the range is 0 - 10" << endl;
        cout << "Enter life for Person: " <<  endl;
        cin >> intelligence;
        cout << endl;
    }

    
        cout << endl;
    cout << "Enter dexterity for person: " <<  endl;
    cin >> dex;
    while (dex < 0 || dex > 30)
    {
        cout << "Invalid range! dexterity must be between 0-30" << endl; 
        cout << "Enter dexterity for person: " <<  endl;
        cin >> dex;
    }

    cout << endl;
    cout << "Enter constituion for person: " <<  endl;
    cin >> con;
    while (con < 0 || con > 30)
    {
        cout << "Invalid range! constituion must be between 0-30" << endl; 
        cout << "Enter constituion for person: " <<  endl;
        cin >> con;
    }

    cout << endl;
    cout << "Enter wisdom for person: " <<  endl;
    cin >> wis;
    while (wis < 0 || wis > 30)
    {
        cout << "Invalid range! wisdom must be between 0-30" << endl; 
        cout << "Enter wisdom for person: " <<  endl;
        cin >> wis;
    }

    cout << endl;
    cout << "Enter charisma for person: " <<  endl;
    cin >> cha;
    while (cha < 0 || cha > 30)
    {
        cout << "Invalid range! Charisma must be between 0-30" << endl; 
        cout << "Enter charisma for person: " <<  endl;
        cin >> cha;
    }

    cout << "Enter name for Person: ";
    cin   >> name;
    cout << endl;

    cout <<"Enter gender for Person: ";
    std::getline(std::cin, gender);

    cout << "Enter fear for Person: " <<  endl;
    cin >> fear;
    while (fear < 0 || fear > 10)
    {
        cout << "Invalid value for fear - the range is 0 - 10" << endl;
        cout << "Enter fear for Person: " <<  endl;
        cin >> fear;
        cout << endl;
    }


    Person p = Person(name, life, strength, intelligence, dex, con, wis, cha, gender, fear);
    return p;

}
