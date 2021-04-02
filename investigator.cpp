#include <iostream>
#include "investigator.h"
#include <string>

using namespace std;

Investigator::Investigator(string name, int life, int strength, int intelligence, int dexterity, int constitution, int wisdom, int charisma, string gender, int fear, int terror) : Person(name,life,strength,intelligence,dexterity,constitution,wisdom,charisma,gender,fear)
{
    this->terror = terror;
}

Investigator::Investigator() : Investigator("Warrior man", 9, 15, 12, 13, 14, 10, 8, "Male", 5, 1) {};


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
    out << "Current life: " << i.currentLife << endl;
    out << "Strength: " << i.strength << endl;
    out << "Intelligence: " << i.intelligence << endl;
    out << "Dexterity: " << i.dexterity << endl;
    out << "Constitution: " << i.constitution << endl;
    out << "Wisdom: " << i.wisdom << endl;
    out << "Charisma: " << i.charisma << endl;
    out << "Fear: " << i.fear << endl;
    out << "Terror: " << i.terror << endl;
    out << endl;
    return out;
}

void Investigator::printCharacter(){
    cout << "ACROBATICS " << floor((dexterity-10)/2) << endl;
    cout << "ANIMAL HANDLING " << floor((wisdom-10)/2) << endl;
    cout << "ARCANA " << floor((intelligence-10)/2)  << endl;
    cout << "ATHLETICS " << floor((strength-10)/2) << endl;
    cout << "DECEPTION "<< floor((charisma-10)/2) << endl;
    cout <<"HISTORY "<< floor((intelligence-10)/2) << endl;
    cout <<"INSIGHT "<<floor((wisdom-10)/2) << endl;
    cout <<"INTIMIDATION "<< floor((charisma-10)/2) << endl;
    cout <<"INVESTIGATION " <<floor((intelligence-10)/2)  << endl;
    cout <<"MEDICINE " << floor((wisdom-10)/2)<< endl;
    cout <<"NATURE " <<floor((intelligence-10)/2)  << endl;
    cout <<"PERCEPTION " <<floor((wisdom-10)/2) << endl;
    cout <<"PERFORMANCE " << floor((charisma-10)/2)<< endl;
    cout <<"PERSUASION " << floor((charisma-10)/2)<< endl;
    cout <<"RELIGION " <<floor((intelligence-10)/2)  << endl;
    cout <<"SLEIGHT OF HAND " << floor((dexterity-10)/2) << endl;
    cout <<"STEALH " << floor((dexterity-10)/2) << endl;
    cout <<"SURVIVAL " <<floor((wisdom-10)/2) << endl;
}
