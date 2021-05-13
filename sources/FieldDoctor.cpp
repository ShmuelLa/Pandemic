#include "FieldDoctor.hpp"

namespace pandemic {
    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city) {
    }

    string FieldDoctor::role() {
        return "FieldDoctor";
    }
}