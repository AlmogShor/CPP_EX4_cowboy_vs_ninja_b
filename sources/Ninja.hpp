//
// Created by shora on 19/05/2023.
//

#pragma once

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    public:
        Ninja(const std::string &name, const Point &location, int speed, int hit_points);

        void move(const Character *enemy);

        void slash(Character *enemy) const;

    protected:
        int speed;
    };

}