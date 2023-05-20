//
// Created by shora on 19/05/2023.
//

#include "YoungNinja.hpp"

namespace ariel {
    YoungNinja::YoungNinja(const std::string &name, const Point &location)
            : Ninja(name, location, 5, 50) {} // Assuming speed = 5 and hit points = 50
}
