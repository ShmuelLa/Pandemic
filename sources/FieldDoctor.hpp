#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class FieldDoctor : public Player {
        public:
            FieldDoctor(Board& board, City city);
            virtual Player& treat(City city) override;
            virtual string role() override;
    };
}