//
// Created by shora on 19/05/2023.
//

#include "Character.hpp"
#include <stdexcept>
#include <sstream>

namespace ariel {
    Character::Character(const std::string &name, const Point &location, int hit_points)
            : name(name), location(location), hit_points(hit_points) {}

    bool Character::isAlive() const {
        return hit_points > 0;
    }

    double Character::distance(const Character &other) const {
        return location.distance(other.location);
    }
    // New distance implementation that takes a pointer like the test file requires
    double Character::distance(const Character *other) const {
        if (other == nullptr) {
            throw std::invalid_argument("Argument to distance cannot be null");
        }
        return distance(*other);
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

    std::string Character::print() const {
        std::stringstream ss;
        ss << "Character(" << name << ", " << "HP: " << hit_points << ", " << "Location: ";
        ss << location.getX() << ", " << location.getY() << ")\n";
        return ss.str();
    }
}
