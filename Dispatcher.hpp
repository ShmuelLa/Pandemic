#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Dispatcher : public Player {
        public:
            Dispatcher(Board board, City city);
    };
}