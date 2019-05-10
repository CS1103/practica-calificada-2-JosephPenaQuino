#include "Attack.h"

int Attack::attack()
{
    return power;
}

Attack::Attack(int power) : power{power} {}
