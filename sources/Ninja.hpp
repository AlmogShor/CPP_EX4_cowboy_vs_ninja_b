//
// Created by shora on 19/05/2023.
//

#pragma once

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    public:
        Ninja(const std::string &name, const Point &location, int speed, int hit_points);

        void move(const Character *enemy); // the ninja moves towards the enemy with the equal distance to his speed

        // the ninja slashes the enemy with 40 damage constant and only if he is in range of 1 meter
        void slash(Character *enemy) const;

        std::string print() override;

        std::string getType() const override {
            return "Ninja";
        }

    private:
        int speed;
    };

}