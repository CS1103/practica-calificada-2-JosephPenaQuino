#ifndef PC2_ARENA_H
#define PC2_ARENA_H

#include "Fight.h"
#include "Fighter.h"
#include <vector>
#include <string>
#include <iostream>

class Arena
{
private:
    std::vector<Fight*> fights;

public:
    Arena() = default;
    std::vector<Fight> get_fights();
    void load_fights(std::string filename);
    void run_all();
    int run_fight(Fight *new_fight);
};


#endif //PC2_ARENA_H
