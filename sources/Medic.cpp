#include "Medic.hpp"

namespace pandemic {
    
    Medic::Medic(Board& board, City city) : Player(board, city) {
    }

    Player& Medic::treat(City city) {
        if (city != _current_city) {
            throw("Medic - can't treat other city");
        }
        if (_player_board._disease_map[city].second == 0) {
            throw("Medic - No disease cubes in current city");
        }
        Color _currect_city_color = _player_board._disease_map[city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[city] = 0;
            return *this;
        }
        _player_board[city] = 0;
        return *this;

    }

    Player& Medic::drive(City city) {
        Player::drive(city);
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City city) {
        Player::fly_direct(city);
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City city) {
        Player::fly_charter(city);
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
        }
        return *this; 
    }

    Player& Medic::fly_shuttle(City city) {
        Player::fly_shuttle(city);
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
        }
        return *this; 
    }

    string Medic::role() {
        return "Medic";
    }
}