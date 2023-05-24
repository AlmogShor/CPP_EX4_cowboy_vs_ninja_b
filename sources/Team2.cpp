//
// Created by shora on 19/05/2023.
//

#include "Team2.hpp"

namespace ariel {
    Team2::Team2(Character *leader) : Team(leader) {
    }

    Team2::~Team2() {

    }

    void Team2::add(Character *fighter) {
        if (fighter->getHasTeam()) {
            throw std::runtime_error("Character already in a team");
        }
        Team::add(fighter); // Use the base class method
        fighter->setInTeam(true);
    }

    void Team2::attack(Team *enemy) {
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
        Character *victim = nullptr;
        for (Character *potential_victim: enemy->getFighters()) {
            if (potential_victim->isAlive()) {
                victim = potential_victim;
                break;
            }
        }
        for (Character *fighter: fighters) {
            if (!fighter->isAlive()) {
                continue;
            }
            if (enemy->stillAlive() <= 0) {
                break;
            }

            Character *closest_victim = nullptr;
            double closest_distance = std::numeric_limits<double>::max();
            for (Character *potential_victim: enemy->getFighters()) {
                if (potential_victim->isAlive()) {
                    double distance = fighter->distance(*potential_victim);
                    if (distance < closest_distance) {
                        closest_distance = distance;
                        closest_victim = potential_victim;
                    }
                }
            }

            if (closest_victim == nullptr) {
                break; // Stop attacking if there are no more enemies alive
            }
//            if (!victim->isAlive()) {
//                if (!victim->isAlive()) {
//                    bool foundAlive = false;
//                    for (Character *potential_victim: enemy->fighters) {
//                        if (potential_victim->isAlive()) {
//                            victim = potential_victim;
//                            foundAlive = true;
//                            break;
//                        }
//                    }
//                    if (!foundAlive) {
//                        break; // Stop attacking if there are no more enemies alive
//                    }
//                }
//            }
            if (fighter->getType() == "Cowboy") {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy->hasBullets()) {
                    cowboy->shoot(closest_victim);
                } else {
                    cowboy->reload();
                }
            } else if (fighter->getType() == "Ninja") {
                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                if (ninja->distance(*closest_victim) <= 1) {
                    ninja->slash(closest_victim);
                } else {
                    ninja->move(closest_victim);
                }
            }
        }
    }

//    int Team2::stillAlive() {
//        for (Character *fighter : fighters) {
//            if (fighter->isAlive()) {
//                return true;
//            }
//        }
//        return false;
//    }

    void Team2::print() {
        std::cout << "Team2:\n";
        for (Character *fighter: fighters) {
            fighter->print();
        }
    }

    SmartTeam::SmartTeam(Character *leader) : leader(leader), Team2(leader) {
        fighters.push_back(leader);
    }

//    SmartTeam::~SmartTeam() {
//        for (Character *fighter: fighters) {
//            delete fighter;
//        }
//    }

//    void SmartTeam::add(Character *fighter) {
//        for (Character *member: fighters) {
//            if (member == fighter) {
//                throw std::runtime_error("Character already in a team");
//            }
//        }
//        fighters.push_back(fighter);
//    }

    void SmartTeam::attack(Team *enemy) {
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
        Character *victim = enemy->getFighters()[0]; // Again, you might need to find the closest fighter
        for (Character *fighter: fighters) {
            if (!fighter->isAlive() || enemy->stillAlive() <= 0) {
                break;
            }
            if (!victim->isAlive()) {
                victim = enemy->getFighters()[0]; // Again, you might need to find the next alive fighter
            }
            if (fighter->getType() == "Cowboy") {
                dynamic_cast<Cowboy *>(fighter)->shoot(victim);
            } else if (fighter->getType() == "Ninja") {
                if (fighter->distance(victim) <= 1) {
                    dynamic_cast<Ninja *>(fighter)->slash(victim);
                } else {
                    dynamic_cast<Ninja *>(fighter)->move(victim);
                }
            }

        }
    }

//    int SmartTeam::stillAlive() {
//        for (Character *fighter : fighters) {
//            if (fighter->isAlive()) {
//                return true;
//            }
//        }
//        return false;
//    }

//    void SmartTeam::print() {
//        std::cout << "SmartTeam:\n";
//        for (
//            Character *fighter
//                : fighters) {
//            fighter->
//
//                    print();
//        }
//    }
}

