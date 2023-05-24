#include "Team.hpp"

namespace ariel {
    Team::Team(Character *leader) : leader(leader), highest_cowboy_position(0), lowest_ninja_position(10) {
        if (leader->getHasTeam()) {
            throw std::runtime_error("Leader already in other team");
        }
        fighters.push_back(leader);
        leader->setInTeam(true);
        if (leader->getType() == "Cowboy") {
            highest_cowboy_position = 0;
        } else {
            lowest_ninja_position = 9;
        }
    }

    Team::~Team() {

    }

    /**
      * Add a fighter to the team.
      * This function adds the fighter at the right position in the fighters vector,
      * following the rule: "Cowboys" first, then "Ninjas".
      * Within each group, the fighters are sorted by their order of addition.
      *
      * @param fighter: The fighter to add to the team.
      * @throws std::runtime_error: If the team is full, the fighter is already in a team,
      *                             or the fighter is already in a different team.
      */
    void Team::add(Character *fighter) {
        if (fighters.size() >= MAX_TEAM_SIZE) {
            throw std::runtime_error("Team is full");
        }
        for (Character *member: fighters) {
            if (member == fighter) {
                throw std::runtime_error("Character already in a team");
            }
        }
        if (fighter->getHasTeam()) {
            throw std::runtime_error("Character already in a different team");
        }
        fighter->setInTeam(true);

        if (fighter->getType() == "Cowboy") {
            highest_cowboy_position++;
        } else {
            lowest_ninja_position--;
        }
// Check if the leader is alive. If not, appoint the closest teammate to the deceased leader as the new leader.
        if (!leader->isAlive()) {
            double closest_distance = std::numeric_limits<double>::max();
            for (Character *potential_leader: fighters) {
                if (potential_leader->isAlive() && leader->distance(*potential_leader) < closest_distance) {
                    closest_distance = leader->distance(*potential_leader);
                    leader = potential_leader;
                }
            }
        }
        orderFighters(fighter);
    }

    /**
     * Helper function to maintain the order of fighters in the team.
     * "Cowboys" are always at the beginning of the vector, followed by "Ninjas".
     * Within each group, the fighters are sorted by their order of addition.
     *
     * @param newFighter: The new fighter to add to the vector.
     */
    void Team::orderFighters(Character *newFighter) {
        if (newFighter->getType() == "Cowboy") {
            if (highest_cowboy_position <= fighters.size()) {
                fighters.insert(fighters.begin() + highest_cowboy_position - 1, newFighter);
            } else {
                fighters.push_back(newFighter);
            }
        } else {
            if (highest_cowboy_position + lowest_ninja_position <= fighters.size()) {
                fighters.insert(fighters.begin() + highest_cowboy_position + lowest_ninja_position, newFighter);
            } else {
                fighters.push_back(newFighter);
            }
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
        Character *victim = nullptr;
        Character *closest_victim = nullptr;
        double closest_distance = std::numeric_limits<double>::max();

// Check if the leader is alive. If not, appoint the closest teammate to the deceased leader as the new leader.
        if (!leader->isAlive()) {
            for (Character *potential_leader: fighters) {
                if (potential_leader->isAlive() && leader->distance(*potential_leader) < closest_distance) {
                    closest_distance = leader->distance(*potential_leader);
                    leader = potential_leader;
                }
            }
        }

// Select the enemy fighter closest to the leader as the victim.
        closest_distance = std::numeric_limits<double>::max();
        for (Character *potential_victim: enemy->fighters) {
            if (potential_victim->isAlive() && leader->distance(*potential_victim) < closest_distance) {
                closest_distance = leader->distance(*potential_victim);
                victim = potential_victim;
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
            for (Character *potential_victim: enemy->fighters) {
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

    int Team::stillAlive() {
        int alive_count = 0;
        // Check if the leader is alive. If not, appoint the closest teammate to the deceased leader as the new leader.
        if (!leader->isAlive()) {
            double closest_distance = std::numeric_limits<double>::max();
            for (Character *potential_leader: fighters) {
                if (potential_leader->isAlive() && leader->distance(*potential_leader) < closest_distance) {
                    closest_distance = leader->distance(*potential_leader);
                    leader = potential_leader;
                }
            }
        }
        for (Character *fighter: fighters) {
            if (fighter != nullptr && fighter->isAlive()) {
                alive_count++;
            }
        }
        return alive_count;
    }

    void Team::print() {
        std::cout << "Team:\n";
        for (Character *fighter: fighters) {
            fighter->print();
        }
    }
}
