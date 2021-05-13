#include "Scientist.hpp"

namespace pandemic {
    
    Scientist::Scientist(Board& board, City city, int num) : Player(board, city), _cards_needed_for_cure(num) {
    }

    Player& Scientist::discover_cure(Color color) {
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_cures_discovered[_currect_city_color] 
            && _player_color_cards[_currect_city_color] >= _cards_needed_for_cure
            && _player_board._research_stations[_current_city]) {
            return *this;
        }
        if (_player_color_cards[_currect_city_color] >= _cards_needed_for_cure
            && _player_board._research_stations[_current_city]) {
            _player_color_cards[_currect_city_color] -= _cards_needed_for_cure;
            _cures_discovered[_currect_city_color] = true;
            return *this;
        }
        throw("Scientist - Can't discover cure, insufficient color cards");

    }

    string Scientist::role() {
        return "Scientist";
    }
}