//
// Created by shora on 19/05/2023.
//

#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

namespace ariel {
    class Point {
    public:
        Point() : x(0), y(0) {}

        Point(double x, double y);

        double distance(const Point &other) const;

        void print() const;

        Point moveTowards(const Point &source, const Point &target, double distance) const;

        //getters
        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

    private:
        double x;
        double y;
    };
}