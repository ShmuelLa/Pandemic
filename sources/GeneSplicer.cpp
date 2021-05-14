#include "GeneSplicer.hpp"

namespace pandemic {

    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city) {
    }

    Player& GeneSplicer::discover_cure(Color color) {
        if (!_player_board._research_stations[_current_city]) {
            throw("GeneSplicer - Don't have research station in current city");
        }
        const int _cards_needed = 5;
        if (_player_board._cures_discovered[color]) {
            return *this;
        }
        int card_count = 0;
        for (auto &cards : _player_city_cards) {
            if (cards.second > 0) {
                card_count++;
            }
        }
        if (card_count < _cards_needed) {
            throw("GeneSplicer - Can't discover cure, insufficient color cards");
        }
        card_count = 0;
        while (card_count < _cards_needed) {
            for (auto &cards : _player_city_cards) {
                if (cards.second > 0) {
                    card_count++;
                    cards.second--;
                }
            }
        }
        _player_board._cures_discovered[color] = true;
        return *this;
    }

    string GeneSplicer::role() {
        return "GeneSplicer";
    }
}