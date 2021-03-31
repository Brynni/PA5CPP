#include "being.h"
#include "individuals.h"
#include "person.h"
#include "eldritch_horror.h"
#include "speciesCreature.h"
#include "role.h"
#include "dice.h"
#include "speciesEldritchHorror.h"
#include "investigator.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm> 
#include <vector>


using namespace std;

/* _________________________________*/
// Functions for loading the data  //
/* ______________________________ */

void generateAllRoles(vector <Role> &roles){
    ifstream RolesFile;
    string fileStream; 
    string roleName;
    string tempName;
    int lifeMin;
    int lifeMax;
    int strengthMin;
    int strengthMax;
    int intelligenceMin;
    int intelligenceMax;
    //Added ability points
    int dexMin, dexMax, wisMin, wisMax, conMin, conMax, chaMin, chaMax;
    bool readingName = false;
    RolesFile.open("roles.txt");
    if (RolesFile.is_open()){
        while (RolesFile){
            RolesFile >> fileStream;
            if (fileStream == "lifeMin:"){
                readingName = false;
                RolesFile >> fileStream;
                lifeMin = std::stoi(fileStream);
            }
            else if (fileStream == "roleName:" || readingName == true){
                if (fileStream == "roleName:")
                {
                    RolesFile >> fileStream;
                }
                readingName = true;
                tempName = "";
                tempName = fileStream;
                if (roleName == "")
                {
                    roleName = tempName;
                }
                else
                {
                    roleName = roleName + " " + tempName;
                }
            }
            else if (fileStream == "lifeMax:"){
                RolesFile >> fileStream;
                lifeMax = std::stoi(fileStream);
            }
            else if (fileStream == "strengthMin:"){
                RolesFile >> fileStream;
                strengthMin = std::stoi(fileStream);
            }
            else if (fileStream == "strengthMax:"){
                RolesFile >> fileStream;
                strengthMax = std::stoi(fileStream);
            }
            else if (fileStream == "intelligenceMin:"){
                RolesFile >> fileStream;
                intelligenceMin = std::stoi(fileStream);
            }
            else if (fileStream == "intelligenceMax:"){
                RolesFile >> fileStream;
                intelligenceMax = std::stoi(fileStream);
            }

            else if (fileStream == "dexMin:"){
                RolesFile >> fileStream;
                dexMin = std::stoi(fileStream);
            }

            else if (fileStream == "dexMax:"){
                RolesFile >> fileStream;
                dexMax = std::stoi(fileStream);
            }

            else if (fileStream == "wisMin:"){
                RolesFile >> fileStream;
                wisMin = std::stoi(fileStream);
            }

            else if (fileStream == "wisMax:"){
                RolesFile >> fileStream;
                wisMax = std::stoi(fileStream);
            }

            else if (fileStream == "conMin:"){
                RolesFile >> fileStream;
                conMin = std::stoi(fileStream);
            }

            else if (fileStream == "conMax:"){
                RolesFile >> fileStream;
                conMax = std::stoi(fileStream);
            }

            else if (fileStream == "chaMin:"){
                RolesFile >> fileStream;
                chaMin = std::stoi(fileStream);
            }

            else if (fileStream == "conMax:"){
                RolesFile >> fileStream;
                conMax = std::stoi(fileStream);
            }

            else if (fileStream == "#" && roleName != ""){
                Role role(roleName, lifeMin,lifeMax ,strengthMin, strengthMax, intelligenceMin, intelligenceMax,
                        dexMin, dexMax, wisMin, wisMax, conMin, conMax, chaMin, chaMax);
                roles.push_back(role);
                roleName = "";
            }
        }
    }
}

void generateAllCreatures(vector <Creature> &creatures){

    ifstream speciesFile;
    string fileStream; 
    string speciesName;
    string tempName;
    int life;
    int strength;
    int intelligence;
    // new ability points
    int dex, con, wis, cha; 
    bool natural;
    int disquiet;
    bool readingName = false;
    speciesFile.open("species.txt");
    if (speciesFile.is_open()){
        while (speciesFile){
            speciesFile >> fileStream;
            if (fileStream == "Life:"){
                speciesFile >> fileStream;
                life = std::stoi(fileStream);
            }
            else if (fileStream == "Creature")
            {
                readingName = false;
            }
            else if (fileStream == "Name:" || readingName == true){
                if (fileStream == "Name:")
                {
                    speciesFile >> fileStream;
                }
                readingName = true;
                tempName = "";
                tempName = fileStream;
                if (speciesName == "")
                {
                    speciesName = tempName;
                }
                else
                {
                    speciesName = speciesName + " " + tempName;
                }
                
            }

            else if (fileStream == "Strength:"){
                speciesFile >> fileStream;
                strength = std::stoi(fileStream);
            }
            else if (fileStream == "Dex:"){
                speciesFile >> fileStream;
                dex = std::stoi(fileStream);
            }
            else if (fileStream == "Con:"){
                speciesFile >> fileStream;
                con = std::stoi(fileStream);
            }
            else if (fileStream == "Wis:"){
                speciesFile >> fileStream;
                wis = std::stoi(fileStream);
            }
            else if (fileStream == "Cha:"){
                speciesFile >> fileStream;
                cha = std::stoi(fileStream);
            }
            else if (fileStream == "Intelligence:"){
                speciesFile >> fileStream;
                intelligence = std::stoi(fileStream);
            }
            else if (fileStream == "Natural")
            {
                natural = true;
            }
            else if (fileStream == "Unnatural")
            {
                natural = false;
            }
            else if (fileStream == "Disquiet:")
            {
                speciesFile >> fileStream;
                disquiet = std::stoi(fileStream);
            }

            else if (fileStream == "#" && speciesName != ""){
                Creature creature(speciesName, life, strength, intelligence, dex, con, wis, cha, natural, disquiet);
                creatures.push_back(creature);
                speciesName = "";
            }
        }
    }
}

void generateAllEldritchHorrors(vector <speciesEldritchHorror> &Horrors){
    ifstream horrorsFile;
    string fileStream; 
    string horrorName;
    string tempName;
    int life;
    int strength;
    int intelligence;
    // New skill points
    int dex, con, wis, cha; 
    int traumatism;
    bool readingName = false;
    horrorsFile.open("eldritchHorrors.txt");
    if (horrorsFile.is_open()){
        while (horrorsFile){
            horrorsFile >> fileStream;
            if (fileStream == "Life:"){
                horrorsFile >> fileStream;
                life = std::stoi(fileStream);
            }
            else if (fileStream == "horror"){
                readingName = false;
            }
            else if ((fileStream == "Name:" || readingName == true) && fileStream != "Eldritch"){
                if (fileStream == "Name:")
                {
                    horrorsFile >> fileStream;
                }
                readingName = true;
                tempName = "";
                tempName = fileStream;
                if (horrorName == "")
                {
                    horrorName = tempName;
                }
                else
                {
                    horrorName = horrorName + " " + tempName;
                }
            }
            else if (fileStream == "Strength:"){
                horrorsFile >> fileStream;
                strength = std::stoi(fileStream);
            }
            else if (fileStream == "Intelligence:"){
                horrorsFile >> fileStream;
                intelligence = std::stoi(fileStream);
            }
            else if (fileStream == "Traumatism:")
            {
                horrorsFile >> fileStream;
                traumatism = std::stoi(fileStream);
            }

            else if (fileStream == "#" && horrorName != ""){
                speciesEldritchHorror horror(horrorName, life, strength, intelligence, traumatism);
                Horrors.push_back(horror);
                horrorName = "";
            }
        }
    }
}

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

void removeCreatureFromFile(Creature sp, string fileName)
{
    Creature c = Creature(sp.getName(), sp.getLife(),sp.getStrength(), sp.getInt(), sp.getDex(), sp.getCon(), sp.getWis(), sp.getCha(), sp.getNature(), sp.getDisquiet());
    ifstream speciesFile;
    string fileStream; 
    string speciesName;
    int life;
    int strength;
    int intelligence;
    bool natural;
    int disquiet;
    //New ability points
    int dex, con, wis, cha; 
    string creatures;
    string NewCreature;
    speciesFile.open("species.txt");
    if (speciesFile.is_open()){
        while (speciesFile){
            speciesFile >> fileStream;
            if (fileStream == "Name:"){
                speciesFile >> fileStream;
                speciesName = fileStream;
            }
            else if (fileStream == "Life:"){
                speciesFile >> fileStream;
                life = std::stoi(fileStream);
            }
            else if (fileStream == "Strength:"){
                speciesFile >> fileStream;
                strength = std::stoi(fileStream);
            }
            else if (fileStream == "Intelligence:"){
                speciesFile >> fileStream;
                intelligence = std::stoi(fileStream);
            }

            else if (fileStream == "Dex:"){
                speciesFile >> fileStream;
                dex = std::stoi(fileStream);
            }
            else if (fileStream == "Con:"){
                speciesFile >> fileStream;
                con = std::stoi(fileStream);
            }
            else if (fileStream == "Wis:"){
                speciesFile >> fileStream;
                wis = std::stoi(fileStream);
            }
            else if (fileStream == "Cha:"){
                speciesFile >> fileStream;
                cha = std::stoi(fileStream);
            }

            else if (fileStream == "Natural")
            {
                natural = true;
            }
            else if (fileStream == "Unnatural")
            {
                natural = false;
            }
            else if (fileStream == "Disquiet:")
            {
                speciesFile >> fileStream;
                disquiet = std::stoi(fileStream);
            }

            else if (fileStream == "#" && speciesName != "" && speciesName != sp.getName()){
                speciesCreature creature(speciesName, life, strength, intelligence, natural, disquiet);
                
                
                NewCreature = NewCreature + "Name: " + speciesName + "\n" + 
                            "Creature\n" + 
                            "Life: " + to_string(life) + "\n" + 
                            "Strength: " + to_string(strength) + "\n" +
                            "Intelligence: " + to_string(intelligence) + "\n" + 
                            "Dex: " + to_string(dex) + "\n" + 
                            "Con: " + to_string(con) + "\n" + 
                            "Wis: " + to_string(wis) + "\n" + 
                            "Cha: " + to_string(cha) + "\n" ;
                if (natural == true){
                    NewCreature = NewCreature + "Natural" + "\n" + "Disquiet: " + to_string(disquiet) + "\n" + "#" "\n";
                }
                else {
                    NewCreature = NewCreature + "Unnatural\n" + "Disquiet: " + to_string(disquiet) + "\n" + "#" "\n";
                }
                speciesName = "";
            }
        }
        std::ofstream CreatureFile;
        CreatureFile.open("species.txt", std::ios::out);
        CreatureFile << NewCreature;
    }

};

EldritchHorror createEldritchHorror(speciesEldritchHorror eh)
{
    EldritchHorror e = EldritchHorror(eh.getLife(), eh.getStrength(), eh.getIntelligence(), eh.getTraumatism());
    return e;
};

void removeEldritchHorrorFromFile(speciesEldritchHorror eh,  string fileName)
{
    ifstream horrorsFile;
    string fileStream; 
    string horrorName;
    string NewHorror;
    int life;
    int strength;
    int intelligence;
    int traumatism;
    horrorsFile.open("eldritchHorrors.txt");
    if (horrorsFile.is_open()){
        while (horrorsFile){
            horrorsFile >> fileStream;
            if (fileStream == "Name:"){
                horrorsFile >> fileStream;
                horrorName = fileStream;
            }
            else if (fileStream == "Life:"){
                horrorsFile >> fileStream;
                life = std::stoi(fileStream);
            }
            else if (fileStream == "Strength:"){
                horrorsFile >> fileStream;
                strength = std::stoi(fileStream);
            }
            else if (fileStream == "Intelligence:"){
                horrorsFile >> fileStream;
                intelligence = std::stoi(fileStream);
            }
            else if (fileStream == "Traumatism:")
            {
                horrorsFile >> fileStream;
                traumatism = std::stoi(fileStream);
            }

            else if (fileStream == "#" && horrorName != "" && horrorName != eh.getName()){
                NewHorror = NewHorror + "Name: " + horrorName + "\n" + "Creature\n" + "Life: " + to_string(life) + "\n" + 
                "Strength: " + to_string(strength) + "\n" + "Intelligence: " + to_string(intelligence) + "\n" +
                "Traumatism: " + to_string(traumatism) + "\n" + "#" "\n";
                horrorName = "";
            }
        }
        std::ofstream HorrorFile;
        HorrorFile.open("eldritchHorrors.txt", std::ios::out);
        HorrorFile << NewHorror;
    }
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

void removePersonRoleFromFile(Role role, string filename)
{
    ifstream RolesFile;
    string fileStream; 
    string roleName;
    string NewRole;
    int lifeMin;
    int lifeMax;
    int strengthMin;
    int strengthMax;
    int intelligenceMin;
    int intelligenceMax;
    RolesFile.open("roles.txt");
    if (RolesFile.is_open()){
        while (RolesFile){
            RolesFile >> fileStream;
            if (fileStream == "roleName:"){
                RolesFile >> fileStream;
                roleName = fileStream;
            }
            else if (fileStream == "lifeMin:"){
                RolesFile >> fileStream;
                lifeMin = std::stoi(fileStream);
            }
            else if (fileStream == "lifeMax:"){
                RolesFile >> fileStream;
                lifeMax = std::stoi(fileStream);
            }
            else if (fileStream == "strengthMin:"){
                RolesFile >> fileStream;
                strengthMin = std::stoi(fileStream);
            }
            else if (fileStream == "strengthMax:"){
                RolesFile >> fileStream;
                strengthMax = std::stoi(fileStream);
            }
            else if (fileStream == "intelligenceMin:"){
                RolesFile >> fileStream;
                intelligenceMin = std::stoi(fileStream);
            }
            else if (fileStream == "intelligenceMax:"){
                RolesFile >> fileStream;
                intelligenceMax = std::stoi(fileStream);
            }

            else if (fileStream == "#" && roleName != "" && roleName != role.getName()){
                
                NewRole =  NewRole + "roleName: " + roleName + "\n" + "lifeMin: " + to_string(lifeMin) + "\n" + "lifeMax: " + to_string(lifeMax) + "\n" + 
                "strengthMin: " + to_string(strengthMin) + "\n" + "strengthMax: " + to_string(strengthMax) + "\n" + "intelligenceMin: " + to_string(intelligenceMin) + "\n" +
                "intelligenceMax: " + to_string(intelligenceMax) + "\n" + "#" + "\n";
                roleName = "";
            }
        }
        std::ofstream RoleFile;
        RoleFile.open("roles.txt", std::ios::out);
        RoleFile << NewRole;
    }
}

void seeAllHorrors(vector<speciesEldritchHorror> horrors)
{
    cout << "Species of type Horror: " << endl;
    int counter = 0;
    for (speciesEldritchHorror eh : horrors )
    {
        counter++;
        cout << counter << ". "; 
        eh.printInfo();
    }

};

void seeDetailHorrors(vector<speciesEldritchHorror> horrors)
{
    for (speciesEldritchHorror eh: horrors)
    {
        cout << eh << endl;
    };
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




bool checkForNameSpecies(vector <Creature> creatures, vector<speciesEldritchHorror> horrors,string name)
{
    for (Creature sp : creatures)
    {
        string sp_name = sp.getName();
        if (name == sp_name)
        {
            return true;
        }

    }

    for (speciesEldritchHorror eh : horrors)
    {
        string eh_name = eh.getName();
        if (name == eh_name)
        {
            return true;
        }

    }

    return false;
};

bool checkForNameRole(vector <Role> roles, string name)
{
    if (roles.size() == 0)
    {
        return false;
    }

    else
    {
        for (Role x_role : roles)
        {
            if (name == x_role.getName())
            {
                return true;
            }
        }
    }


    return false;
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


speciesEldritchHorror selectHorror(vector<speciesEldritchHorror> horrors)
{
    seeAllHorrors(horrors);
    int selection;
    cout << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    while (selection < 1 || selection > horrors.size())
    {
        cout << "Invalid selection! You must select a creature between 1 and " << horrors.size() << endl; 
        cout << "Enter your selection: ";
        cin >> selection;
    }


    return horrors[selection -1];
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






Role createRole(vector <Role> roles)
{

    std::string name;
    int lifeMax, lifeMin, strengthMin, strengthMax, intMin, intMax;

    //New ability points
    int dexMax, dexMin, conMin, conMax, wisMin, wisMax, chaMin, chaMax;


    cout << "Enter name: ";
    //Clear the input buffer before hand
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;

    while (checkForNameRole(roles, name))
    {
        cout << "Name already exists!" << endl;
        cout << "Enter name: ";
        name = "";
        std::getline(std::cin, name);
    }
    cout << endl;

    cout << "Enter Minimum life: ";
    cin >> lifeMin;

    while (lifeMin < 0 || lifeMin > 30)
    {
        cin.clear();
        cout << "Invalid range! Life must be between 0-30" << endl; 
        cout << "Enter Minimum life: ";
        cin >> lifeMin;
    }

    cout << endl;

    cout << "Enter Maximum life: ";
    cin >> lifeMax;
    while (lifeMax < lifeMin || lifeMax > 30 )
    {
        cout << "Invalid range! Maximum life must be between "<< lifeMin << "-30" << endl; 
        cout << "Enter Maximum life: ";
        cin >> lifeMax;
    }

    cout << endl;
    cout << "Enter minimum strength: ";
    cin >> strengthMin;
    while (strengthMin < 0 || strengthMin > 30)
    {
        cout << "Invalid range! Life must be between 0-30" << endl; 
        cout << "Enter Minimum strength: ";
        cin >> strengthMin;
    }
    
    cout << endl;
    cout << "Enter Maximum strength: ";
    cin >> strengthMax;
    while (strengthMax < strengthMin || strengthMax > 30 )
    {
        cout << "Invalid range! Maximum strength must be between "<< strengthMin << "-30" << endl; 
        cout << "Enter Maximum strength: ";
        cin >> strengthMax;
    }

    cout << endl;
    cout << "Enter minimum intelligence: ";
    cin >> intMin;
    while (intMin < 0 || intMin > 30)
    {
        cout << "Invalid range! Intelligence must be between 0-30" << endl; 
        cout << "Enter Minimum Intelligence: ";
        cin >> intMin;
    }
    
    cout << endl;
    cout << "Enter Maximum Intelligence: ";
    cin >> intMax;
    while (intMax < intMin || intMax > 30 )
    {
        cout << "Invalid range! Maximum Intelligence must be between "<< intMin << "-30" << endl; 
        cout << "Enter Maximum Intelligence: ";
        cin >> intMax;
    }

    cout << endl;
    cout << "Enter minimum dexterity modifier: ";
    cin >> dexMin;
    while (dexMin < 0 || dexMin > 30)
    {
        cout << "Invalid range! dexterity must be between 0-30" << endl; 
        cout << "Enter Minimum dexterity: ";
        cin >> dexMin;
    }
    
    cout << endl;
    cout << "Enter Maximum dexterity: ";
    cin >> dexMax;
    while (dexMax < dexMin || dexMax > 30 )
    {
        cout << "Invalid range! Maximum dexterity must be between "<< dexMin << " -30" << endl; 
        cout << "Enter Maximum dexterity: ";
        cin >> dexMax;
    }

    cout << endl;
    cout << "Enter minimum constituion: ";
    cin >> conMin;
    while (conMin < 0 || conMin > 30)
    {
        cout << "Invalid range! constituion must be between 0-30" << endl; 
        cout << "Enter Minimum constituion: ";
        cin >> conMin;
    }
    
    cout << endl;
    cout << "Enter Maximum constituion: ";
    cin >> conMax;
    while (conMax < conMin || conMax > 30 )
    {
        cout << "Invalid range! Maximum constituion must be between "<< conMin << " - 10" << endl; 
        cout << "Enter constituion strength: ";
        cin >> conMax;
    }

    cout << endl;
    cout << "Enter minimum wisdom: ";
    cin >> wisMin;
    while (wisMin < 0 || wisMin > 30)
    {
        cout << "Invalid range! wisdom must be between 0-10" << endl; 
        cout << "Enter Minimum wisdom: ";
        cin >> wisMin;
    }
    
    cout << endl;
    cout << "Enter Maximum wisdom: ";
    cin >> wisMax;
    while (wisMax < wisMin || wisMax > 30 )
    {
        cout << "Invalid range! Maximum wisdom must be between "<< wisMin << " - 10" << endl; 
        cout << "Enter Maximum wisdom: ";
        cin >> wisMax;
    }

    cout << endl;
    cout << "Enter minimum charisma: ";
    cin >> chaMin;
    while (chaMin < 0 || chaMin > 30)
    {
        cout << "Invalid range! Charisma must be between 0-10" << endl; 
        cout << "Enter Minimum charisma: ";
        cin >> chaMin;
    }
    
    cout << endl;
    cout << "Enter Maximum charisma: ";
    cin >> chaMax;
    while (chaMax < chaMin || chaMax > 30 )
    {
        cout << "Invalid range! Maximum charisma must be between "<< intMin << " - 10" << endl; 
        cout << "Enter Maximum charisma: ";
        cin >> chaMax;
    }
    
    string NewRole;
    NewRole =  "roleName: " + name + "\n" + 
                "lifeMin: " + to_string(lifeMin) + "\n" + 
                "lifeMax: " + to_string(lifeMax) + "\n" + 
                "strengthMin: " + to_string(strengthMin) + "\n" + 
                "strengthMax: " + to_string(strengthMax) + "\n" + 
                "intelligenceMin: " + to_string(intMin) + "\n" +
                "intelligenceMax: " + to_string(intMax) + "\n" + 
                "dexMin: " + to_string(dexMin) + "\n" + 
                "dexMax: " + to_string(dexMax) + "\n" + 
                "wisMin: " + to_string(wisMax) + "\n" + 
                "wisMax: " + to_string(wisMax) + "\n" + 
                "conMin: " + to_string(conMax) + "\n" + 
                "conMax: " + to_string(conMax) + "\n" + 
                "chaMin: " + to_string(chaMax) + "\n" + 
                "chaMax: " + to_string(chaMax) + "\n" + 
                "#";

    Role r = Role(name, lifeMin,lifeMax,strengthMin,strengthMax,intMin,intMax, dexMin, dexMax, conMin, conMax, wisMin, wisMax, chaMin, chaMax);
    std::ofstream RoleFile;
    RoleFile.open("roles.txt", std::ios::out | std::ios::app);
    RoleFile << "\n" <<NewRole;
    return r;
};

Creature createSpecies(vector <Creature> species_vector, vector <speciesEldritchHorror> eh_vector)
{
    string name;
    int life, strength, intelligence, dex, con, wis, cha, naturalInput, disquiet;
    bool natural;
    cout << "Enter name: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;

    while(checkForNameSpecies(species_vector, eh_vector, name))
    {   
        cout << "Name already exists!" << endl;
        cout << "Enter name: " << endl;
        name = "";
        std::getline(std::cin, name);
    }

    cout << "Enter  life for " << name << " ";
    cin >> life;
    while (life > 1000 || life < 0)
    {   
        cout << "Invalid value for life, the range is 0-1000" << endl;
        cout << "Enter  life for " << name << " ";
        cin >> life;
    }
    
    cout << "Enter  strength for " << name << " ";
    cin >> strength;
    while (strength > 30 || strength < 0)
    {   
        cout << "Invalid value for strength, the range is 0-30" << endl;
        cout << "Enter  strength for " << name << " ";
        cin >> strength;
    }

    cout << "Enter  intelligence for " << name << " ";
    cin >> intelligence;
    while (intelligence > 30 || intelligence < 0)
    {   
        cout << "Invalid value for Intelligence, the range is 0-30" << endl;
        cout << "Enter  intelligence for " << name << " ";
        cin >> intelligence;
    }

    cout << endl;
    cout << "Enter dexterity for " << name << " ";
    cin >> dex;
    while (dex < 0 || dex > 30)
    {
        cout << "Invalid range! dexterity must be between 0-30" << endl; 
        cout << "Enter dexterity for " << name << " ";
        cin >> dex;
    }

    cout << endl;
    cout << "Enter constituion for " << name << " ";
    cin >> con;
    while (con < 0 || con > 30)
    {
        cout << "Invalid range! constituion must be between 0-30" << endl; 
        cout << "Enter constituion for " << name << " ";
        cin >> con;
    }

    cout << endl;
    cout << "Enter wisdom for " << name << " ";
    cin >> wis;
    while (wis < 0 || wis > 30)
    {
        cout << "Invalid range! wisdom must be between 0-30" << endl; 
        cout << "Enter wisdom for " << name << " ";
        cin >> wis;
    }

    cout << endl;
    cout << "Enter charisma for " << name << " ";
    cin >> cha;
    while (cha < 0 || cha > 30)
    {
        cout << "Invalid range! Charisma must be between 0-30" << endl; 
        cout << "Enter charisma for " << name << " ";
        cin >> cha;
    }
    

    cout << "Enter disquiet for " << name << " ";
    cin>> disquiet;
    while (disquiet > 10 || disquiet < 0)
    {   
        cout << "Invalid value for disquiet, the range is 0-30" << endl;
        cout << "Enter  disquiet for " << name << " ";
        cin >> disquiet;
    }

    cout << "Enter 1 if  " << name << " should be a natural creature, Enter 2 if it should be unnatural: ";
    cin >> naturalInput;

    if (naturalInput==1)
    {
        natural = true;
    }
    else
    {
        natural = false;
    }
    cout << endl;

    Creature sc = Creature(name, life, strength, intelligence, dex, con, wis, cha,  natural, disquiet);
    cout << endl;
    cout << "Here is your species: " << endl;
    cout << sc << endl;
    string NewCreature;
    NewCreature =   "Name: " + name + "\n" + 
                    "Creature\n" + 
                    "Life: " + to_string(life) + "\n" + 
                    "Strength: " + to_string(strength) + "\n" + 
                    "Intelligence: " + to_string(intelligence) + "\n";
                    "Dex: " + to_string(dex) + "\n";
                    "Con: " + to_string(con) + "\n";
                    "Wis: " + to_string(wis) + "\n";
                    "Cha: " + to_string(cha) + "\n";
    if (natural == true){
        NewCreature = NewCreature + "Natural" + "\n" + "Disquiet: " + to_string(disquiet) + "\n" + "#";
    }
    else {
        NewCreature = NewCreature + "Unnatural\n" + "Disquiet: " + to_string(disquiet) + "\n" + "#";
    }
    std::ofstream CreatureFile;
    CreatureFile.open("species.txt", std::ios::out | std::ios::app);
    CreatureFile << "\n" << NewCreature;

    return sc;
};

speciesEldritchHorror createEldritchHorror(vector<Creature> creatures, vector <speciesEldritchHorror> horrors)
{
    int life, str, intelligence, traumatism;
    string name;
    EldritchHorror eh;

    cout << "Enter name: "; 
    //Clear the input buffer before hand
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;

    while(checkForNameSpecies(creatures, horrors, name))
    {   
        cout << "Name already exists!" << endl;
        cout << "Enter name: " << endl;
        name = "";
        std::getline(std::cin, name);
    }
    cout <<"Enter life for " << name << endl;
    cin >> life;
    while (life >10 || life < 0)
    {
        cout << "Invalid value for life the range is 0-10" << endl;
        cout <<"Enter life for " << name << endl;
        cin >> life;
    }

    cout <<"Enter strength for " << name << endl;
    cin >> str;
    while (str > 10 || str < 0)
    {
        cout << "Invalid value for strength the range is 0-10" << endl;
        cout <<"Enter strength for " << name << endl;
        cin >> str;
    }
    cout << "Enter intelligence for " << name << endl;
    cin >> intelligence;
    while (intelligence > 10 || intelligence < 0)
    {
        cout << "Invalid value for intelligence the range is 0-10" << endl;
        cout <<"Enter intelligence for " << name << endl;
        cin >> intelligence;
    }
    cout << "Enter traumatism for for " << name << endl;
    cin >> traumatism;
    while (traumatism > 3 || traumatism < 0)
    {
        cout << "Invalid value for traumatism the range is 0-3" << endl;
        cout <<"Enter traumatism for " << name << endl;
        cin >> traumatism;
    }


    speciesEldritchHorror sp_eh = speciesEldritchHorror(name, life, str, intelligence, traumatism);

    cout << "Here is your species: " << endl;
    cout << sp_eh << endl;
    string NewHorror;
    NewHorror =  "Name: " + name + "\n" + "Eldritch horror\n" + "Life: " + to_string(life) + "\n" + 
    "Strength: " + to_string(str) + "\n" + "Intelligence: " + to_string(intelligence) + "\n" +
    "Traumatism: " + to_string(traumatism) + "\n" + "#";
    std::ofstream HorrorFile;
    HorrorFile.open("eldritchHorrors.txt", std::ios::out | std::ios::app);
    HorrorFile << "\n" << NewHorror;

    return sp_eh;
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

int getNumberOfHorrors(vector<Individuals<EldritchHorror> >individualsHorrors, string name)
{
    int counter = 0;

     for (Individuals<EldritchHorror> eh : individualsHorrors)
    {
        if(eh.getJob() == name)
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

void printIndividualHorrors(vector <Individuals<EldritchHorror> > individualHorrors)
{
    int counter = 0;
    cout << "Printing Individuals of type Eldritch Horrors" << endl;
    for (Individuals<EldritchHorror> h: individualHorrors)
    {
        counter ++;
        cout << counter << ". " << h.getName() << " " << h.getCounter() << endl;
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

Individuals<EldritchHorror> selectIndividualHorror(vector <Individuals<EldritchHorror> > individualHorrors)
{
    printIndividualHorrors(individualHorrors);
    cout << endl;
    int selection;
    cout << "Select what horror you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualHorrors.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualHorrors.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualHorrors[selection -1];
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

EldritchHorror createCustomHorror()
{
    int life;
    int strength;
    int intelligence;
    int traumtaism;

    cout << endl;
    cout << "Enter life for Horror: " <<  endl;
    cin >> life;
    while (life < 0 || life > 10)
    {
        cout << "Invalid value for life - the range is 0 - 10" << endl;
        cout << "Enter life for Horror: " <<  endl;
        cin >> life;
        cout << endl;
    }   
    cout << "Enter strength for Horror: " <<  endl;
    cin >> strength;
    while (strength < 0 || strength > 10)
    {
        cout << "Invalid value for strength - the range is 0 - 10" << endl;
        cout << "Enter strength for Horror: " <<  endl;
        cin >> strength;
        cout << endl;
    }   
    cout << "Enter Intelligence for Horror: " <<  endl;
    cin >> intelligence;
    while (intelligence < 0 || intelligence > 10)
    {
        cout << "Invalid value for Intelligence - the range is 0 - 10" << endl;
        cout << "Enter Intelligence for Horror: " <<  endl;
        cin >> intelligence;
        cout << endl;
    }

    cout << "Enter Traumatism for Horror: " <<  endl;
    cin >> traumtaism;
    while (traumtaism < 0 || traumtaism > 3)
    {
        cout << "Invalid value for Horror - the range is 0 - 3" << endl;
        cout << "Enter life for Horror: " <<  endl;
        cin >> traumtaism;
        cout << endl;
    }

    EldritchHorror eh = EldritchHorror(life, strength, intelligence, traumtaism);
    return eh;    
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



int main()
{
    //All vectors pertaining to beings
    vector <Role> roles;
    vector <Creature> creatures;
    vector <speciesEldritchHorror> horrors;
    vector <Individuals<Investigator>> investigators;
    vector <Individuals<Person> > individualsPersons;
    vector <Individuals<Creature> > IndividualsCreatures;
    vector <Individuals<EldritchHorror> > individualsHorrors;

    //All vectors pertaining to game mechanics
    vector <Dice> allDice;

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    
    //Initialize all the needed data for the game to function
    generateAllRoles(roles);
    generateAllCreatures(creatures);
    generateAllEldritchHorrors(horrors);
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
        cout <<"\t 6. Select Individual for editing / deleting" << endl;
        cout <<"\t 7. Remove Individual Type" << endl;
        cout <<"\t 8. Roll dice test" << endl;
        cout <<"\t 0. quit" << endl;

        cout << "Enter choice here: ";
        cin >> user_choice;
        cout << " " << endl;


        if (user_choice == 1)
        {
            roles.push_back(createRole(roles));
        }

        else if (user_choice == 2)
        {
            int creature_or_horror;
            cout << "Would you like your species to be: \n\t1.Creature\n\t2.Eldritch Horror: ";
            cin >> creature_or_horror;
            if (creature_or_horror != 2)
            {
                creatures.push_back(createSpecies(creatures, horrors));
            }
            else
            {
                horrors.push_back(createEldritchHorror(creatures,horrors));
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

            else if (whatList == 2 && horrors.size()>0)
            {
                cout << "Would you like see: " << endl;
                cout << "1. Compact view" << endl;
                cout << "2. Detailed view" << endl;
                cout << "Your choice here: ";
                cin >> detailOrCompact;
                cout << endl;

                if (detailOrCompact == 1)
                {
                    seeAllHorrors(horrors);
                    cout << endl;
                }

                if (detailOrCompact == 2)
                {
                    seeDetailHorrors(horrors);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid selection" << endl;
                }
            }
            else if (whatList == 2 && horrors.size() == 0)
            {
                cout << "No species of type Eldritch Horror yet added" << endl;
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
                if(horrors.size() > 0)
                {
                    int basicOrCustom;
                    speciesEldritchHorror eh = selectHorror(horrors);

                    cout << "Would you like to create a basic or a custom Individual? " << endl;
                    cout << "1. Basic" << endl;
                    cout << "2. Custom" << endl;
                    cin >>basicOrCustom;

                    if(basicOrCustom == 1)
                    {
                       
                        EldritchHorror horror = createEldritchHorror(eh);
                        int countOfHorrors = getNumberOfHorrors(individualsHorrors, eh.getName());
                        string name = eh.getName();
                        Individuals<EldritchHorror> t = Individuals<EldritchHorror>(name, horror, countOfHorrors +1, eh.getName());
                        individualsHorrors.push_back(t);
                        t.printA();
                        cout << endl;
                    }

                    if (basicOrCustom == 2)
                    {
                        string name;
                        EldritchHorror horror = createCustomHorror();
                        int countOfHorrors = getNumberOfHorrors(individualsHorrors, eh.getName());
                        cout << "Enter name for individual: ";
                        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, name);
                        Individuals<EldritchHorror> t = Individuals<EldritchHorror>(name, horror, countOfHorrors +1, eh.getName());
                        individualsHorrors.push_back(t);
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
                    cout << "There are no horrors..." << endl;
                }
                
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
                printIndividualHorrors(individualsHorrors);
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
                    cr.type.updateIntelligence();
                }

                else if(editing >0 || editing < 6 )
                {
                    Creature newCre = Creature (cr.type.getName(), cr.type.getLife(), cr.type.getStrength(), cr.type.getIntelligence(), cr.type.getDex(), cr.type.getCon(), cr.type.getWis(), cr.type.getCha(), cr.type.getNature(), cr.type.getDisquiet());
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

                else if (editing > 0 && editing < 7)
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

                else if (editing < 1 || editing > 6)
                {
                    cout << "Invalid Selection" << endl;
                }

                
            }

            else if(whatToEdit == 3)
            {
                Individuals<EldritchHorror> eh = selectIndividualHorror(individualsHorrors);
                int editing;
                eh.printA();
                cout << "What would you like to edit? " << endl;
                cout << "1. Life" << endl;
                cout << "2. Strength" << endl;
                cout << "3. Traumatism" << endl;
                cout << "4. Intelligence " << endl;
                cout << "Your selection: ";

                cin >> editing;


                if (editing == 1)
                {
                    eh.type.updateLife();
                }

                if (editing == 2)
                {
                    eh.type.updateStrength();
                }

                if (editing == 3)
                {
                    
                    eh.type.updateTrauma();
                    
                }


                if (editing == 4)
                {
                    eh.type.updateIntelligence();
                }

                else if(editing >0 || editing < 5 )
                {
                    EldritchHorror newHorror = EldritchHorror (eh.type.getLife(), eh.type.getStrength(), eh.type.getIntelligence(), eh.type.getTraumatism());
                    string name = eh.getName();
                    string job = eh.getJob();
                    int count = eh.getCounter();
                    Individuals<EldritchHorror> t = Individuals<EldritchHorror>(name, newHorror, count, job);
                    for (int i=0; i<individualsHorrors.size();i++)
                    {
                        if (individualsHorrors[i].getName() == eh.getName() && individualsHorrors[i].getCounter() == eh.getCounter() )
                        {
                            individualsHorrors.erase(individualsHorrors.begin() + i);
                            individualsHorrors.push_back(t);
                        }
                    }
                    sort(individualsHorrors.begin(), individualsHorrors.end());
                }

                else if(editing < 1 || editing > 6)
                {
                    cout << "Invalid selection" << endl;
                }

                cout << endl;
                
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

                else if (editing > 0 && editing < 8)
                {
                    Investigator newI = Investigator (inv.type.getName(), inv.type.getLife(), inv.type.getStrength(), inv.type.getInt(), inv.type.getDex(), inv.type.getCon(), inv.type.getWis(), inv.type.getCha(),  inv.type.getGender(), inv.type.getFear(), inv.type.getTerror());
                    string name = inv.getName();
                    string job = inv.getJob();
                    int count = inv.getCounter();
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

                else if (editing < 1 || editing > 7)
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
                    removeCreatureFromFile(cre, "species.txt");
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
                if(horrors.size() > 0)
                {
                    cout << "Horror" << endl;
                    speciesEldritchHorror eh = selectHorror(horrors);
                    removeEldritchHorrorFromFile(eh, "eldritchHorrors.txt");
                    //Remove the horror from the horror vector as per the Occamz razor sollution
                    for (int i = 0; i < horrors.size(); i++)
                    {
                        if (horrors[i].getName() == eh.getName())
                        {
                            horrors.erase (horrors.begin() + i);
                        }
                    }
                    //Success
                    cout << "Horror type has been removed..." << endl; 
                }

                else
                {
                    cout << "There are no horrors..." << endl;
                }
                
            }

            else if (select_creature_horror_person == 3)
            {
                if(roles.size() > 0)
                {
                    Role sel_role = selectRole(roles);
                    removePersonRoleFromFile(sel_role, "roles.txt");
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
            Dice selectedDice = selectIndividualDice(allDice);
            cout << "The roll of your selected dice is: " << selectedDice.rollDice() << endl;
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