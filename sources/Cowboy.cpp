//
// Created by shora on 19/05/2023.
//

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(const std::string &name, const Point &location)
            : Character(name, location, 100), bullets(6) {} // Assuming initial bullets = 6

    void Cowboy::shoot(Character *enemy) {
        if (bullets > 0) {
            enemy->hit(20); // Assuming each bullet causes 20 damage
            bullets--;
        }
    }
    bool Cowboy::hasBullets() const {
        return bullets > 0;
    }

    bool Cowboy::hasboolets() const {
        return hasBullets();
    }

    void Cowboy::reload() {
        bullets = 6; // Assuming full ammo is 6 bullets
    }

}
