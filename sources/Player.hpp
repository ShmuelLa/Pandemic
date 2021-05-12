#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <string>
#include <set>
using std::string;
using std::set;

namespace pandemic {

    class Player {
        private:
            set <City> _cities;
            City _current_city;
            Board _player_board;
            map <City, int> _player_cards;

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