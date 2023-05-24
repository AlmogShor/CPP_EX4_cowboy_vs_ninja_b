//
// Created by shora on 15/05/2023.
//

#include "Team.hpp"
#include <iostream>
#include <sstream>
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_SUITE("point class methods") {
    TEST_CASE("constructor") {
        SUBCASE("default constructor") {
            Point p1;
            CHECK(p1.getX() == 0);
            CHECK(p1.getY() == 0);
        }
        SUBCASE("constructor with parameters") {
            Point p1(1, 2);
            CHECK(p1.getX() == 1);
            CHECK(p1.getY() == 2);
        }
    }

    TEST_CASE("distance") {
        Point p1(1, 2);
        Point p2(3, 4);
        CHECK(p1.distance(p2) == sqrt(8));
    }

    TEST_CASE("print") {
        Point p1(1, 2);
        ostringstream oss;
        p1.print();
        CHECK(oss.str() == "(1, 2)");
    }

    TEST_CASE("moveTowards") {
        Point p1(1, 2);
        Point p2(3, 4);
        Point p3(2, 3);
        CHECK(p1.moveTowards(p1, p2, 1).getX() == p3.getX());
        CHECK(p1.moveTowards(p1, p2, 1).getY() == p3.getY());
    }

    TEST_CASE("getters") {
        Point p1(1, 2);
        CHECK(p1.getX() == 1);
        CHECK(p1.getY() == 2);
    }
}

TEST_SUITE("charachter class methods") {
    TEST_CASE("constructor") {

        SUBCASE("constructor with parameters") {
            Point p1(1, 2);
            Character c1("shora", p1, 100);
            CHECK(c1.getName() == "shora");
            CHECK(c1.getLocation().getX() == 1);
            CHECK(c1.getLocation().getY() == 2);
            CHECK(c1.isAlive() == true);
        }
    }

    TEST_CASE("distance") {
        Point p1(1, 2);
        Point p2(3, 4);
        Character c1("shora", p1, 100);
        Character c2("shora", p2, 100);
        CHECK(c1.distance(c2) == sqrt(8));
    }

    TEST_CASE("hit") {
        Point p1(1, 2);
        Character c1("shora", p1, 100);
        c1.hit(50);
        CHECK(c1.isAlive() == true);
        c1.hit(50);
        CHECK(c1.isAlive() == false);
    }

    TEST_CASE("isAlive") {
        Point p1(1, 2);
        Character c1("shora", p1, 100);
        CHECK(c1.isAlive() == true);
        c1.hit(100);
        CHECK(c1.isAlive() == false);
    }

    TEST_CASE("getters") {
        SUBCASE("getName") {
            Point p1(1, 2);
            Character c1("shora", p1, 100);
            CHECK(c1.getName() == "shora");
        }
        SUBCASE("getLocation") {
            Point p1(1, 2);
            Character c1("shora", p1, 100);
            CHECK(c1.getLocation().getX() == 1);
            CHECK(c1.getLocation().getY() == 2);
        }
    }

    TEST_CASE("print") {
        Point p1(1, 2);
        Character c1("shora", p1, 100);
        ostringstream oss;
        c1.print();
        CHECK(oss.str() == "shora at (1, 2)");
    }

}
TEST_SUITE("Cowboy class method") {
    TEST_CASE("constructor") {
        SUBCASE("constructor with parameters") {
            Point p1(1, 2);
            Cowboy c1("shora", p1);
            CHECK(c1.getName() == "shora");
            CHECK(c1.getLocation().getX() == 1);
            CHECK(c1.getLocation().getY() == 2);
            CHECK(c1.isAlive() == true);
        }
    }

    TEST_CASE("distance") {
        Point p1(1, 2);
        Point p2(3, 4);
        Cowboy c1("shora", p1);
        Cowboy c2("shora", p2);
        CHECK(c1.distance(c2) == sqrt(8));
    }

    TEST_CASE("shoot") {
        Point p1(1, 2);
        Point p2(3, 4);
        Cowboy c1("shora", p1);
        Cowboy c2("shora", p2);
        c1.shoot(&c2);
        CHECK(c2.isAlive() == false);
    }

    TEST_CASE("reload") {
        Point p1(1, 2);
        Cowboy c1("shora", p1);
        Cowboy c2("123", p1);
        c1.shoot(&c2);
        c1.reload();
        CHECK(c1.getAmmo() == 6);
    }

    TEST_CASE("hasBullets") {
        Point p1(1, 2);
        Cowboy c1("shora", p1);
        CHECK(c1.hasBullets() == true);
        for (int i = 0; i < 6; i++) {
            c1.shoot(&c1);
        }
        CHECK(c1.hasBullets() == false);
    }
}
TEST_SUITE("Ninja class methods") {
    TEST_CASE("constructors") {
        SUBCASE("constructor with parameters") {
            Point p1(1, 2);
            Ninja n1("shora", p1, 1, 21);
            CHECK(n1.getName() == "shora");
            CHECK(n1.getLocation().getX() == 1);
            CHECK(n1.getLocation().getY() == 2);
            CHECK(n1.isAlive() == true);

        }
    }
}
