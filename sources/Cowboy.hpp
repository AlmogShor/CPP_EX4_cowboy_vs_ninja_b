//
// Created by shora on 19/05/2023.
//

#pragma once

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    public:
        Cowboy(const std::string &name, const Point &location);

        void shoot(Character *enemy);

        bool hasBullets() const;

        bool hasboolets() const;    // Typo on purpose in the test file

        void reload();

        int getAmmo() const {
            return bullets;
        }

        std::string print() override;

        std::string getType() const override {
            return "Cowboy";
        }

    private:
        int bullets;
    };
}