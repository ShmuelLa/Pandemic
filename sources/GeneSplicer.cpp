#include "GeneSplicer.hpp"

namespace pandemic {

    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city) {
    }

    Player& GeneSplicer::discover_cure(Color color) {
        const int _cards_needed = 5;
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_cures_discovered[_currect_city_color] 
            && _player_color_cards[_currect_city_color] >= 5
            && _research_stations[_current_city]) {
            return *this;
        }
        if (_player_color_cards[_currect_city_color] >= 5
            && _research_stations[_current_city]) {
            _player_color_cards[_currect_city_color] -= _cards_needed;
            _cures_discovered[_currect_city_color] = true;
            return *this;
        }
        throw("Player - Can't discover cure, insufficient color cards");

    }

    string GeneSplicer::role() {
        return "GeneSplicer";
    }
}