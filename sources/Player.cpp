#include "Player.hpp"

namespace pandemic {
    
    Player& Player::take_card(City city) {
        return *this;
    }

    Player& Player::build() {
        if (_player_city_cards[_current_city] > 0 && _research_stations[_current_city]) {
            return *this;
        }
        if (_player_city_cards[_current_city] > 0) {
            _player_city_cards[_current_city]--;
            _research_stations[_current_city] = true;
            return *this;
        }
        throw("Player has no cards to build");
    }

    Player& Player::drive(City city) {
        if (_player_board._connection_map[_current_city].count(city) < 1) {
            throw("Cities are not connected!");
        }
        _current_city = city;
        return *this;
    }

    Player& Player::fly_direct(City city) {
        if (_player_board._connection_map[_current_city].count(city) >= 1 && _player_city_cards[city] > 0) {
            _player_city_cards[city]--;
            _current_city = city;
            return *this;
        }
        throw("There is no connected city with availabe cards");      
    }

    Player& Player::fly_charter(City city) {
        if (_player_board._connection_map[_current_city].count(city) >= 1 && _player_city_cards[_current_city] > 0) {
            _player_city_cards[_current_city]--;
            _current_city = city;
            return *this;
        }
        throw("There is no connected city with availabe cards");  
    }

    Player& Player::fly_shuttle(City city) {
        if (_research_stations[_current_city] && _research_stations[city]) {
            _current_city = city;
            return *this;
        }
        throw("Current or targeted city has no research stations");
    }

    Player& Player::treat(City city) {
        if (_player_board._disease_map[_current_city].second == 0) {
            throw("No disease cubes in current city");
        }
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
            return *this;
        }
        _player_board[_current_city]--;
        return *this;
    }

    Player& Player::discover_cure(Color color) {
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_cures_discovered[_currect_city_color] && _player_color_cards[_currect_city_color] > 4) {
            return *this;
        }
        if (_player_color_cards[_currect_city_color] > 4) {
            _player_color_cards[_currect_city_color] -= 5;
            _cures_discovered[_currect_city_color] = true;
            return *this;
        }
        throw("Can't discover cure, insufficient color cards");
    }

    string Player::role() {
        return "Player";
    }
}