#include "Board.hpp"

namespace pandemic {
    Board::Board() {
    }

    int& Board::operator[] (City city) {
        return _disease_map[city];
    }

    ostream& operator<< (ostream& stream, const Board& Board) {
        return stream;
    }

    bool Board::is_clean() {
        return true;
    }

    void Board::remove_cures() {
    }
}

