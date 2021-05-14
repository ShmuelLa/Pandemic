#include "FieldDoctor.hpp"

namespace pandemic {
    
    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city) {
    }

    Player& FieldDoctor::treat(City city) {
        if (_player_board._connection_map[_current_city].count(city) < 1
            && city != _current_city) {
            throw("FieldDoctor - City is not connected to current city");
        }
        if (_player_board._disease_map[city].second == 0) {
            throw("FieldDoctor - No disease cubes in current city");
        }
        Color _chosen_city_color = _player_board._disease_map[city].first;
        if (_player_board._cures_discovered[_chosen_city_color]) {
            _player_board[_current_city] = 0;
            return *this;
        }
        _player_board[city]--;
        return *this;

    }

    string FieldDoctor::role() {
        return "FieldDoctor";
    }
}