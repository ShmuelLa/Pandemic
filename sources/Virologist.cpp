#include "Virologist.hpp"

namespace pandemic {
    
    Virologist::Virologist(Board& board, City city) : Player(board, city) {
    }

    string Virologist::role() {
        return "Virologist";
    }
}
