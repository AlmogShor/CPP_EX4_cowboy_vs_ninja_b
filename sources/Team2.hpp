//
// Created by shora on 19/05/2023.
//

#pragma once

#include <vector>
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {
    private:
        std::vector<Character *> fighters;
        Character *leader;


    public:
        Team2(Character *leader);

        ~Team2();

        void add(Character *fighter) override;

        void attack(Team *enemy) override;


        void print() override;


    };

    class SmartTeam : public Team2 {
    private:
        std::vector<Character *> fighters;
        Character *leader;

    public:
        SmartTeam(Character *leader);


        void attack(Team *enemy) override;


    };
}

