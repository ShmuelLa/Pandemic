#pragma once
#include <map>
#include "City.hpp"
using namespace std;

namespace pandemic {

    class Board {
        private:
            map <City, int> _disease_map;

        public:
            Board();
            int& operator[] (City city);
            string is_clean();
            friend ostream& operator<< (ostream& stream, const Board& board);
            void remove_cures();
    };
}