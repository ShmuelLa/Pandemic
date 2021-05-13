#include "OperationsExpert.hpp"

namespace pandemic {

    OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city) {
    }

    Player& OperationsExpert::build() {
        if (_player_board._research_stations[_current_city]) {
            return *this;
        }
        _player_board._research_stations[_current_city] = true;
        return *this;
    }

    string OperationsExpert::role() {
        return "OperationsExpert";
    }
}