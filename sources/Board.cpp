#include "Board.hpp"

namespace pandemic {
    Board::Board() {
        _disease_map[Algiers]=make_pair(Black, 0);
        _connection_map[Algiers]={Madrid, Paris, Istanbul, Cairo};
        _disease_map[Atlanta]=make_pair(Blue, 0);
        _connection_map[Atlanta]={Chicago, Miami, Washington};
        _disease_map[Baghdad]=make_pair(Black, 0);
        _connection_map[Baghdad]={Tehran, Istanbul, Cairo, Riyadh, Karachi};
        _disease_map[Bangkok]=make_pair(Red, 0);
        _connection_map[Bangkok]={Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong};
        _disease_map[Beijing]=make_pair(Red, 0);
        _connection_map[Beijing]={Shanghai, Seoul};
        _disease_map[Bogota]=make_pair(Yellow, 0);
        _connection_map[Bogota]={MexicoCity, Lima, Miami, SaoPaulo, BuenosAires};
        _disease_map[BuenosAires]=make_pair(Yellow, 0);
        _connection_map[BuenosAires]={Bogota, SaoPaulo};
        _disease_map[Cairo]=make_pair(Black, 0);
        _connection_map[Cairo]={Algiers, Istanbul, Baghdad, Khartoum, Riyadh};
        _disease_map[Karachi]=make_pair(Black, 0);
        _connection_map[Karachi]={Tehran, Baghdad, Riyadh, Mumbai, Delhi};
        _disease_map[Johannesburg]=make_pair(Yellow, 0);
        _connection_map[Johannesburg]={Kinshasa, Khartoum};
        _disease_map[Jakarta]=make_pair(Red, 0);
        _connection_map[Jakarta]={Chennai, Bangkok, HoChiMinhCity, Sydney};
        _disease_map[Istanbul]=make_pair(Black, 0);
        _connection_map[Istanbul]={Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow};
        _disease_map[HongKong]=make_pair(Red, 0);
        _connection_map[HongKong]={Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei};
        _disease_map[HoChiMinhCity]=make_pair(Red, 0);
        _connection_map[HoChiMinhCity]={Jakarta, Bangkok, HongKong, Manila};
        _disease_map[Essen]=make_pair(Blue, 0);
        _connection_map[Essen]={London, Paris, Milan, StPetersburg};
        _disease_map[Delhi]=make_pair(Black, 0);
        _connection_map[Delhi]={Tehran, Karachi, Mumbai, Chennai, Kolkata};
        _disease_map[Chicago]=make_pair(Blue, 0);
        _connection_map[Chicago]={SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal};
        _disease_map[Chennai]=make_pair(Black, 0);
        _connection_map[Chennai]={Mumbai, Delhi, Kolkata, Bangkok, Jakarta};
        _disease_map[MexicoCity]=make_pair(Yellow, 0);
        _connection_map[MexicoCity]={LosAngeles, Chicago, Miami, Lima, Bogota};
        _disease_map[Manila]=make_pair(Red, 0);
        _connection_map[Manila]={Taipei, SanFrancisco, HoChiMinhCity, Sydney};
        _disease_map[Madrid]=make_pair(Blue, 0);
        _connection_map[Madrid]={London, NewYork, Paris, SaoPaulo, Algiers};
        _disease_map[LosAngeles]=make_pair(Yellow, 0);
        _connection_map[LosAngeles]={SanFrancisco, Chicago, MexicoCity, Sydney};
        _disease_map[London]=make_pair(Blue, 0);
        _connection_map[London]={NewYork, Madrid, Essen, Paris};
        _disease_map[Lima]=make_pair(Yellow, 0);
        _connection_map[Lima]={MexicoCity, Bogota, Santiago};
        _disease_map[Lagos]=make_pair(Yellow, 0);
        _connection_map[Lagos]={SaoPaulo, Khartoum, Kinshasa};
        _disease_map[Kolkata]=make_pair(Black, 0);
        _connection_map[Kolkata]={Delhi, Chennai, Bangkok, HongKong};
        _disease_map[Kinshasa]=make_pair(Yellow, 0);
        _connection_map[Kinshasa]={Lagos, Khartoum, Johannesburg};
        _disease_map[Khartoum]=make_pair(Yellow, 0);
        _connection_map[Khartoum]={Cairo, Lagos, Kinshasa, Johannesburg};
        _disease_map[Miami]=make_pair(Yellow, 0);
        _connection_map[Miami]={Atlanta, MexicoCity, Washington, Bogota};
        _disease_map[Milan]=make_pair(Blue, 0);
        _connection_map[Milan]={Essen, Paris, Istanbul};
        _disease_map[Montreal]=make_pair(Blue, 0);
        _connection_map[Montreal]={Chicago, Washington, NewYork};
        _disease_map[Moscow]=make_pair(Black, 0);
        _connection_map[Moscow]={StPetersburg, Istanbul, Tehran};
        _disease_map[Mumbai]=make_pair(Black, 0);
        _connection_map[Mumbai]={Karachi, Delhi, Chennai};
        _disease_map[NewYork]=make_pair(Blue, 0);
        _connection_map[NewYork]={Montreal, Washington, London, Madrid};
        _disease_map[Osaka]=make_pair(Red, 0);
        _connection_map[Osaka]={Taipei, Tokyo};
        _disease_map[Paris]=make_pair(Blue, 0);
        _connection_map[Paris]={Algiers, Essen, Madrid, Milan, London};
        _disease_map[Riyadh]=make_pair(Black, 0);
        _connection_map[Riyadh]={Baghdad, Cairo, Karachi};
        _disease_map[SanFrancisco]=make_pair(Blue, 0);
        _connection_map[SanFrancisco]={LosAngeles, Chicago, Tokyo, Manila};
        _disease_map[Santiago]=make_pair(Yellow, 0);
        _connection_map[Santiago]={Lima};
        _disease_map[SaoPaulo]=make_pair(Yellow, 0);
        _connection_map[SaoPaulo]={Bogota, BuenosAires, Lagos, Madrid};
        _disease_map[Seoul]=make_pair(Red, 0);
        _connection_map[Seoul]={Beijing, Shanghai, Tokyo};
        _disease_map[Shanghai]=make_pair(Red, 0);
        _connection_map[Shanghai]={Beijing, HongKong, Taipei, Seoul, Tokyo};
        _disease_map[StPetersburg]=make_pair(Blue, 0);
        _connection_map[StPetersburg]={Essen, Istanbul, Moscow};
        _disease_map[Sydney]=make_pair(Red, 0);
        _connection_map[Sydney]={Jakarta, Manila, LosAngeles};
        _disease_map[Taipei]=make_pair(Red, 0);
        _connection_map[Taipei]={Shanghai, HongKong, Osaka, Manila};
        _disease_map[Tehran]=make_pair(Black, 0);
        _connection_map[Tehran]={Baghdad, Moscow, Karachi, Delhi};
        _disease_map[Tokyo]=make_pair(Red, 0);
        _connection_map[Tokyo]={Seoul, Shanghai, Osaka, SanFrancisco};
        _disease_map[Washington]=make_pair(Blue, 0);
        _connection_map[Washington]={Atlanta, NewYork, Montreal, Miami};
    }

    int& Board::operator[] (City city) {
        return _disease_map[city].second;
    }

    ostream& operator<< (ostream& stream, const Board& Board) {
        return stream;
    }

    bool Board::is_clean() {
        return true;
    }

    void Board::remove_cures() {
    }
}

