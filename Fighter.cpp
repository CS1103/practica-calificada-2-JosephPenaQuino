#include "Fighter.h"

Fighter::Fighter(int id) : id{id} {}

int Fighter::attack()
{
    int sum_attack = 0;
    for(Attack *current_attack : stats_attack)
    {
        sum_attack += current_attack->attack();
    }
    return sum_attack;
}

int Fighter::defense()
{
    int sum_defense = 0;
    for(Defense *current_defense : stats_defense)
    {
        sum_defense += current_defense->defense();
    }
    return sum_defense;
}

void Fighter::obtain_defense(Defense * new_defense)
{
    stats_defense.push_back(new_defense);
}

void Fighter::obtain_attack(Attack * new_attack)
{
    stats_attack.push_back(new_attack);
}

int Fighter::get_id()
{
    return id;
}
