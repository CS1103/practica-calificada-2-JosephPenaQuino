#include "catch.hpp"

#include "Arena.h"
#include "Fight.h"
#include "Fighter.h"
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

#include <iostream>
#include <fstream>
#include <sstream>

SCENARIO("PC2 POO2")
{
    GIVEN("An Arena with 2 fights")
    {
        Arena arena1;
        Elude D_E;
        Shield D_S;
        Armor D_A;
        Punch A_P;
        Saber A_S;
        Firearm A_F;

        WHEN("ChuckNorris(Defense: E, S; Attack: P, S) meets JasonStatham(Defense: S, A; Attack: S, F)")
        {
            const int id_CN1 = 1;
            const int id_JS1 = 2;
            ChuckNorris CN1(id_CN1);
            CN1.obtain_defense(&D_E);
            CN1.obtain_defense(&D_S);
            CN1.obtain_attack(&A_P);
            CN1.obtain_attack(&A_S);
            JasonStatham JS1(id_JS1);
            JS1.obtain_defense(&D_S);
            JS1.obtain_defense(&D_A);
            JS1.obtain_attack(&A_S);
            JS1.obtain_attack(&A_F);

            THEN("ChuckNorris and JasonStatham Fights")
            {
                Fight F1(&CN1, &JS1);
                int id_winner_1 = arena1.run_fight(&F1);
                arena1.get_fights();
                REQUIRE(id_winner_1==id_JS1);
            }
        }
        WHEN("JasonStatham(Defense: S, A; Attack: P, S) meets BruceLee(Defense: E, S, A; Attack: P, S, F)")
        {
            const int id_JS2 = 3;
            const int id_BS1 = 4;
            JasonStatham JS2(id_JS2);
            JS2.obtain_defense(&D_S);
            JS2.obtain_defense(&D_A);
            JS2.obtain_attack(&A_P);
            JS2.obtain_attack(&A_S);
            BruceLee BS1(id_BS1);
            BS1.obtain_defense(&D_E);
            BS1.obtain_defense(&D_S);
            BS1.obtain_defense(&D_A);
            BS1.obtain_attack(&A_P);
            BS1.obtain_attack(&A_S);
            BS1.obtain_attack(&A_F);

            THEN("JasonStatham vs BruceLee")
            {
                Fight F2(&JS2, &BS1);
                int id_winner_2 = arena1.run_fight(&F2);
                arena1.get_fights();
                REQUIRE(id_winner_2 == id_BS1);
            }
        }
    }

    GIVEN("An Arena reading 'peleas.txt'")
    {
        const std::string SEARCH_FILE = "peleas.txt";
        Arena arena2;
        std::ifstream inFile;

        inFile.open(SEARCH_FILE);
        if (!inFile)
        {
            std::cerr << "Unable to open file "<< SEARCH_FILE;
            exit(1);
        }
        std::vector<std::string> text;
        std::string current_line;
        while (inFile >> current_line)
            text.push_back(current_line);

//        arena2.load_fights(text);

        WHEN("Running all fights")
        {
            THEN("")
            {
                REQUIRE(true);
            }
        }
    }
}