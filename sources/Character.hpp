//
// Created by shora on 19/05/2023.
//

#pragma once

#include <string>
#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
    public:
        Character(const std::string &name, const Point &location, int hit_points);

        //Virtual destructor
        virtual ~Character() = default;


        bool isAlive() const;


        double distance(const Character &other) const;

        // New distance method that takes a pointer like the test file requires
        double distance(const Character *other) const;

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        std::string print() const;

        virtual std::string getType() const = 0;

    protected:
        std::string name;
        Point location;
        int hit_points;
    };
}