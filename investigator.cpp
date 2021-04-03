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

Investigator createInvestigator(Role role)
{
    string name;
    string gender;
    int terror;
    cout << "Enter name for the investigator: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;
    cout << "Enter gender: " ;
    std::getline(std::cin, gender);
    cout << endl;
    cout << "Enter terror for the investigator: ";
    cin >> terror;
    cout << endl;
    while(terror < 0 || terror > 3)
    {
        cout << "Invalid value for terror, the range is 0-3" << endl;
        cout << "Enter terror for the investigator: ";
        cin >> terror;
        cout << endl;
    }

    Investigator i = Investigator(
        name,
        role.generateHealth(), 
        role.generateStrength(), 
        role.generateIntelligence(), 
        role.generateDex(),
        role.generateWis(),
        role.generateCon(),
        role.generateCha(), 
        gender, 
        role.getFear(),
        terror);
    return i;
}

Investigator createCustomInvestigator()
{

    string name;
    int life;
    int strength;
    int intelligence;
    string gender;
    int fear;
    int terror;

    int wis, dex, con, cha;

     cout << endl;

    cout << "Enter life for Investigator: " <<  endl;
    cin >> life;
    while (life < 0 || life > 10)
    {
        cout << "Invalid value for life - the range is 0 - 10" << endl;
        cout << "Enter life for Investigator: " <<  endl;
        cin >> life;
        cout << endl;
    }   
    cout << "Enter strength for Investigator: " <<  endl;
    cin >> strength;
    while (strength < 0 || strength > 10)
    {
        cout << "Invalid value for Investigator - the range is 0 - 10" << endl;
        cout << "Enter life for Investigator: " <<  endl;
        cin >> strength;
        cout << endl;
    }   
    cout << "Enter Intelligence for Investigator: " <<  endl;
    cin >> intelligence;
    while (intelligence < 0 || intelligence > 10)
    {
        cout << "Invalid value for Investigator - the range is 0 - 10" << endl;
        cout << "Enter life for Investigator: " <<  endl;
        cin >> intelligence;
        cout << endl;
    }

        cout << endl;
    cout << "Enter dexterity for Investigator: " <<  endl;
    cin >> dex;
    while (dex < 0 || dex > 30)
    {
        cout << "Invalid range! dexterity must be between 0-30" << endl; 
        cout << "Enter dexterity for Investigator: " <<  endl;
        cin >> dex;
    }

    cout << endl;
    cout << "Enter constituion for Investigator: " <<  endl;
    cin >> con;
    while (con < 0 || con > 30)
    {
        cout << "Invalid range! constituion must be between 0-30" << endl; 
        cout << "Enter constituion for Investigator: " <<  endl;
        cin >> con;
    }

    cout << endl;
    cout << "Enter wisdom for Investigator: " <<  endl;
    cin >> wis;
    while (wis < 0 || wis > 30)
    {
        cout << "Invalid range! wisdom must be between 0-30" << endl; 
        cout << "Enter wisdom for Investigator: " <<  endl;
        cin >> wis;
    }

    cout << endl;
    cout << "Enter charisma for Investigator: " <<  endl;
    cin >> cha;
    while (cha < 0 || cha > 30)
    {
        cout << "Invalid range! Charisma must be between 0-30" << endl; 
        cout << "Enter charisma for Investigator: " <<  endl;
        cin >> cha;
    }

    cout << "Enter name for Investigator: ";
    cin   >> name;
    cout << endl;

    cout <<"Enter gender for Investigator: ";
    std::getline(std::cin, gender);

    cout << "Enter fear for Investigator: " <<  endl;
    cin >> fear;
    while (fear < 0 || fear > 10)
    {
        cout << "Invalid value for fear - the range is 0 - 10" << endl;
        cout << "Enter fear for Investigator: " <<  endl;
        cin >> fear;
        cout << endl;
    }

    cout << "Enter terror for Investigator: " <<  endl;
    cin >> terror;
    while (terror < 0 || terror > 3)
    {
        cout << "Invalid value for terror - the range is 0 - 3" << endl;
        cout << "Enter terror for Investigator: " <<  endl;
        cin >> terror;
        cout << endl;
    }

    Investigator inv = Investigator(name, life, strength, intelligence, dex, con, wis, cha, gender, fear, terror);
    return inv;     
}