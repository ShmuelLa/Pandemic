#include "Researcher.hpp"

namespace pandemic {
    Researcher::Researcher(Board& board, City city) : Player(board, city) {
    }

    Player& Researcher::discover_cure(Color color) {
        const int _cards_needed = 5;
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color] 
            && _player_color_cards[_currect_city_color] >= _cards_needed) {
            return *this;
        }
        if (_player_color_cards[_currect_city_color] >= _cards_needed) {
            _player_color_cards[_currect_city_color] -= _cards_needed;
            _player_board._cures_discovered[_currect_city_color] = true;
            return *this;
        }
        throw("Researcher - Can't discover cure, insufficient color cards");

    }

    string Researcher::role() {
        return "Researcher";
    }
}