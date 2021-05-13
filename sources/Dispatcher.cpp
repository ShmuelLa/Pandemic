#include "Dispatcher.hpp"

namespace pandemic {
    
    Dispatcher::Dispatcher(Board& board, City city) : Player(board, city) {
    }

    Player& Dispatcher::fly_direct(City city) {
        if (_player_board._connection_map[_current_city].count(city) >= 1 && _research_stations[_current_city]) {
            _current_city = city;
            return *this;
        }
        if (_player_board._connection_map[_current_city].count(city) >= 1 && _player_city_cards[city] > 0) {
            _player_city_cards[city]--;
            _current_city = city;
            return *this;
        }
        throw("There is no connected city with availabe cards");   
    }

    string Dispatcher::role() {
        return "Dispatcher";
    }
}