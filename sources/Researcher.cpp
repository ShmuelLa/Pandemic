#include "Researcher.hpp"

namespace pandemic {
    Researcher::Researcher(Board& board, City city) : Player(board, city) {
    }

    Player& Researcher::discover_cure(Color color) {
        const int _cards_needed = 5;
        if (_player_board._cures_discovered[color]) {
            return *this;
        }
        int card_count = 0;
        for (auto &cards : _player_city_cards) {
            if (cards.second > 0 && _player_board._disease_map[cards.first].first == color) {
                card_count++;
            }
        }
        if (card_count < _cards_needed) {
            throw("Researcher - Can't discover cure, insufficient color cards");
        }
        card_count = 0;
        while (card_count < _cards_needed) {
            for (auto &cards : _player_city_cards) {
                if (_player_board._disease_map[cards.first].first == color) {
                    card_count++;
                    cards.second--;
                }
            }
        }
        return *this;
    }

    string Researcher::role() {
        return "Researcher";
    }
}