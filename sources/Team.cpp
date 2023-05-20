//
// Created by shora on 9/05/2023.
//

#include "Team.hpp"

namespace ariel{
    Team::Team(Character *leader) : leader(leader) {
        fighters.push_back(leader);
    }

    Team::~Team() {
        for (Character *fighter : fighters) {
            delete fighter;
        }
    }

    void Team::add(Character *fighter) {
        if (fighters.size() >= MAX_TEAM_SIZE) {
            throw std::runtime_error("Team is full");
        }
        for (Character *member : fighters) {
            if (member == fighter) {
                throw std::runtime_error("Character already in a team");
            }
        }
        fighters.push_back(fighter);
    }

    void Team::attack(Team *enemy) {
        // To be implemented...
    }

    int Team::stillAlive() {
        int alive_count = 0;
        for (Character *fighter : fighters) {
            if (fighter->isAlive()) {
                alive_count++;
            }
        }
        return alive_count;
    }

    void Team::print() {
        std::cout << "Team:\n";
        for (Character *fighter : fighters) {
            fighter->print();
        }
    }
}
