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
        protected:
            City _current_city;
            Board& _player_board;
            map <City, int> _player_city_cards;

        public:
            Player(Board& brd, City city);
            Player& take_card(City city);
            virtual Player& build();
            virtual Player& drive(City city);
            virtual Player& treat(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& discover_cure(Color color);
            virtual string role();
            Player& remove_cards();
    };
}