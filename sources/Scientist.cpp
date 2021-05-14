#include "Scientist.hpp"

namespace pandemic {
    
    Scientist::Scientist(Board& board, City city, int num) : Player(board, city), _cards_needed_for_cure(num) {
    }

    Player& Scientist::discover_cure(Color color) {
        if (!_player_board._research_stations[_current_city]) {
            throw("Scientist - Don't have research station in current city");
        }
        if (_player_board._cures_discovered[color]) {
            return *this;
        }
        int card_count = 0;
        for (auto &cards : _player_city_cards) {
            if (cards.second > 0 && _player_board._disease_map[cards.first].first == color) {
                card_count++;
            }
        }
        if (card_count < _cards_needed_for_cure) {
            throw("Scientist - Can't discover cure, insufficient color cards");
        }
        card_count = 0;
        for (auto &cards : _player_city_cards) {
            if (_player_board._disease_map[cards.first].first == color) {
                card_count++;
                cards.second--;
            }
            if (card_count == _cards_needed_for_cure) {
                break;
            }
        }
        _player_board._cures_discovered[color] = true;
        return *this;
    }

    string Scientist::role() {
        return "Scientist";
    }
}