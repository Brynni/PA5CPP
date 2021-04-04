#include "fileReader.h"
#include <iostream>
#include <fstream>


using namespace std;

// Helper functions

bool checkForNameSpecies(vector <Creature> creatures,string name)
{
    for (Creature sp : creatures)
    {
        string sp_name = sp.getName();
        if (name == sp_name)
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



/* _________________________________*/
// Functions for loading the data  //
/* ______________________________ */

void FileReader::ReadRolesFromFile(vector <Role> &roles){
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

            else if (fileStream == "chaMax:"){
                RolesFile >> fileStream;
                chaMax = std::stoi(fileStream);
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


void FileReader::ReadCreaturesFromFile(vector <Creature> &creatures){

    ifstream speciesFile;
    string fileStream; 
    string speciesName;
    string tempName;
    string typeOfCreature;
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

            else if (fileStream == "Type:")
            {
                speciesFile >> fileStream;
                typeOfCreature = fileStream;
            }

            else if (fileStream == "#" && speciesName != ""){
                Creature creature(speciesName, life, strength, intelligence, dex, con, wis, cha, natural, disquiet, typeOfCreature);
                creatures.push_back(creature);
                speciesName = "";
            }
        }
    }
}


void FileReader::ReadEncounterFromFile(vector <Encounter> encounters_vector, vector <Creature> creatures_vector)
{
ifstream encounterFile;
    string fileStream; 
    string speciesName;
    string difficulty;
    Encounter newEncounter;
    bool readingName = false;
    encounterFile.open("encounter.txt");
    if (encounterFile.is_open()){
        while (encounterFile){
            encounterFile >> fileStream;
            if (fileStream == "Difficulty:")
            {
                encounterFile >> fileStream;
                difficulty = fileStream;
            }
            if (fileStream == "Enemies-")
            { 
                while (fileStream != "Difficulty"){
                    encounterFile >> fileStream;
                    difficulty = fileStream;
                    if (fileStream == "#" && speciesName != ""){
                        //Creature creature(speciesName, life, strength, intelligence, dex, con, wis, cha, natural, disquiet, typeOfCreature);
                        newEncounter.addEnemyToEncounter(selectCreatureWithName(creatures_vector, speciesName));
                        speciesName = "";
                    }
                encounters_vector.push_back(newEncounter);
                }
            }
        }
    }   
}


/* 
    Would be good to use this for initializing the vector bla
    for (int i = 0; i < encounters_vector.size(); i++)
    {
        for (int j = 0; j < encounters_vector[i].creatures.size();j++)
        {
            
        }
    } */

/* _________________________________*/
// Functions for deleting data     //
/* ______________________________ */


void FileReader::RemoveCreatureFromFile(Creature sp, string fileName)
{
    Creature c = Creature(sp.getName(), sp.getLife(),sp.getStrength(), sp.getInt(), sp.getDex(), sp.getCon(), sp.getWis(), sp.getCha(), sp.getNature(), sp.getDisquiet(), sp.getType());
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

void FileReader::RemovePersonRoleFromFile(Role role, string filename)
{
    ifstream RolesFile;
    string fileStream; 
    string roleName;
    string NewRole;
    int lifeMax, lifeMin, strengthMin, strengthMax, intelligenceMin, intelligenceMax;

    //New ability points
    int dexMax, dexMin, conMin, conMax, wisMin, wisMax, chaMin, chaMax;
    
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

            else if (fileStream == "chaMax:"){
                RolesFile >> fileStream;
                chaMax = std::stoi(fileStream);
            }

            else if (fileStream == "#" && roleName != "" && roleName != role.getName()){
                
                NewRole =   NewRole + 
                            "roleName: " + roleName + "\n" + 
                            "lifeMin: " + to_string(lifeMin) + "\n" + 
                            "lifeMax: " + to_string(lifeMax) + "\n" + 
                            "strengthMin: " + to_string(strengthMin) + "\n" + 
                            "strengthMax: " + to_string(strengthMax) + "\n" + 
                            "intelligenceMin: " + to_string(intelligenceMin) + "\n" +
                            "intelligenceMax: " + to_string(intelligenceMax) + "\n" + 
                            "dexMin: " + to_string(dexMin) + "\n" + 
                            "dexMax: " + to_string(dexMax) + "\n" + 
                            "wisMin: " + to_string(wisMax) + "\n" + 
                            "wisMax: " + to_string(wisMax) + "\n" + 
                            "conMin: " + to_string(conMax) + "\n" + 
                            "conMax: " + to_string(conMax) + "\n" + 
                            "chaMin: " + to_string(chaMax) + "\n" + 
                            "chaMax: " + to_string(chaMax) + "\n" + 
                            "#" + "\n";
                roleName = "";
            }
        }
        std::ofstream RoleFile;
        RoleFile.open("roles.txt", std::ios::out);
        RoleFile << NewRole;
    }
}


/* _________________________________*/
//  Functions for writing data     //
/* ______________________________ */

Role FileReader::createRole(vector <Role> roles)
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

Creature FileReader::createSpecies(vector <Creature> species_vector)
{
    string name, type;
    int life, strength, intelligence, dex, con, wis, cha, naturalInput, disquiet, typeSelect;
    bool natural;
    cout << "Enter name: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    cout << endl;

    while(checkForNameSpecies(species_vector, name))
    {   
        cout << "Name already exists!" << endl;
        cout << "Enter name: " << endl;
        name = "";
        std::getline(std::cin, name);
    }

    cout << "Select type of creature: " <<  endl;
    cout << "0. Humanoid" <<  endl;
    cout << "1. Animal" <<  endl;
    cout << "2. Undead" <<  endl;
    cout << "3. Monstrosity" <<  endl;
    cin >> typeSelect;
    while (typeSelect < 0 || typeSelect > 4)
    {
        cout << "Invalid selection - the range is 0 - 3" << endl;
        cout << "Select type of creature: " <<  endl;
        cin >> typeSelect;
        cout << endl;
    } 

    switch(typeSelect) {
      case 0 :
         type = "Humanoid"; 
         break;
      case 1 :
         type = "Animal";
         break;
      case 2 :
         type = "Undead";
         break;
      case 3 :
         type = "Monstrosity";
         break;
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

    Creature sc = Creature(name, life, strength, intelligence, dex, con, wis, cha,  natural, disquiet, type);
    cout << endl;
    cout << "Here is your species: " << endl;
    cout << sc << endl;
    string NewCreature;
    NewCreature =   "Name: " + name + "\n" + 
                    "Creature\n" + 
                    "Life: " + to_string(life) + "\n" + 
                    "Strength: " + to_string(strength) + "\n" + 
                    "Intelligence: " + to_string(intelligence) + "\n" +
                    "Dex: " + to_string(dex) + "\n" +
                    "Con: " + to_string(con) + "\n" +
                    "Wis: " + to_string(wis) + "\n" +
                    "Cha: " + to_string(cha) + "\n" +
                    "Type: " + type + "\n";
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

void FileReader::createEncounter(Encounter encounter)
{
    string newEncounter;
    newEncounter += "Difficulty: " + encounter.difficulty + "\n";
    newEncounter += "Enemies-\n";
    for (int j = 0; j < encounter.creatures.size();j++)
    {
        newEncounter += encounter.creatures[j].getName() + " #\n";
    }

    std::ofstream EncounterFile;
    EncounterFile.open("encounter.txt", std::ios::out | std::ios::app);
    EncounterFile << "\n" << newEncounter;
};