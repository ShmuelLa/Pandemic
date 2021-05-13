#include "Medic.hpp"

namespace pandemic {
    Medic::Medic(Board& board, City city) : Player(board, city) {
    }

    Player& Medic::treat(City city) {
        if (_player_board._disease_map[_current_city].second == 0) {
            throw("No disease cubes in current city");
        }
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
            return *this;
        }
        _player_board[_current_city] = 0;
        return *this;

    }

    Player& Medic::drive(City city) {
        if (_player_board._connection_map[_current_city].count(city) < 1) {
            throw("Medic - Cities are not connected!");
        }
        _current_city = city;
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color] && _player_board._disease_map[_current_city].second > 0) {
            _player_board[_current_city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City city) {
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_city_cards[city] > 0) {
            _player_city_cards[city]--;
            _current_city = city;
            if (!_player_board._cures_discovered[_currect_city_color]) {
                return *this;
            }
        }
        if (_player_board._cures_discovered[_currect_city_color] && _player_board._disease_map[_current_city].second > 0) {
            _player_board[_current_city] = 0;
            return *this;
        }
        throw("Medic - There is no connected city with availabe cards");      
    }

    Player& Medic::fly_charter(City city) {
        if (_player_board._connection_map[_current_city].count(city) >= 1 && _player_city_cards[_current_city] > 0) {
            _player_city_cards[_current_city]--;
            _current_city = city;
            return *this;
        }
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color] && _player_board._disease_map[_current_city].second > 0) {
            _player_board[_current_city] = 0;
        }
        throw("Medic - There is no connected city with availabe cards");  
    }

    Player& Medic::fly_shuttle(City city) {
        if (_player_board._research_stations[_current_city] && _player_board._research_stations[city]) {
            _current_city = city;
            return *this;
        }
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color] && _player_board._disease_map[_current_city].second > 0) {
            _player_board[_current_city] = 0;
        }
        throw("Medic - Current or targeted city has no research stations");
    }

    string Medic::role() {
        return "Medic";
    }
}