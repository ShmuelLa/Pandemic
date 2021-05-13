#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Researcher : public Player {
        public:
            Researcher(Board& board, City city);
    };
}