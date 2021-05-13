#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Medic : public Player {
        public:
            Medic(Board& board, City city);
            virtual Player& treat(City city) override;
            virtual Player& drive(City city) override;
            virtual Player& fly_direct(City city) override;
            virtual Player& fly_charter(City city) override;
            virtual Player& fly_shuttle(City city) override;
            virtual string role() override;
    };
}