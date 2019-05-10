#include "Arena.h"

std::vector<Fight> Arena::get_fights()
{
    return std::vector<Fight>();
}

void Arena::load_fights(std::string filename)
{

}

void Arena::run_all()
{
    for (Fight * current_fight : fights)
    {
        int winner_id = current_fight->start_fight();
        std::cout << "Winner id: " << winner_id << std::endl;
    }
}

int Arena::run_fight(Fight * new_fight)
{
    fights.push_back(new_fight);
    return new_fight->start_fight();
}
