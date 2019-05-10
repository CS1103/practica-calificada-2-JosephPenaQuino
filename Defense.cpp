#include "Defense.h"

int Defense::defense()
{
    return level;
}

Defense::Defense(int level) : level{level} {}
