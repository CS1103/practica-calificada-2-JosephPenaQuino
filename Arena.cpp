#include "Arena.h"

std::vector<Fight> Arena::get_fights()
{
    return std::vector<Fight>();
}

void Arena::load_fights(std::vector<std::string> filename)
{
    int state_fighter = 0;
    int state_fight = 0;
    int current_id = 0;
    for(std::string current_line : filename)
    {
        Fighter * f = nullptr;
        if (state_fighter == 0)
        {
            f = get_fighter(current_line, current_id);
            current_id++;
            state_fighter = 1;
        }
        else if (state_fighter == 1)
        {
            get_defense(f, current_line);
            state_fighter = 2;
        }
        else if (state_fighter == 2)
        {
            get_attack(f, current_line);
            state_fighter = 0;
        }

    }
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

Fighter * Arena::get_fighter(std::string line, int id)
{
    if(line == "BL")
    {
        auto * fighter = new BruceLee(id);
        return (BruceLee*)fighter;
    }
    else if (line == "CN")
    {
        auto * fighter = new ChuckNorris(id);
        return (ChuckNorris*) fighter;
    }
    else if (line == "JS")
    {
        auto * fighter = new JasonStatham(id);
        return (JasonStatham*) fighter;
    }
    else
    {
        return nullptr;
    }

}

void Arena::get_defense(Fighter * f, std::string line)
{
    std::stringstream ss(line);
    std::string current_defense;

    while (getline(ss, current_defense, ','))
    {
        if (current_defense == "E")
        {
            auto * E = new Elude;
            f->obtain_defense(E);
        }
        else if (current_defense == "S")
        {
            auto * S = new Shield;
            f->obtain_defense(S);
        }
        else if (current_defense == "A")
        {
            auto * A = new Armor;
            f->obtain_defense(A);
        }
    }
}

void Arena::get_attack(Fighter * f, std::string line)
{
    std::stringstream ss(line);
    std::string current_attack;

    while (getline(ss, current_attack, ','))
    {
        if (current_attack == "P")
        {
            auto * E = new Punch;
            f->obtain_attack(E);
        }
        else if (current_attack == "S")
        {
            auto * S = new Saber;
            f->obtain_attack(S);
        }
        else if (current_attack == "F")
        {
            auto * F = new Firearm;
            f->obtain_attack(F);
        }
    }

}
