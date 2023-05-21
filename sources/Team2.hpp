//
// Created by shora on 19/05/2023.
//

#pragma once

#include <vector>
#include "Team.hpp"

namespace ariel {
    class Team2 {
    private:
        std::vector<Character *> fighters;
        Character *leader;


    public:
        Team2(Character *leader);

        ~Team2();

        void add(Character *fighter);

        void attack(Team2 *enemy);

        bool stillAlive();

        void print();


    };

    class SmartTeam {
    private:
        std::vector<Character *> fighters;
        Character *leader;

    public:
        SmartTeam(Character *leader);

        ~SmartTeam();

        void add(Character *fighter);

        void attack(SmartTeam *enemy);

        bool stillAlive();

        void print();
    };
}

