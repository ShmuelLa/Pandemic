#include "Scientist.hpp"

namespace pandemic {
    
    Scientist::Scientist(Board& board, City city, int num) : Player(board, city), _cards_needed_for_cure(num) {
    }
}