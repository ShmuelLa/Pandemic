#include "GeneSplicer.hpp"

namespace pandemic {

    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city) {
    }

    Player& GeneSplicer::discover_cure(Color color) {
        if (!_player_board._research_stations[_current_city]) {
            throw("GeneSplicer - Don't have research station in current city");
        }
        const int _cards_needed = 5;
        int cards_count = 0;
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_color_cards[_currect_city_color] >= _cards_needed) {
            if (_player_board._cures_discovered[_currect_city_color] && _player_board._research_stations[_current_city]) {
                return *this;
            }
            if (_player_board._research_stations[_current_city]) {
                _player_color_cards[_currect_city_color] -= _cards_needed;
                _player_board._cures_discovered[_currect_city_color] = true;
                return *this;
            }
        }
        for (auto& cards : _player_color_cards) {
            if (cards.first == color && cards.second > 0) {
                cards_count += cards.second;
            }
        }
        if (cards_count >= _cards_needed) {
            cards_count = 0;
            while (cards_count < _cards_needed) {
                for (auto& cards : _player_color_cards) {
                    if (cards.first == color && cards.second > 0) {
                        cards_count++;
                        cards.second--;
                    }
                }
            }
            return *this;
        }
        throw("GeneSplicer - Can't discover cure, insufficient color cards");
    }

    string GeneSplicer::role() {
        return "GeneSplicer";
    }
}