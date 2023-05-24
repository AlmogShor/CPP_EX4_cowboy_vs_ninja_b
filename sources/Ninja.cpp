//
// Created by shora on 19/05/2023.
//

#include "Ninja.hpp"


namespace ariel {
    Ninja::Ninja(const std::string &name, const Point &location, int speed, int hit_points)
            : Character(name, location, hit_points), speed(speed) {}


    void Ninja::move(Character *enemy) {
        if (!enemy) {
            throw std::invalid_argument("Cannot move towards a null character");
        }

        Point enemy_location = enemy->getLocation();
        Point ninja_location = this->getLocation();
        double distance_to_enemy = ninja_location.distance(enemy_location);

        // If the enemy is within 1 meter, attack.
        if (distance_to_enemy <= 1) {
//            this->slash(enemy);
        } else {
            // Move towards the enemy if the enemy is more than 1 meter away.
            Point new_location = ninja_location.moveTowards(ninja_location, enemy_location, speed);
            // Need to add a method in Character class to update the location.
            this->setLocation(new_location);
        }
    }


    void Ninja::slash(Character *enemy) const {
        if (!enemy) {
            throw std::invalid_argument("Cannot attack a null character");
        }

        if (!(enemy->isAlive())) {
            throw std::runtime_error("Cannot attack a dead enemy Charachter");
        }
        if (!(this->isAlive())) {
            throw std::runtime_error("A dead team can't attack");
        }
        if (this == enemy) {
            throw std::runtime_error("A team cannot attack itself");
        }


        // Perform damage calculation and attack the enemy.
        int damage = 40; // Assuming damage is 40 constant
        enemy->hit(damage);
    }

    std::string Ninja::print() {
        return "Ninja";
    }
}
