#include "attack.h"
#include "battle.h"
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

int selectIndividualEncounter(vector <Encounter> encounters)
{
    seeAllEncounters(encounters);
    cout << endl;
    int selection;
    cout << "Select what encounter you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > encounters.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << encounters.size() << endl;
        cout << "Select what encounter you would like to select for editing: ";
        cin >> selection;
    }

    return selection-1;
}

Individuals<Creature> selectIndividualCreature(vector <Individuals<Creature> > individualCreatures)
{
    printIndividualCreature(individualCreatures);
    cout << endl;
    int selection;
    cout << "Select what creature you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualCreatures.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualCreatures.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualCreatures[selection -1];
}

Individuals<Person>& selectIndividualPerson(vector <Individuals<Person> > individualPersons)
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

int getIndexOfInvestigator(vector <Individuals<Investigator> > investigators)
{
    printIndividualInvestigator(investigators);
    cout << endl;
    int selection;
    cout << "Select an PC: ";
    cin >> selection;
    while(selection < 1 || selection > investigators.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << investigators.size() << endl;
        cout << "Select an PC: ";
        cin >> selection;
    }

    return (selection -1);
}


/* _________________________________*/
//       Main starts here!         //
/* ______________________________ */

int main()
{
    //All vectors pertaining to beings
    vector <Role> roles;
    vector <Creature> creatures;
    vector <Attack> attacks;
    vector <Weapon> weapons;
    vector <Individuals<Investigator>> investigators;
    vector <Individuals<Person> > individualsPersons;
    vector <Individuals<Creature> > IndividualsCreatures;
    vector <Individuals<Investigator>> gameInvestigators;

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

    // Create an attack vector for unarmed attacks
    vector <Attack> unarmedHumanAttacks;
    Attack punch = Attack();
    unarmedHumanAttacks.push_back(punch);
    attacks.push_back(punch);

    vector <Attack> unarmedBeastAttacks;
    Attack bite = Attack("Bite", "Strength", selectIndividualDiceByNickname(allDice,"D6"), 1);
    Attack scratch = Attack("Scratch", "Strength", selectIndividualDiceByNickname(allDice,"D4"), 1);
    unarmedBeastAttacks.push_back(bite);
    unarmedBeastAttacks.push_back(scratch);
    attacks.push_back(bite);
    attacks.push_back(scratch);

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

    sword.AddAttacksToWeapon(swordAttacks);
    Weapon warhammer("Warhammer");
    warhammer.AddAttacksToWeapon(warhammerAttacks);
    Weapon bow("Bow");
    bow.AddAttacksToWeapon(bowAttack);
    weapons.push_back(sword);
    weapons.push_back(bow);
    weapons.push_back(warhammer);
    


    //Test adding weapons to a character and adding unarmed attacks as well
    /* Investigator man("Warrior man", 9, 15, 12, 13, 14, 10, 8, "Male", 5, 1);
    man.AddWeaponToBeing(sword);
    man.AddWeaponToBeing(bow);
    man.AddAttackToBeing(punch);
    man.printAttacks();
    int manInit = man.getInitiative();
    cout << "This is the initive: " << manInit << endl; */

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

                    else if (basicOrCustom == 2)
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
                //TODO Remove this
                cout << "Gone" << endl;
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
                //TODO REMOVE
                cout << "blah" << endl;

            }
            else if (whatToEdit == 2)
            {
                //TODO remove
                cout << "Taken away" << endl;
            }

            else if(whatToEdit == 3)
            {
            //TODO Remove
                cout << "Nothing to see here" << endl;
            }

            else if(whatToEdit == 4)
            {
                //TODO Remove
                
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
                        if (roles[i].getRoleName() == sel_role.getRoleName())
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
            cout << "Would you like to select\n\t0.Dice test\n\t1.attack setup test?\n\t2.Final version of path 2. Create Encounter\n\t3.version of path 9 generate encounter\n\t4.Final version of path 1. Create Human\n\t5.Not final version of path 5. Add attack to Being/object\n\t6. Not final version of path 6. Edit/delete being\n\t7. Not final version of path 7. Edit/delete encounter\n\t8.Battle Test\n\t9.Select/remove Character for game session -- Path 8"<< endl;
            cin >>select_test;
            if (select_test == 0){
                Dice selectedDice = selectIndividualDice(allDice);
                cout << "The roll of your selected dice is: " << selectedDice.rollDice() << endl;
            }
            if (select_test == 1){
                cout << "Moved to initiliazier!" << endl;
            }
            if (select_test == 2){
                //Path 2 completed
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
            if (select_test == 3){
                int randEnc;

                cout << "Would you like to get a " << endl;
                cout << "1. Easy encounter" << endl;
                cout << "2. Medium encounter" << endl;
                cout << "3. Hard encounter" << endl;
                cout << "4. Impossible encounter" << endl;
                cin >> randEnc;
                while(randEnc < 1 || randEnc > 4){
                    cout << "INVALID SELECTION!!!!" << endl;
                    cout << "Would you like to get a " << endl;
                    cout << "1. Easy encounter" << endl;
                    cout << "2. Medium encounter" << endl;
                    cout << "3. Hard encounter" << endl;
                    cout << "4. Impossible encounter" << endl;
                    cin >> randEnc;
                }

                Encounter selEnc = getRandomEncounter(randEnc-1, allEncounters);
                
            }
            if (select_test == 4){
                //Path 1 Create Human
                createPersonAndAddToVector(roles, investigators, individualsPersons);
            }
            if (select_test == 5){
                //Path 5 Add attack to weapon/being
                int userChoice = uiAttackAdder();
                if (userChoice == 1)
                {
                    string enemyType = uiSelectBeingType();
                    Creature &selectedCreature = selectCreatureWithType(creatures, enemyType);
                    Attack selectedAttack = selectAttack(attacks);
                    cout << "BEFORE UPDATE ATTACKS" << endl;
                    selectedCreature.printAttacks();
                    vector<Attack> theAttacksVector = selectedCreature.getAttacksVector();
                    theAttacksVector.push_back(selectedAttack);
                    //selectedCreature.printAttacks();
                    selectedCreature.getAttacksVector() = theAttacksVector;
                    cout << "AFTER UPDATE" << endl;
                    selectedCreature.printAttacks();

                }
                if (userChoice == 2)
                {
                    int userChoice = uiSelectNPCOrPC();
                    if (userChoice == 1)
                    {
                        
                        Individuals<Person> & p = selectIndividualPerson(individualsPersons);
                        Attack selectedAttack = selectAttack(attacks);
                        vector<Attack> theAttacksVector = p.getType().getAttacksVector();
                        theAttacksVector.push_back(selectedAttack);
                        p.getType().printAttacks();
                        p.getType().getAttacksVector() = theAttacksVector;
                        p.type.printAttacks();
                    }
                    if (userChoice == 2)
                    {
                        
                        Individuals<Investigator>& inv = selectIndividualInvestigator(investigators);
                        Attack selectedAttack = selectAttack(attacks);
                        vector<Attack> theAttacksVector = inv.getType().getAttacksVector();
                        theAttacksVector.push_back(selectedAttack);
                        inv.getType().printAttacks();
                        inv.getType().getAttacksVector() = theAttacksVector;
                        inv.type.printAttacks();


                    }
                }
                if (userChoice == 3)
                {
                    //Todo perhaps add the choice to pick a premade attack for a weapon
                    // You would have to create a new vector called weapon attacks and allow the old one to be renamed unarmed attacks
                    Weapon selectedWeapon = selectWeapon(weapons);
                    Attack newAttack = createIndividualAttack(allDice);
                    cout << "This is your new attack" << endl;
                    cout << newAttack << endl;
                    selectedWeapon.AddAttackToWeapon(newAttack);
                }
            }
            if (select_test == 6)
            {
                //Select Being to edit/remove
                int userchoice1 = uiPrintAllTypes ();
                if (userchoice1 == 1)
                {
                    int userchoice2 = uiNPCOrPC();
                    if (userchoice2 == 1)
                    {
                        cout << "selected NPC" << endl;
                        if (individualsPersons.size() != 0)
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

                            else if (editing == 2)
                            {
                                p.type.updateStrength();
                            }

                            else if (editing == 3)
                            {
                                p.type.updateName();
                            }

                            else if (editing == 4)
                            {
                                p.type.updateInt();
                            }

                            else if (editing == 5)
                            {
                                p.type.updateGender();
                            }

                            else if (editing == 6)
                            {
                                p.type.updateFear();
                            }

                            else if (editing == 7)
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
                        } else {
                            cout << "Error! No NPC's found in system!" << endl;
                        } 
                                      
                    }
                    if (userchoice2 == 2)
                    {
                        cout << "selected PC" << endl;
                        if (investigators.size() != 0)
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

                            else if (editing == 2)
                            {
                                inv.type.updateStrength();
                            }

                            else if (editing == 3)
                            {
                                inv.type.updateName();
                            }

                            else if (editing == 4)
                            {
                                inv.type.updateInt();
                            }

                            else if (editing == 5)
                            {
                                inv.type.updateGender();
                            }

                            else if (editing == 6)
                            {
                                inv.type.updateFear();
                            }

                            else if (editing == 7)
                            {
                                inv.type.updateTerror();
                            }

                            else if (editing == 8)
                            {
                                inv.type.takeDamage(5);
                            }

                            else if (editing > 0 && editing < 9)
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
                                cout << " Updated Investigator" << endl;
                                t.printA();
                                cout << endl;
                                sort(investigators.begin(), investigators.end());
                            }

                            else if (editing < 1 || editing > 8)
                            {
                                cout << "Invalid Selection" << endl;
                            }
                        } else {
                            cout << "Error! No PC's found in system!" << endl;
                        }
                    }
                }
                if (userchoice1 == 2)
                {
                    if (creatures.size() != 0){
                        // start by listing all creatures
                        //TODO CREATURE STUFFFFFFFFFF
                        string type = uiSelectBeingType();
                        Creature cre = selectCreatureWithType(creatures, type);
                        // select stat to edit
                        int index = 0;
                        for (Creature cr : creatures)
                        {
                            if (cr.getName() == cre.getName())
                            {
                                break;
                            }
                            index ++;
                        }
                        cout<< index << endl;
                
                        string statToEdit = uiUpdateStat();
                        if (statToEdit != "cancel")
                        {
                            cre.updateStat(statToEdit);
                            Creature newCre = createCreature(cre);
                             for (int i=0; i<creatures.size();i++)
                                {
                                    if (creatures[i].getName() == cre.getName())
                                    {
                                        creatures.erase(creatures.begin() + i);
                                        creatures.push_back(newCre); 
                                    }
                                }
                        }
                        
                    } else {
                        cout << "Error! No enemies found in system!" << endl;
                    }
                }
            }
            if (select_test == 7)
            {
                //TODO write to file the change
                if (allEncounters.size() > 0)
                {
                    cout << "Edit/remove encounters" << endl;
                    int selectedEncounter = selectIndividualEncounter(allEncounters);
                    int userChoice = uiEditEncounter();
                    if (userChoice == 1)
                    {
                        cout << "What creature do you wish you remove?" << endl;
                        seeAllCreatures(allEncounters[selectedEncounter].creatures);
                        int userChoice2;
                        cin >> userChoice2;
                        if (userChoice2 > 0 &&  userChoice2 <= allEncounters[selectedEncounter].creatures.size()+1){
                            allEncounters[selectedEncounter].creatures.erase (allEncounters[selectedEncounter].creatures.begin()+userChoice2-1);
                            if (allEncounters[selectedEncounter].creatures.size() == 0){
                                allEncounters.erase (allEncounters.begin()+selectedEncounter);      
                            }
                        } else {
                            cout << "Error selection out of range!" << endl;
                        }
                    }
                    else if (userChoice == 2)
                    {
                        string typeOfCreature = uiSelectBeingType();
                        cout << typeOfCreature << endl;

                        //Find how many creatures of the type exist
                        int tempCreaturesCount = countAllCreaturesOfType(creatures, typeOfCreature);
                        if (tempCreaturesCount > 0)
                        {
                            Creature selectedCreature = selectCreatureWithType(creatures, typeOfCreature);
                            allEncounters[selectedEncounter].addEnemyToEncounter(selectedCreature);
                        } else{
                            cout << "Error! No creature of type " << typeOfCreature << endl;
                        }
                    }
                    else if (userChoice == 3)
                    {
                        string newDifficulty = uiSelectDifficulty();
                        allEncounters[selectedEncounter].changeDifficulty(newDifficulty);

                        
                        cout << "Current difficulty: " << allEncounters[selectedEncounter].difficulty << endl;
                        
                    }
                    else if (userChoice == 4)
                    {
                        allEncounters.erase (allEncounters.begin()+selectedEncounter);        
                    }
                    
                } else {
                    cout << "Error! No encounters found!" << endl;
                }
            }
            // Battle test hereeee
            else if(select_test == 8)
            {
                if (gameInvestigators.size() > 0)
                {// Start by seleting encounter
                int randEnc;

                cout << "Would you like to get a " << endl;
                cout << "1. Easy encounter" << endl;
                cout << "2. Medium encounter" << endl;
                cout << "3. Hard encounter" << endl;
                cout << "4. Impossible encounter" << endl;
                cin >> randEnc;
                while(randEnc < 1 || randEnc > 4){
                    cout << "INVALID SELECTION!!!!" << endl;
                    cout << "Would you like to get a " << endl;
                    cout << "1. Easy encounter" << endl;
                    cout << "2. Medium encounter" << endl;
                    cout << "3. Hard encounter" << endl;
                    cout << "4. Impossible encounter" << endl;
                    cin >> randEnc;
                }

                Encounter selEnc = getRandomEncounter(randEnc-1, allEncounters);
                vector<Individuals<Investigator>> selInv;
                bool keepAdding = true;
                int addingNum;
                while (keepAdding)
                {
                    cout << "Add Characters" << endl;
                    Individuals<Investigator>& inv = selectIndividualInvestigator(gameInvestigators);
                    selInv.push_back(inv);
                    // This is the shit we need to fix
                    inv.type.printAttacks();
                    cout << "Keep adding?" << endl;
                    cout <<"1. yes" << endl;
                    cout <<"2. no" << endl;
                    cin >> addingNum;
                    while (addingNum > 2 || addingNum < 1)
                    {
                        cout << "invalid selection" << endl;
                        cout << "Keep adding?" << endl;
                        cout <<"1. yes" << endl;
                        cout <<"2. no" << endl;
                        cin >> addingNum;
                    }

                    if (addingNum == 2)
                    {
                        keepAdding = false;
                    }
                }
                battleEnv(selEnc, selInv);
                } else {
                    cout << "Error! No investigator found!" << endl;
                }
            }
            else if(select_test == 9)
            {
                int userChoice = uiSelectOrRemoveFromEncounter();
                if (userChoice == 1)
                {
                    //Add character to game
                    if (investigators.size() != 0)
                    {
                        gameInvestigators.push_back(selectIndividualInvestigator(investigators));
                    } else {
                        cout << "Error! No investigators in the system!" << endl;
                    } 
                }
                if (userChoice == 2)
                {
                    //Remove character from game
                    if (gameInvestigators.size() != 0)
                    {
                        for (int i = 0; i < gameInvestigators.size(); i++)
                        {
                            int userChoice2 = getIndexOfInvestigator(gameInvestigators);
                            gameInvestigators.erase (gameInvestigators.begin()+userChoice2);
                        }
                    } else{
                        cout << "Error! No investigators in the system!" << endl;
                    }
                    
                }
            }
        }

        // Testing area for creating weapons and attacks
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
                    newWep.AddAttacksToWeapon(newVect);
                    cout << "This is your new weapon"<< endl;
                    cout << newWep << endl;
                    
                }

            }
            else
            {
                Attack newAttack = createIndividualAttack(allDice);
                cout << "This is your new attack" << endl;
                cout << newAttack << endl;
                attacks.push_back(newAttack);
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