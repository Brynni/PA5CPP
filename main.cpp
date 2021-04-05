#include "attack.h"
#include "being.h"
#include "dice.h"
#include "encounter.h"
#include "fileReader.h"
#include "individuals.h"
#include "investigator.h"
#include "person.h"
#include "speciesCreature.h"
#include "role.h"
#include "weapon.h"
#include "ui.h"


#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm> 
#include <vector>


using namespace std;

// Find out the problem here
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





// TODO Get this working 
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
    vector <Encounter> allEncounters;

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    
    //Initialize all the needed data for the game to function
    FileReader myFileReader; 
    myFileReader.ReadRolesFromFile(roles);
    myFileReader.ReadCreaturesFromFile(creatures);
    myFileReader.ReadEncounterFromFile(allEncounters, creatures);
    initializeBaseDice(allDice);
    /* for (int i = 0; i < allEncounters.size(); i++){
        cout << allEncounters[i];
    } */

    bool playing = true;

    while (playing)
    {
        int user_choice = renderMainMenu();


        if (user_choice == 1)
        {
            roles.push_back(myFileReader.createRole(roles));
        }

        else if (user_choice == 2)
        {
            int creature_or_horror = uiCreatureOrHorror();

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
            int whatList = uiRenderListOfType();
            
            
            if (whatList == 1 && creatures.size()>0)
            {
                int detailOrCompact = uiDetailListOrCompactList();

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
                int detailOrCompact = uiDetailListOrCompactList();

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
            int select_creature_horror_person = uiSelectCHP();
            if(select_creature_horror_person == 1)
            {
                if(creatures.size() > 0)
                {
                    Creature cre = selectCreature(creatures);

                    int basicOrCustom = uiBasicOrCustom();

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
                    int npc_pc = uiNPCOrPC();
                    if(npc_pc == 1)
                    {
                        Role sel_role = selectRole(roles);
                        int basicOrCustom = uiBasicOrCustom();
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
                        int basicOrCustom = uiBasicOrCustom();
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
            int indList = uiIndividualList();
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
            int whatToEdit = uiEditIndividuals();
            if (whatToEdit == 1)
            {
                Individuals<Creature> cr = selectIndividualCreature(IndividualsCreatures);
                Creature & cre = cr.getType();
                cr.printA();
                int editing = uiStatToEdit();

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
                    Creature newCre = Creature (cr.type.getName(), cr.type.getLife(), cr.type.getStrength(), cr.type.getInt(), cr.type.getDex(), cr.type.getCon(), cr.type.getWis(), cr.type.getCha(), cr.type.getNature(), cr.type.getDisquiet(), cr.type.getType());
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
                Individuals<Person> p = selectIndividualPerson(individualsPersons);
                cout << "Selected person: " << endl;
                p.printA();
                int editing = uiStatToEdit();
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
                Individuals<Investigator> inv = selectIndividualInvestigator(investigators);
                cout << "Selected investigator: " << endl;
                inv.printA();
                int editing = uiStatToEdit();
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
            
            int select_creature_horror_person = uiSelectCHP();
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
            cout << "Would you like to select\n\t0.Dice test\n\t1.attack setup test?\n\t2.create encounter"<< endl;
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
            if (select_test == 2){
                //Create Encounter Path
                Encounter newEncounter;
                bool hasBeenSaved = false;
                while (!hasBeenSaved)
                {
                    int userChoice1 = uiCreateEncounter(newEncounter.creatures.size());
                    // if he wants to select from the already existing plethora of characters
                    if (userChoice1 == 1)
                    {
                        string typeOfCreature = uiSelectBeingType();
                        cout << typeOfCreature << endl;

                        //Find how many creatures of the type exist
                        int tempCreaturesCount = countAllCreaturesOfType(creatures, typeOfCreature);
                        if (tempCreaturesCount > 0)
                        {
                            Creature selectedCreature = selectCreatureWithType(creatures, typeOfCreature);
                            newEncounter.addEnemyToEncounter(selectedCreature);
                        } else{
                            cout << "Error! No creature of type " << typeOfCreature << endl;
                        }
                    }
                    //If the user wants to create his own custom enemy type
                    else if (userChoice1 == 2)
                    {
                        creatures.push_back(myFileReader.createSpecies(creatures));
                    } 
                    // Attempt to save
                    else if (userChoice1 == 3) {
                        if (newEncounter.creatures.size() == 0)
                        {
                            cout << "Error! Nothing added to the encounter! Exiting...." << endl;
                            hasBeenSaved = true;
                        } else {
                            string difficultyLevel = uiSelectDifficulty();
                            newEncounter.changeDifficulty(difficultyLevel);
                            allEncounters.push_back(newEncounter);
                            myFileReader.createEncounter(newEncounter);
                            cout << "Success! Encounter has been saved ...." << endl;
                            cout << newEncounter << endl;
                            hasBeenSaved = true;
                        }
                    } else {
                        cout << "Invalid Choice! Try again!" << endl;
                    }
                }   
            }
        }

        // Testing area for createing weapons and attacks
        else if (user_choice == 9)
        {
            int w_or_s; 
            cout << "Would you like to create: " << endl;
            cout << "1. Weapon" << endl;
            cout << "2. Attack/Spell" << endl;
            cin >> w_or_s;
            while(w_or_s < 1 || w_or_s > 2){
                cout << "invalid input" << endl;
                cout << "Would you like to create: " << endl;
                cout << "1. Weapon" << endl;
                cout << "2. Attack/Spell" << endl;
                cin >> w_or_s;
            }
            if (w_or_s == 1 ){
                Weapon newWep = createIndividualWeapon();
                char addAttack;
                cout << "Would you like to create an Attack and assign it to the weapon? (y/n)" << endl;
                cin >> addAttack;
                if (addAttack == 'y')
                {
                    vector<Attack> newVect;
                    bool addingToWeapon = true;
                    while (addingToWeapon)
                    {
                        Attack newAttack = createIndividualAttack(allDice);
                        newVect.push_back(newAttack);
                        char keepAdding;
                        cout << "Would you like to another attack to the weapon? (y/n)" << endl;
                        cin >> keepAdding;
                        if(keepAdding != 'y'){
                            addingToWeapon = false;
                        } 
                    }
                    newWep.AddAttackToWeapon(newVect);
                    cout << "This is your new weapon"<< endl;
                    cout << newWep << endl;
                    
                }

            }
            else
            {
                Attack newAttack = createIndividualAttack(allDice);
                cout << "This is your new attack" << endl;
                cout << newAttack << endl;
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