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

Creature createCreature(Creature sp)
{
    Creature c = Creature(sp.getName(), sp.getLife(),sp.getStrength(), sp.getInt(), sp.getDex(), sp.getCon(), sp.getWis(), sp.getCha(), sp.getNature(), sp.getDisquiet());
    return c;

};

void seeAllCreatures(vector<Creature> creatures)
{
    cout << "Species of type creature: " << endl;
    int counter = 0;
    for (Creature sp : creatures )
        {   
            counter ++;
            cout << counter << ". "; 
            sp.printInfo();
        }
};

void seeDetailCreatures(vector<Creature> creatures)
{
    for(Creature sp: creatures)
    {
        cout << sp << endl;
    }
};

Creature createCustomCreature()
{
    int life, intelligence, natureChoice, strength, disquiet;
    bool nature;
    string name;
    int dex, con, wis, cha;

    cout << endl;
    cout << "Enter life for creature: " <<  endl;
    cin >> life;
    while (life < 0 || life > 10)
    {
        cout << "Invalid value for life - the range is 0 - 10" << endl;
        cout << "Enter life for creature: " <<  endl;
        cin >> life;
        cout << endl;
    }   
    cout << "Enter strength for creature: " <<  endl;
    cin >> strength;
    while (strength < 0 || strength > 10)
    {
        cout << "Invalid value for strength - the range is 0 - 10" << endl;
        cout << "Enter life for strength: " <<  endl;
        cin >> strength;
        cout << endl;
    }   
    cout << "Enter Intelligence for creature: " <<  endl;
    cin >> intelligence;
    while (intelligence < 0 || intelligence > 10)
    {
        cout << "Invalid value for intelligence - the range is 0 - 10" << endl;
        cout << "Enter life for intelligence: " <<  endl;
        cin >> intelligence;
        cout << endl;
    }   

        cout << endl;
    cout << "Enter dexterity for creature: " <<  endl;
    cin >> dex;
    while (dex < 0 || dex > 30)
    {
        cout << "Invalid range! dexterity must be between 0-30" << endl; 
        cout << "Enter dexterity for creature: " <<  endl;
        cin >> dex;
    }

    cout << endl;
    cout << "Enter constituion for creature: " <<  endl;
    cin >> con;
    while (con < 0 || con > 30)
    {
        cout << "Invalid range! constituion must be between 0-30" << endl; 
        cout << "Enter constituion for creature: " <<  endl;
        cin >> con;
    }

    cout << endl;
    cout << "Enter wisdom for creature: " <<  endl;
    cin >> wis;
    while (wis < 0 || wis > 30)
    {
        cout << "Invalid range! wisdom must be between 0-30" << endl; 
        cout << "Enter wisdom for creature: " <<  endl;
        cin >> wis;
    }

    cout << endl;
    cout << "Enter charisma for creature: " <<  endl;
    cin >> cha;
    while (cha < 0 || cha > 30)
    {
        cout << "Invalid range! Charisma must be between 0-30" << endl; 
        cout << "Enter charisma for creature: " <<  endl;
        cin >> cha;
    }

    cout << "Enter Nature choice for creature: " <<  endl;
    cout << "1. Natural" << endl;
    cout << "2. Unnatural" << endl;
    cin >> natureChoice;
    while (natureChoice < 1 || natureChoice > 2)
    {
        cout << "Enter Nature choice for creature: " <<  endl;
        cout << "1. Natural" << endl;
        cout << "2. Unnatural" << endl;
        cin >> natureChoice;
        cout << endl;
    }   
    cout << "Enter disquiet for creature: " <<  endl;
    cin >> disquiet;
    while (disquiet < 0 || disquiet > 10)
    {
        cout << "Invalid value for disquiet - the range is 0 - 10" << endl;
        cout << "Enter disquiet for creature: " <<  endl;
        cin >> disquiet;
        cout << endl;
    };
    Creature beast = Creature(name ,life, strength, intelligence, dex, con, wis, cha, nature, disquiet);  
        return beast;
}

Creature selectCreature(vector<Creature> creatures)
{
    seeAllCreatures(creatures);
    int selection;
    cout << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    while (selection < 1 || selection > creatures.size())
    {
        cout << "Invalid selection! You must select a creature between 1 and " << creatures.size() << endl; 
        cout << "Enter your selection: ";
        cin >> selection;
    }


    return creatures[selection -1];
    
}