#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Medic : public Player {
        public:
            Medic(Board board, City city);
    };
}