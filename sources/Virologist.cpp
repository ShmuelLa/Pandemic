#include "Virologist.hpp"

namespace pandemic {
    
    Virologist::Virologist(Board& board, City city) : Player(board, city) {
    }

    Player& Virologist::treat(City city) {
        if (_current_city == city) {
            if (_player_board._disease_map[_current_city].second == 0) {
                throw("Virologist - No disease cubes in current city");
            }
            Color _currect_city_color = _player_board._disease_map[city].first;
            if (_player_board._cures_discovered[_currect_city_color]) {
                _player_board[city] = 0;
                return *this;
            }
            _player_board[city]--;
            _player_city_cards[city]--;
            return *this;
        }
        if (_player_board._disease_map[city].second == 0) {
            throw("Virologist - No disease cubes in chosen city");
        }
        Color _chosen_city_color = _player_board._disease_map[city].first;
        if (_player_board._cures_discovered[_chosen_city_color]) {
            _player_board[city] = 0;
            _player_city_cards[city]--;
            return *this;
        }
        if (_player_city_cards[city] == 0) {
            throw("Virologist - don't have needed city card");
        }
        _player_board[city]--;
        _player_city_cards[city]--;
        return *this;

    }

    string Virologist::role() {
        return "Virologist";
    }
}
