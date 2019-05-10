#ifndef PC2_FIGHTER_H
#define PC2_FIGHTER_H

#include "Defense.h"
#include "Attack.h"
#include <vector>

class Fighter
{
private:
    std::vector<Defense*> stats_defense;
    std::vector<Attack*> stats_attack;
    int id;
public:
    explicit Fighter(int id);
    int attack();
    int defense();
    void obtain_defense(Defense * new_defense);
    void obtain_attack(Attack * new_attack);
    int get_id();

};


#endif //PC2_FIGHTER_H
