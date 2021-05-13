#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class GeneSplicer : public Player {
        public:
            GeneSplicer(Board& board, City city);
            virtual Player& discover_cure(Color color) override;
            virtual string role() override;
    };
}