#include "Team.hpp"

namespace ariel {
    Team::Team(Character *leader) : leader(leader), highest_cowboy_position(0), lowest_ninja_position(10) {
        fighters.push_back(leader);
        if (leader->getType() == "Cowboy") {
            highest_cowboy_position = 0;
        } else {
            lowest_ninja_position = 9;
        }
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
        if (fighter->getType() == "C") {
            highest_cowboy_position++;
        } else {
            lowest_ninja_position--;
        }
    }

    void Team::attack(Team *enemy) {
        if (!enemy) {
            throw std::invalid_argument("Cannot attack a null team");
        }
        if (enemy->stillAlive() == 0) {
            throw std::runtime_error("Cannot attack a dead team");
        }
        if (this->stillAlive() == 0) {
            throw std::runtime_error("A dead team can't attack");
        }
        if (this == enemy) {
            throw std::runtime_error("A team cannot attack itself");
        }
        Character *victim = enemy->fighters[0]; // You might need to find the closest fighter like in your friend's code
        for (Character *fighter : fighters) {
            if (!fighter->isAlive() || enemy->stillAlive() <= 0) {
                break;
            }
            if (!victim->isAlive()) {
                victim = enemy->fighters[0]; // You might need to find the next alive fighter
            }
            if (fighter->getType() == "Cowboy") {
                dynamic_cast<Cowboy*>(fighter)->shoot(victim);
            } else if (fighter->getType() == "Ninja") {
                if (fighter->distance(*victim) <= 1) {
                    dynamic_cast<Ninja*>(fighter)->slash(victim);
                } else {
                    dynamic_cast<Ninja*>(fighter)->move(victim);
                }
            }
        }
    }

    int Team::stillAlive() {
        int alive_count = 0;
        for (Character *fighter : fighters) {
            if (fighter != nullptr && fighter->isAlive()) {
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
