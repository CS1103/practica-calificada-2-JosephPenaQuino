#ifndef PC2_ARENA_H
#define PC2_ARENA_H

#include "Fight.h"
#include "Fighter.h"
#include <vector>
#include <string>
#include <iostream>
#include "BruceLee.h"
#include "ChuckNorris.h"
#include "JasonStatham.h"
#include "Defense.h"
#include "Elude.h"
#include "Shield.h"
#include "Armor.h"
#include "Attack.h"
#include "Punch.h"
#include "Saber.h"
#include "Firearm.h"
#include <sstream>

class Arena
{
private:
    std::vector<Fight*> fights;
    Fighter * get_fighter(std::string line, int id);
    void get_defense(Fighter * f, std::string line);
    void get_attack(Fighter * f, std::string line);

public:
    Arena() = default;
    std::vector<Fight> get_fights();
    void load_fights(std::vector<std::string> filename);
    void run_all();
    int run_fight(Fight *new_fight);
};


#endif //PC2_ARENA_H
