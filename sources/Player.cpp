#include "Player.hpp"

namespace pandemic {
    
    Player& Player::take_card(City city) {
        return *this;
    }

    Player& Player::build() {
        return *this;
    }

    Player& Player::drive(City city) {
        if (_player_board._connection_map[_current_city].count(city) < 1) {
            throw("Cities are not connected!");
        }
        _current_city = city;
        return *this;
    }

    Player& Player::fly_direct(City city) {
        return *this;
    }

    Player& Player::fly_charter(City city) {
        return *this;
    }

    Player& Player::fly_shuttle(City city) {
        return *this;
    }

    Player& Player::treat(City city) {
        return *this;
    }

    Player& Player::discover_cure(Color color) {
        return *this;
    }

    string Player::role() {
        return "role";
    }
}