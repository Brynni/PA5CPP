#include "attack.h"
#include "being.h"
#include "dice.h"
#include "fileReader.h"
#include "individuals.h"
#include "investigator.h"
#include "person.h"
#include "speciesCreature.h"
#include "role.h"
#include "weapon.h"

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm> 
#include <vector>


using namespace std;

void initializeBaseDice(vector <Dice> &allDice)
{
    Dice d20( "ICOSAHEDRON", "D20", 20);
    Dice d12( "DODECAHEDRON", "D12", 12);
    Dice d10( "PENTAGONAL TRAPEZOHEDRON", "D10", 10);
    Dice d8( "OCTAHEDRON", "D8", 8);
    Dice d6("CUBE", "D6" , 6);
    Dice d4("TETRAHEDRON", "D4", 4);
    allDice.push_back(d20);
    allDice.push_back(d12);
    allDice.push_back(d10);
    allDice.push_back(d8);
    allDice.push_back(d6);
    allDice.push_back(d4);
}


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
}

void seeDetailCreatures(vector<Creature> creatures)
{
    for(Creature sp: creatures)
    {
        cout << sp << endl;
    }
}

Creature createCreature(Creature sp)
{
    Creature c = Creature(sp.getName(), sp.getLife(),sp.getStrength(), sp.getInt(), sp.getDex(), sp.getCon(), sp.getWis(), sp.getCha(), sp.getNature(), sp.getDisquiet());
    return c;

};

Person createPerson(Role role)
{
    string name;
    string gender;
    cout << "Enter name for the person: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;
    cout << "Enter gender: " ;
    std::getline(std::cin, gender);

    Person p = Person(
        name, 
        role.generateHealth(), 
        role.generateStrength(), 
        role.generateIntelligence(), 
        role.generateDex(),
        role.generateWis(),
        role.generateCon(),
        role.generateCha(), 
        gender, 
        role.getFear());
    return p;
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

void seeAllRoles(vector<Role> roles)
{
    cout << "Roles"  << endl;
    int counter = 0;
    for (Role r : roles)
    {
        counter ++;
        cout << counter << ". " << r.getName() << endl;
    }
}

void seeDetailRoles(vector<Role> roles)
{
    for(Role r : roles)
    {
        cout << r << endl;
    }
};


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

Role selectRole(vector<Role> roles)
{
    seeAllRoles(roles);
    int selection;
    cout << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    while (selection < 1 || selection > roles.size())
    {
        cout << "Invalid selection! You must select a between between 1 and " << roles.size() << endl; 
        cout << "Enter your selection: ";
        cin >> selection;
    }


    return roles[selection -1];
    
}


int getNumberOfRoles(vector<Individuals<Person> > individualsPersons, string name)
{
    int counter = 0;

    for (Individuals<Person> p : individualsPersons)
    {
        if(p.getJob() == name)
        {
            counter ++;
        }
    }
    return counter;
}

int getNumberOfCreatures(vector<Individuals<Creature> >individualsCreatures, string name)
{
    int counter = 0;

     for (Individuals<Creature> cre : individualsCreatures)
     {
        if(cre.getJob() == name)
        {
            counter ++;
        }
    }

    return counter;
}


void printIndividualPersons(vector <Individuals<Person> > individualPersons)
{
    int counter = 0;
    cout << "Printing Individuals of type Person" << endl;
    for (Individuals<Person> p: individualPersons)
    {
        counter ++;
        cout << counter << ". " << p.getName() << " " << p.getCounter() << endl;
        
    }
}

void printIndividualInvestigator(vector <Individuals<Investigator> > investigators)
{
    int counter = 0;
    cout << "Printing Individuals of type investigator" << endl;
    for (Individuals<Investigator> i: investigators)
    {
        counter ++;
        cout << counter << ". " << i.getName() << " " <<  endl;
    }
}


void printIndividualCreature(vector <Individuals<Creature> > individualCreature)
{
    int counter = 0;
    cout << "Printing Individuals of type Creature" << endl;
    for (Individuals<Creature> c: individualCreature)
    {
        counter ++;
        cout << counter << ". " << c.getName()  << " " << c.getCounter() << endl;
    }
}

void printIndividualDice(vector <Dice> allDice)
{
    int counter = 0;
    cout << "Printing all dice" << endl;
    for (Dice d: allDice)
    {
        counter ++;
        cout << counter << ". " << d.getName() <<"("<< d.getNickname() <<")" << " " << d.getSides() << endl;
    }
}

Individuals<Creature> selectIndividualCreature(vector <Individuals<Creature> > individualCreature)
{
    printIndividualCreature(individualCreature);
    cout << endl;
    int selection;
    cout << "Select what creature you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualCreature.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualCreature.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualCreature[selection -1];
}

Individuals<Person> selectIndividualPerson(vector <Individuals<Person> > individualPersons)
{
    printIndividualPersons(individualPersons);
    cout << endl;
    int selection;
    cout << "Select what person you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualPersons.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualPersons.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualPersons[selection -1];
}

Individuals<Investigator> selectIndividualInvestigator(vector <Individuals<Investigator> > investigators)
{
    printIndividualInvestigator(investigators);
    cout << endl;
    int selection;
    cout << "Select what Investigator you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > investigators.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << investigators.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return investigators[selection -1];
}

Dice selectIndividualDice(vector <Dice> allDice)
{
    printIndividualDice(allDice);
    cout << endl;
    int selection;
    cout << "Select what Dice you would like to roll: ";
    cin >> selection;
    while(selection < 1 || selection > allDice.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << allDice.size() << endl;
        cout << "Select what Dice you would like to roll: ";
        cin >> selection;
    }

    return allDice[selection -1];
}

Dice selectIndividualDiceByNickname(vector <Dice> allDice, string nickname)
{
    for (int i = 0; i < allDice.size(); i++)
    {
        if (allDice[i].getNickname() == nickname)
        {
            return allDice[i];
        }
    }
    return Dice();
    
}

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

/* _________________________________*/
//       Main starts here!         //
/* ______________________________ */

int main()
{
    //All vectors pertaining to beings
    vector <Role> roles;
    vector <Creature> creatures;
    vector <Individuals<Investigator>> investigators;
    vector <Individuals<Person> > individualsPersons;
    vector <Individuals<Creature> > IndividualsCreatures;

    //All vectors pertaining to game mechanics
    vector <Dice> allDice;

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    
    //Initialize all the needed data for the game to function
    FileReader myFileReader; 
    myFileReader.ReadRolesFromFile(roles);
    myFileReader.ReadCreaturesFromFile(creatures);
    initializeBaseDice(allDice);
    

    bool playing = true;

    while (playing)
    {
        int user_choice;
        cout << "Your choices are: " << endl;
        cout <<"\t 1. Create Role" << endl;
        cout <<"\t 2. Create Species" << endl;
        cout <<"\t 3. See lists" << endl;
        cout <<"\t 4. Create a new individual " << endl;
        cout <<"\t 5. See list individuals" << endl;
        cout <<"\t 6. Select Individual for editing / deleting / taking damage test" << endl;
        cout <<"\t 7. Remove Individual Type" << endl;
        cout <<"\t 8. Testing area" << endl;
        cout <<"\t 0. quit" << endl;

        cout << "Enter choice here: ";
        cin >> user_choice;
        cout << " " << endl;


        if (user_choice == 1)
        {
            roles.push_back(myFileReader.createRole(roles));
        }

        else if (user_choice == 2)
        {
            int creature_or_horror;
            cout << "Would you like your species to be: \n\t1.Creature\n\t2.Eldritch Horror: ";
            cin >> creature_or_horror;
            if (creature_or_horror != 2)
            {
                creatures.push_back(myFileReader.createSpecies(creatures));
            }
            else
            {
                //TODO look at message below
                cout << "Maybe make it so that we can have different types of animals and this is how they'd be defined" << endl;
            }
        }

        else if (user_choice == 3)
        {   
            int whatList;
            int detailOrCompact;
            cout << "Would you like to see list of: " << endl;
            cout << "1. Species" << endl;
            cout << "2. Horrors" << endl;
            cout << "3. Roles" << endl;
            cout << "Your selection here: ";
            cin >> whatList;
            if (whatList == 1 && creatures.size()>0)
            {
                cout << "Would you like see: " << endl;
                cout << "1. Compact view" << endl;
                cout << "2. Detailed view" << endl;
                cout << "Your choice here: ";
                cin >> detailOrCompact;
                cout << endl;

                if (detailOrCompact == 1)
                {
                    seeAllCreatures(creatures);
                    cout << endl;
                }

                if (detailOrCompact == 2)
                {
                    seeDetailCreatures(creatures);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid selection" << endl;
                }
                
                
            }
            else if(whatList == 1 && creatures.size() == 0)
            {
                cout << "No species of type creature yet added" << endl;
            }

            else if (whatList == 2 )
            {
                //TODO Fix
                cout << "This has been removed" << endl;
            }

            else if(whatList == 3 && roles.size()>0)
            {
                cout << "Would you like see: " << endl;
                cout << "1. Compact view" << endl;
                cout << "2. Detailed view" << endl;
                cout << "Your choice here: ";
                cin >> detailOrCompact;
                cout << endl;

                if (detailOrCompact == 1)
                {
                    seeAllRoles(roles);
                    cout << endl;
                }

                if (detailOrCompact == 2)
                {
                    seeDetailRoles(roles);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid selection" << endl;
                }
            }

            else if(whatList == 3 && roles.size() == 0)
            {
                cout << "No roles added" << endl;
            }

            cout << endl;

        }


        else if (user_choice == 4)
        {
            
            int select_creature_horror_person;
            cout << "Would you like to select\n\t1.Creature\n\t2.Horror\n\t3.Person"<< endl;
            cin >>select_creature_horror_person;
            if(select_creature_horror_person == 1)
            {
                if(creatures.size() > 0)
                {
                    Creature cre = selectCreature(creatures);

                    int basicOrCustom;

                    cout << "Would you like to create a basic or a custom Individual? " << endl;
                    cout << "1. Basic" << endl;
                    cout << "2. Custom" << endl;
                    cin >>basicOrCustom;

                    if (basicOrCustom == 1)
                    {
                        Creature beast = createCreature(cre);
                        int countOfCreatures = getNumberOfCreatures(IndividualsCreatures, cre.getName());
                        string name = cre.getName();
                        Individuals<Creature> t = Individuals<Creature>(name, beast, countOfCreatures +1, cre.getName());
                        IndividualsCreatures.push_back(t);
                        t.printA();
                        cout << endl;

                    }

                    if (basicOrCustom == 2)
                    {
                        string name; 
                        cout << "Enter name for individual: ";
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, name);
                        cout << endl;
                        Creature beast = createCustomCreature();
                        int countOfCreatures = getNumberOfCreatures(IndividualsCreatures, cre.getName());
                        Individuals<Creature> t = Individuals<Creature>(name, beast, countOfCreatures +1, cre.getName());
                        IndividualsCreatures.push_back(t);
                        t.printA();
                        cout << endl;
                    }


                    

                    else if (basicOrCustom != 1 || basicOrCustom !=2) 
                    {
                        cout << "Invalid choice..." << endl;
                    } 
                                   
                }

                else
                {
                    cout << "There are no creatures..." << endl;
                }
            }
            else if (select_creature_horror_person == 2)
            {
                //TODO Remove
                cout << "Nothing to see here, move along" << endl;
            }

            else if (select_creature_horror_person == 3)
            {
                if(roles.size() > 0)
                {
                    int npc_pc;
                    cout <<"Would you like to create: " << endl;
                    cout <<"1. NPC" << endl;
                    cout <<"2. Investigator" << endl;
                    cin >> npc_pc;

                    if(npc_pc == 1)
                    {
                        Role sel_role = selectRole(roles);
                        int basicOrCustom;
                        cout << "Would you like to create a basic or a custom Individual? " << endl;
                        cout << "1. Basic" << endl;
                        cout << "2. Custom" << endl;
                        cin >>basicOrCustom;

                        if (basicOrCustom == 1)
                        {
                            Person human = createPerson(sel_role);
                            int countOfRole = getNumberOfRoles(individualsPersons, sel_role.getName());
                            string name = sel_role.getName();
                            Individuals<Person> t = Individuals<Person>(name, human, countOfRole +1, sel_role.getName());
                            individualsPersons.push_back(t);
                            t.printA();
                            cout << endl;
                        }

                         if (basicOrCustom == 2)
                        {
                            string name;
                            cout << "Enter name for individual: ";
                            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, name);   
                            Person human = createCustomPerson();
                            int countOfRole = getNumberOfRoles(individualsPersons, sel_role.getName());
                            Individuals<Person> t = Individuals<Person>(name, human, countOfRole +1, sel_role.getName());
                            individualsPersons.push_back(t);
                            t.printA();
                            cout << endl;
                        }
                        else if (basicOrCustom != 1 || basicOrCustom !=2) 
                        {
                            cout << "Invalid choice..." << endl;
                        } 
                        
                        
                    }

                    if (npc_pc == 2)
                    {
                        Role sel_role = selectRole(roles);
                        int basicOrCustom;
                        cout << "Would you like to create a basic or a custom Individual? " << endl;
                        cout << "1. Basic" << endl;
                        cout << "2. Custom" << endl;
                        cin >>basicOrCustom;
                        
                        if(basicOrCustom == 1)
                        {
                            
                            Investigator human = createInvestigator(sel_role);
                            int countOfRole = getNumberOfRoles(individualsPersons, sel_role.getName());
                            string name = sel_role.getName();
                            Individuals<Investigator> t = Individuals<Investigator>(name, human, countOfRole +1, sel_role.getName());
                            investigators.push_back(t);
                            t.printA();
                            cout << endl;
                        }

                        if(basicOrCustom == 2)
                        {
                            string name;
                            cout << "Enter name for your individual: ";
                            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, name);
                            Investigator human = createCustomInvestigator();
                            int countOfRole = getNumberOfRoles(individualsPersons, sel_role.getName());
                            Individuals<Investigator> t = Individuals<Investigator>(name, human, countOfRole +1, sel_role.getName());
                            investigators.push_back(t);
                            t.printA();
                            cout << endl;
                        }
                    else if (basicOrCustom != 1 || basicOrCustom !=2) 
                    {
                        cout << "Invalid choice..." << endl;
                    } 

                        
                    }
                    

                }
            }

            else
            {
                cout << "Invalid selection" << endl;
            }

        }

        else if (user_choice == 5)
        {
            int indList;
            cout << "Would you like to see a list of individuals of type: " << endl;
            cout << "1. Person " << endl;
            cout << "2. Creature " << endl;
            cout << "3. Eldritch Horrors " << endl;
            cout << "4. Investigators " << endl;

            cin >> indList;

            if (indList == 1)
            {
                printIndividualPersons(individualsPersons);
            }

            else if (indList == 2)
            {
                printIndividualCreature(IndividualsCreatures);
            }


            else if (indList == 3)
            {
                //TODO Remove
                cout << "Nothing to see here" << endl;
            }

            else if (indList == 4)
            {
                printIndividualInvestigator(investigators);
            }

            else
            {
                cout << "Invalid selection! " << endl;
            }

        }

        else if (user_choice == 6)
        {
            cout << user_choice << endl;
            int whatToEdit;
            cout << "What type of individual would like to edit? " << endl;
            cout << "1. Creature" << endl;
            cout << "2. Person" << endl;
            cout << "3. Eldritch Horror" << endl;
            cout << "4. Investigator" << endl;
            cin >> whatToEdit;

            if (whatToEdit == 1)
            {
                Individuals<Creature> cr = selectIndividualCreature(IndividualsCreatures);
                Creature & cre = cr.getType();
                int editing;
                cr.printA();
                cout << "What would you like to edit? " << endl;
                cout << "1. Life" << endl;
                cout << "2. Strength" << endl;
                cout << "3. Nature" << endl;
                cout << "4. Disquiet " << endl;
                cout << "5. Intelligence " << endl;
                cout << "Your selection: ";

                cin >> editing;

                if (editing == 1)
                {
                   cr.type.updateLife();
                    
                }

                if (editing == 2)
                {
                    cr.type.updateStrength();
                }

                if (editing == 3)
                {
                    
                    cr.type.updateNature();
                    
                }

                if (editing == 4)
                {
                    
                    cr.type.updateDisquiet();
                }

                if (editing == 5)
                {
                    cr.type.updateInt();
                }

                if (editing == 6)
                {
                    cr.type.takeDamage(5);
                }

                else if(editing >0 || editing < 7 )
                {
                    Creature newCre = Creature (cr.type.getName(), cr.type.getLife(), cr.type.getStrength(), cr.type.getInt(), cr.type.getDex(), cr.type.getCon(), cr.type.getWis(), cr.type.getCha(), cr.type.getNature(), cr.type.getDisquiet());
                    string name = cr.getName();
                    string job = cr.getJob();
                    int count = cr.getCounter() - 1;
                    Individuals<Creature> t = Individuals<Creature>(name, newCre, count +1, job);
                    for (int i=0; i<IndividualsCreatures.size();i++)
                    {
                        if (IndividualsCreatures[i].getName() == cr.getName())
                        {
                            IndividualsCreatures.erase(IndividualsCreatures.begin() + i);
                            IndividualsCreatures.push_back(t);
                        }
                    }
                    sort(IndividualsCreatures.begin(), IndividualsCreatures.end());
                }
                else if(editing <= 0 || editing > 5)
                {
                    cout << "Invalid selection" << endl;
                }



            }
            else if (whatToEdit == 2)
            {
                int editing;
                Individuals<Person> p = selectIndividualPerson(individualsPersons);
                cout << "Selected person: " << endl;
                p.printA();
                cout << "What would you like to edit? " << endl;
                cout << "1. Life" << endl;
                cout << "2. Strength" << endl;
                cout << "3. Name" << endl;
                cout << "4. Intelligence " << endl;
                cout << "5. Gender" << endl;
                cout << "6. Fear" << endl;
                cout << "7. Hurt being for 5 points of damage" << endl;
                cout << "Your selection: ";
                cin >> editing;
                cout << endl;

                if (editing == 1)
                {
                    p.type.updateLife();
                }

                if (editing == 2)
                {
                    p.type.updateStrength();
                }

                if (editing == 3)
                {
                    p.type.updateName();
                }

                if (editing == 4)
                {
                    p.type.updateInt();
                }

                if (editing == 5)
                {
                    p.type.updateGender();
                }

                if (editing == 6)
                {
                    p.type.updateFear();
                }

                if (editing == 7)
                {
                    p.type.takeDamage(5);
                }

                else if (editing > 0 && editing < 8)
                {
                    Person newP = Person (p.type.getName(), p.type.getLife(), p.type.getStrength(), p.type.getInt(), p.type.getDex(), p.type.getCon(), p.type.getWis(), p.type.getCha(), p.type.getGender(), p.type.getFear());
                    string name = p.getName();
                    string job = p.getJob();
                    int count = p.getCounter();
                    Individuals<Person> t = Individuals<Person>(name, newP, count, job);
                    for (int i=0; i<individualsPersons.size();i++)
                    {
                        if (individualsPersons[i].getName() == p.getName() && individualsPersons[i].getCounter() == p.getCounter() )
                        {
                        individualsPersons.erase(individualsPersons.begin() + i);
                        individualsPersons.push_back(t);
                        }
                    }
                    cout << "updated Person" << endl;
                    t.printA();
                    
                    cout << endl;
                    sort(individualsPersons.begin(), individualsPersons.end());
                }

                else if (editing < 1 || editing > 8)
                {
                    cout << "Invalid Selection" << endl;
                }

                
            }

            else if(whatToEdit == 3)
            {
            //TODO Remove
                cout << "Nothing to see here" << endl;
            }

            else if(whatToEdit == 4)
            {
                int editing;
                Individuals<Investigator> inv = selectIndividualInvestigator(investigators);
                cout << "Selected investigator: " << endl;
                inv.printA();
                cout << "What would you like to edit? " << endl;
                cout << "1. Life" << endl;
                cout << "2. Strength" << endl;
                cout << "3. Name" << endl;
                cout << "4. Intelligence " << endl;
                cout << "5. Gender" << endl;
                cout << "6. Fear" << endl;
                cout << "7. Terror" << endl;
                cout << "8. Hurt this character for 5 points of damage" << endl;
                cout << "Your selection: ";
                cin >> editing;
                cout << endl;

                if (editing == 1)
                {
                    inv.type.updateLife();
                }

                if (editing == 2)
                {
                    inv.type.updateStrength();
                }

                if (editing == 3)
                {
                    inv.type.updateName();
                }

                if (editing == 4)
                {
                    inv.type.updateInt();
                }

                if (editing == 5)
                {
                    inv.type.updateGender();
                }

                if (editing == 6)
                {
                    inv.type.updateFear();
                }

                if (editing == 7)
                {
                    inv.type.updateTerror();
                }

                if (editing == 8)
                {
                    inv.type.takeDamage(5);
                }

                if (editing > 0 && editing < 9)
                {
                    Investigator newI = Investigator (inv.type.getName(), inv.type.getLife(), inv.type.getStrength(), inv.type.getInt(), inv.type.getDex(), inv.type.getCon(), inv.type.getWis(), inv.type.getCha(),  inv.type.getGender(), inv.type.getFear(), inv.type.getTerror());
                    string name = inv.getName();
                    string job = inv.getJob();
                    int count = inv.getCounter();
                    newI.updateCurrentLife(inv.type.getCurrentLife());
                    newI.printCharacter();
                    Individuals<Investigator> t = Individuals<Investigator>(name, newI, count, job);
                    for (int i=0; i<investigators.size();i++)
                    {
                        if (investigators[i].getName() == inv.getName() && investigators[i].getCounter() == inv.getCounter() )
                        {
                            investigators.erase(investigators.begin() + i);
                            investigators.push_back(t);
                            
                        }
                    }
                    cout << "updated Updated Investigator" << endl;
                    t.printA();
                    cout << endl;
                    sort(investigators.begin(), investigators.end());
                }

                else if (editing < 1 || editing > 8)
                {
                    cout << "Invalid Selection" << endl;
                }
            }
        }

        else if (user_choice == 7)
        {
            
            int select_creature_horror_person;
            cout << "Would you like to select\n\t1.Creature\n\t2.Horror\n\t3.Person"<< endl;
            cin >>select_creature_horror_person;
            if(select_creature_horror_person == 1)
            {
                if(creatures.size() > 0)
                {
                    cout << "Creatures" << endl;
                    //Get the creature
                    Creature cre = selectCreature(creatures);
                    //Send the filename to the remove function and the creature itself
                    myFileReader.RemoveCreatureFromFile(cre, "species.txt");
                    //Remove the creature from the creature vector as per the Occamz razor sollution
                    for (int i = 0; i < creatures.size(); i++)
                    {
                        if (creatures[i].getName() == cre.getName())
                        {
                            creatures.erase (creatures.begin() + i);
                        }
                    }
                    //Success
                    cout << "Creature type has been removed..." << endl;                   
                }

                else
                {
                    cout << "There are no creatures..." << endl;
                }
            }
            else if (select_creature_horror_person == 2)
            {
                //TODO Remove
                cout << "Nothing to see here" << endl;
                
            }

            else if (select_creature_horror_person == 3)
            {
                if(roles.size() > 0)
                {
                    Role sel_role = selectRole(roles);
                    myFileReader.RemovePersonRoleFromFile(sel_role, "roles.txt");
                    //Remove the role from the role vector as per the Occamz razor sollution
                    for (int i = 0; i < roles.size(); i++)
                    {
                        if (roles[i].getName() == sel_role.getName())
                        {
                            roles.erase (roles.begin() + i);
                        }
                    }
                    //Success
                    cout << "Role type has been removed..." << endl;

                }
                
                else
                {

                }
            }

            else
            {
                cout << "Invalid selection" << endl;
            }

        }

        else if (user_choice == 8)
        {
            int select_test;
            cout << "Would you like to select\n\t0.Dice test\n\t1.attack setup test?\n"<< endl;
            cin >>select_test;
            if (select_test == 0){
                Dice selectedDice = selectIndividualDice(allDice);
                cout << "The roll of your selected dice is: " << selectedDice.rollDice() << endl;
            }
            if (select_test == 1){
                // Create an attack vector for unarmed attacks
                vector <Attack> unarmedHumanAttacks;
                Attack punch = Attack();
                unarmedHumanAttacks.push_back(punch);

                vector <Attack> unarmedBeastAttacks;
                Attack bite = Attack("Bite", "Strength", selectIndividualDiceByNickname(allDice,"D6"), 1);
                Attack scratch = Attack("Scratch", "Strength", selectIndividualDiceByNickname(allDice,"D4"), 1);
                unarmedBeastAttacks.push_back(bite);
                unarmedBeastAttacks.push_back(scratch);

                // Create an attack vector for weapon attacks
                
                    //Melee weapons use strength
                vector <Attack> swordAttacks;
                Attack slash = Attack("Slash", "Strength", selectIndividualDiceByNickname(allDice,"D8"), 1);
                Attack franticSlashes = Attack("Frantic slashes", "Strength", selectIndividualDiceByNickname(allDice,"D4"), 3);
                Attack stab = Attack("Stab", "Strength", selectIndividualDiceByNickname(allDice,"D8"), 1);
                
                swordAttacks.push_back(slash);
                swordAttacks.push_back(franticSlashes);
                swordAttacks.push_back(stab);

                vector <Attack> warhammerAttacks;
                Attack crush = Attack("Crush", "Strength", selectIndividualDiceByNickname(allDice,"D12"), 1);
                
                    //Ranged weapons use Dexterity
                vector <Attack> bowAttack;
                Attack letBow = Attack("Fire bow", "Dexterity", selectIndividualDiceByNickname(allDice,"D8"), 1);
                bowAttack.push_back(letBow);

                // Create an attack vector for spells?


                //Create the weapons to be used
                Weapon sword("Sword");
                sword.AddAttackToWeapon(swordAttacks);
                Weapon warhammer("Warhammer");
                warhammer.AddAttackToWeapon(warhammerAttacks);
                Weapon bow("Bow");
                bow.AddAttackToWeapon(bowAttack);
                cout << sword << endl;


                //Test adding weapons to a character and adding unarmed attacks as well
                Investigator man("Warrior man", 9, 15, 12, 13, 14, 10, 8, "Male", 5, 1);
                man.AddWeaponToBeing(sword);
                man.AddWeaponToBeing(bow);
                man.AddAttackToBeing(punch);
                man.printAttacks();

            }

            
        }


        else if (user_choice == 0)
        {
            playing = false;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }

    }

    return 0;
}