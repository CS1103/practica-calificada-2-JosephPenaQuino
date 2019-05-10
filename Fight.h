#ifndef PC2_FIGHT_H
#define PC2_FIGHT_H

#include "Fighter.h"

class Fight
{
private:
    Fighter * a;
    Fighter * b;
    Fighter * winner;
    int score[2];
public:
    Fight(Fighter * a, Fighter * b);
    int start_fight();

};


#endif //PC2_FIGHT_H
