#include "Researcher.hpp"

namespace pandemic {
    Researcher::Researcher(Board& board, City city) : Player(board, city) {
    }

    string Researcher::role() {
        return "Researcher";
    }
}