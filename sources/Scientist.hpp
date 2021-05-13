#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist : public Player {
        private:
            int _cards_needed_for_cure;
        public:
            Scientist(Board& board, City city, int num);
    };
}