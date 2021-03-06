#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic {

    class Board {
        protected:
            typedef pair <Color, int> city_stats;

        public:
            Board();
            map <City, city_stats> _disease_map;
            map <City, set<City>> _connection_map;
            map <City, bool> _research_stations;
            map <Color, bool> _cures_discovered;
            int& operator[] (City city);
            bool is_clean();
            friend ostream& operator<< (ostream& stream, const Board& board);
            void remove_cures();
            void remove_stations();
    };
}