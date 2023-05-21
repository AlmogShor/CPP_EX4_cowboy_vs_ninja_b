//
// Created by shora on 19/05/2023.
//

#include "Ninja.hpp"



namespace ariel {
    Ninja::Ninja(const std::string &name, const Point &location, int speed, int hit_points)
            : Character(name, location, hit_points), speed(speed) {}

    void Ninja::move(const Character *enemy) {
        if (!enemy) {
            throw std::invalid_argument("Cannot move towards a null character");
        }

        Point enemy_location = enemy->getLocation();
        Point ninja_location = this->getLocation();

        // Move towards enemy using speed and the distance from the enemy.

        this->getLocation().moveTowards(ninja_location, enemy_location, speed); // (x, y) = (x0 + x_direction * speed, y0 + y_direction * speed)


    }

    void Ninja::slash(Character *enemy) const {
        if (!enemy) {
            throw std::invalid_argument("Cannot attack a null character");
        }

        // Perform damage calculation and attack the enemy.
        int damage = 10; // Arbitrary value, replace with actual damage calculation.
        enemy->hit(damage);
    }
}
