//
// Created by shora on 19/05/2023.
//

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(const std::string &name, const Point &location)
            : Character(name, location, 100), bullets(6) {} // Assuming initial bullets = 6

    void Cowboy::shoot(Character *enemy) {
        if (!enemy) {
            throw std::invalid_argument("Cannot attack a null team");
        }
        if (!(enemy->isAlive())) {
            throw std::runtime_error("Cannot attack a dead team");
        }
        if (!(this->isAlive())) {
            throw std::runtime_error("A dead team can't attack");
        }
        if (this == enemy) {
            throw std::runtime_error("A team cannot attack itself");
        }


        if (bullets > 0) {
            enemy->hit(10); // Assuming each bullet causes 20 damage
            bullets--;
        }
        if (!hasBullets()) {
//            this->reload();
//            printf("out of ammo");
        }
    }

    bool Cowboy::hasBullets() const {
        return bullets > 0;
    }

    bool Cowboy::hasboolets() const {
        return hasBullets();
    }

    void Cowboy::reload() {
        if (!(this->isAlive()))
            throw std::runtime_error("A dead cowboy cant reload");
        bullets = 6; // Assuming full ammo is 6 bullets
    }

    std::string Cowboy::print() {
        return "";
    }

}
