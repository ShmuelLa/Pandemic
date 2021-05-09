#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <string>
using std::string;

namespace pandemic {

    class Player {
        public:
            Player& take_card(City city);
            Player& build();
            Player& drive(City city);
            Player& treat(City city);
            Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            Player& discover_cure(Color color);
            string role();
    };
}