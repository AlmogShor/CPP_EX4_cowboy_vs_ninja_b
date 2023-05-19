//
// Created by shora on 19/05/2023.
//

#include "Point.hpp"

#include <stdexcept>
#include <iostream>

namespace ariel {
    Point::Point(double x, double y) : x(x), y(y) {}

    double Point::distance(const Point &other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    Point Point::moveTowards(const Point &source, const Point &target, double distance) {
        if (distance < 0) {
            throw std::invalid_argument("Distance can't be negative");
        }
        double totalDistance = source.distance(target);
        if (distance > totalDistance) {
            return target;
        }
        double ratio = distance / totalDistance;
        double newX = source.x + ratio * (target.x - source.x);
        double newY = source.y + ratio * (target.y - source.y);
        return Point(newX, newY);
    }

    void Point::print() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
}
