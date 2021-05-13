#include "OperationsExpert.hpp"

namespace pandemic {

    OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city) {
    }

    Player& OperationsExpert::build() {
        if (_research_stations[_current_city]) {
            return *this;
        }
        _research_stations[_current_city] = true;
        return *this;
    }

    string OperationsExpert::role() {
        return "OperationsExpert";
    }
}