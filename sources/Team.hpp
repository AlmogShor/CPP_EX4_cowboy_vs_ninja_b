//
// Created by shora on 9/05/2023.
//

#pragma once


#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"



#define MAX_TEAM_SIZE 10
namespace ariel {
    class Team {
    protected:
        std::vector<Character *> fighters;
        Character *leader;
        int highest_cowboy_position;
        int lowest_ninja_position;

    public:
        Team(Character *leader);

        Team(Team &other);

        //move ctor
        Team(Team &&other)

        noexcept;

        ~Team();

        virtual void add(Character *fighter);

        virtual void attack(Team *enemy);

        virtual int stillAlive();

        virtual void print();

        Character *getLeader() const {
            return leader;
        }
        std::vector<Character *> getFighters() const {
            return fighters;
        }

        // need to think about the following helper funcs
        /*
         *  virtual void check_change_leader();
        Character* find_closest(Team* Character);

        void setStrtedGame(bool set_to);
        void setTeamAt(Character *newmember, size_t at_i);
        void setLeader(size_t nleaderpos);
        Character* getLeader();
        Character* getLeaderStraight();
        Character* getTeamAt(size_t at_i);
        bool getStartedGame();
         Team& operator=(const Team& tem);
        Team& operator=(Team&& tem) noexcept;

        size_t actualSize() const;
         */
    };
}