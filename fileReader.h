#ifndef FILEREADER_12314123
#define FILEREADER_12314123

#include <iostream>
#include <string>
#include "role.h"
#include "creature.h"

class FileReader
{
    public:
        void ReadRolesFromFile(vector <Role> &roles);
        void ReadCreaturesFromFile(vector <Creature> &creatures);
        void RemoveCreatureFromFile(Creature sp, string fileName);
        void RemovePersonRoleFromFile(Role role, string filename);
        Role createRole(vector <Role> roles);
        Creature createSpecies(vector <Creature> species_vector);
        
};


#endif