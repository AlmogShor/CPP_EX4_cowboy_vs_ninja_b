//
// Created by shora on 19/05/2023.
//

#include "TrainedNinja.hpp"

namespace ariel{
    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
            : Ninja(name, location, 12, 120) {} // Assuming speed = 10 and hit points = 100

}