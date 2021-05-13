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
            Board _player_board;
            map <City, int> _player_city_cards;
            map <Color, int> _player_color_cards;
            map <City, bool> _research_stations;
            map <Color, bool> _cures_discovered;

        public:
            Player(Board& brd, City city);
            Player& take_card(City city);
            virtual Player& build();
            Player& drive(City city);
            virtual Player& treat(City city);
            virtual Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            virtual Player& discover_cure(Color color);
            virtual string role();
    };
}