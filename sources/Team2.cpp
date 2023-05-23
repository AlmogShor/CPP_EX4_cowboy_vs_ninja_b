//
// Created by shora on 19/05/2023.
//

#include "Team2.hpp"


namespace ariel {
    Team2::Team2(Character *leader) : Team(leader) {}

    Team2::~Team2() {}

    void Team2::attack(Team2 *enemy) {
        // Implement attack logic specific to Team2
        // Here, for example, the leader attacks first followed by each fighter
        getLeader()->attack(enemy);
        for (auto fighter: fighters) {
            if (fighter->isAlive()) {
                fighter->attack(enemy);
            }
        }
    }
}

// SmartTeam.cpp

namespace ariel {
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    SmartTeam::~SmartTeam() {}

    void SmartTeam::attack(SmartTeam *enemy) {
        // Implement attack logic specific to SmartTeam
        // Here, for example, the leader chooses the best fighter to attack
        Character *bestFighter = fighters[0]; // Assuming fighters[0] is the best initially
        for (auto fighter: fighters) {
            if (fighter->isAlive() && fighter->getSkillLevel() > bestFighter->getSkillLevel()) {
                bestFighter = fighter;
            }
        }
        bestFighter->attack(enemy);
    }
}


namespace ariel {
    Team2::Team2(Character *leader) : leader(leader) {
        fighters.push_back(leader);
    }

    Team2::~Team2() {
        for (Character *fighter : fighters) {
            delete fighter;
        }
    }

    void Team2::add(Character *fighter) {
        for (Character *member : fighters) {
            if (member == fighter) {
                throw std::runtime_error("Character already in a team");
            }
        }
        fighters.push_back(fighter);
    }

    void Team2::attack(Team2 *enemy) {
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
        Character *victim = enemy->fighters[0]; // Again, you might need to find the closest fighter
        for (Character *fighter : fighters) {
            if (!fighter->isAlive() || enemy->stillAlive() <= 0) {
                break;
            }
            if (!victim->isAlive()) {
                victim = enemy->fighters[0]; // Again, you might need to find the next alive fighter
            }
            if (fighter->getType() == "C") {
                dynamic_cast<Cowboy*>(fighter)->shoot(victim);
            } else if (fighter->getType() == "N") {
                if (fighter->distance(victim) <= 1) {
                    dynamic_cast<Ninja*>(fighter)->slash(victim);
                } else {
                    dynamic_cast<Ninja*>(fighter)->move(victim);
                }
            }
        }
    }

    bool Team2::stillAlive() {
        for (Character *fighter : fighters) {
            if (fighter->isAlive()) {
                return true;
            }
        }
        return false;
    }

    void Team2::print() {
        std::cout << "Team2:\n";
        for (Character *fighter : fighters) {
            fighter->print();
        }
    }

    SmartTeam::SmartTeam(Character *leader) : leader(leader) {
        fighters.push_back(leader);
    }

    SmartTeam::~SmartTeam() {
        for (Character *fighter : fighters) {
            delete fighter;
        }
    }

    void SmartTeam::add(Character *fighter) {
        for (Character *member : fighters) {
            if (member == fighter) {
                throw std::runtime_error("Character already in a team");
            }
        }
        fighters.push_back(fighter);
    }

    void SmartTeam::attack(SmartTeam *enemy) {
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
        Character *victim = enemy->fighters[0]; // Again, you might need to find the closest fighter
        for (Character *fighter : fighters) {
            if (!fighter->isAlive() || enemy->stillAlive() <= 0) {
                break;
            }
            if (!victim->isAlive()) {
                victim = enemy->fighters[0]; // Again, you might need to find the next alive fighter
            }
            if (fighter->getType() == "C") {
                dynamic_cast<Cowboy*>(fighter)->shoot(victim);
            } else if (fighter->getType() == "N") {
                if (fighter->distance(victim) <= 1) {
                    dynamic_cast<Ninja*>(fighter)->slash(victim);
                } else {
                    dynamic_cast<Ninja*>(fighter)->move(victim);
                }
            }
        }
    }

    bool SmartTeam::stillAlive() {
        for (Character *fighter : fighters) {
            if (fighter->isAlive()) {
                return true;
            }
        }
        return false;
    }

    void SmartTeam::print() {
        std::cout << "SmartTeam:\n";
        for (Character *fighter : fighters) {
            fighter->print();
        }
    }
}

