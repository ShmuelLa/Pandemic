#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic {

    class Board {
        private:
            typedef pair <Color, int> city_stats;
            static map <City, city_stats> _disease_map;
            static map <City, set<City>> _connection_map;

        public:
            Board();
            int& operator[] (City city);
            bool is_clean();
            friend ostream& operator<< (ostream& stream, const Board& board);
            void remove_cures();
    };
}