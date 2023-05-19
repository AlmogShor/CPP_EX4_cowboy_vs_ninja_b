//
// Created by shora on 19/05/2023.
//

#include "Character.hpp"
#include <stdexcept>

namespace ariel {
    Character::Character(const std::string &name, const Point &location, int hit_points)
            : name(name), location(location), hit_points(hit_points) {}

    bool Character::isAlive() const {
        return hit_points > 0;
    }

    double Character::distance(const Character &other) const {
        return location.distance(other.location);
    }

    void Character::hit(int damage) {
        hit_points -= damage;
        if (hit_points < 0) hit_points = 0;
    }

    std::string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    void Character::print() const {
        std::cout << "Character(" << name << ", " << "HP: " << hit_points << ", " << "Location: ";
        location.print();
        std::cout << ")\n";
    }
}
