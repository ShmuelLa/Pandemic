#include "Player.hpp"

namespace pandemic {

    Player::Player(Board& brd, City city) : _player_board(brd) {
        _current_city = city;
        for (auto &card : _player_city_cards) {
            card.second = 0;
        }
    }
    
    Player& Player::take_card(City city) {
        if (_player_city_cards[city] == 0) {
            _player_city_cards[city]++;
        }
        return *this;
    }

    Player& Player::build() {
        if (_player_board._research_stations[_current_city]) {
            return *this;
        }
        if (_player_city_cards[_current_city] > 0) {
            _player_city_cards[_current_city]--;
            _player_board._research_stations[_current_city] = true;
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
        if (_current_city == city) {
            throw("Player - Can't Fly direct to current city");
        }
        if (_player_city_cards[city] > 0) {
            _player_city_cards[city]--;
            _current_city = city;
            return *this;
        }
        throw("Player - Can't Fly direct, no availabe cards");
    }

    Player& Player::fly_charter(City city) {
        if (_current_city == city) {
            throw("Player - Can't Fly charter to current city");
        }
        if (_player_city_cards[_current_city] > 0) {
            _player_city_cards[_current_city]--;
            _current_city = city;
            return *this;
        }
        throw("Player - There is no connected city with availabe cards");  
    }

    Player& Player::fly_shuttle(City city) {
        if (_current_city ==city) {
            throw("Player - Can't fly shuttle to same city");
        }
        if (_player_board._research_stations[_current_city] && _player_board._research_stations[city]) {
            _current_city = city;
            return *this;
        }
        throw("Player - Current or targeted city has no research stations");
    }

    Player& Player::treat(City city) {
        if (_player_board._disease_map[_current_city].second == 0) {
            throw("Player - No disease cubes in current city");
        }
        Color _currect_city_color = _player_board._disease_map[_current_city].first;
        if (_player_board._cures_discovered[_currect_city_color]) {
            _player_board[_current_city] = 0;
            return *this;
        }
        _player_board[_current_city]--;
        return *this;
    }

    Player& Player::discover_cure(Color color) {
        if (!_player_board._research_stations[_current_city]) {
            throw("Player - Don't have research station in current city");
        }
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
            throw("Player - Can't discover cure, insufficient color cards");
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
        _player_board._cures_discovered[color] = true;
        return *this;
    }

    string Player::role() {
        return "Player";
    }

    Player& Player::remove_cards() {
        for (auto &card : _player_city_cards) {
            card.second = 0;
        }
        return *this;
    }
}