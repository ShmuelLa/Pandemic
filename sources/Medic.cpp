#include "Medic.hpp"

namespace pandemic {
    Medic::Medic(Board& board, City city) : Player(board, city) {
    }

    string Medic::role() {
        return "Medic";
    }
}