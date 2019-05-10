#include "Fight.h"

Fight::Fight(Fighter *a, Fighter *b) : a{a}, b{b}, winner{nullptr}, score{0 ,0} {}

int Fight::start_fight()
{
    score[0] = a->defense() - b->attack();
    score[1] = b->defense() - a->attack();
    winner = score[0] > score[1] ? a : b;
    return winner->get_id();
}
