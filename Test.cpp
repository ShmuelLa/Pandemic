/**
 * @file Test.cpp
 * @author Shmuel.Lavian
 * @brief Pandemic assignment first part testings
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <string>
using namespace std;
using namespace pandemic;

TEST_CASE("Board") {
    Board board;
    CHECK(board.is_clean());
	board[City::Tehran] = 3;
    CHECK_FALSE(board.is_clean());
    CHECK(board[City::Tehran] == 3);
    CHECK_FALSE(board[City::Tehran] == 4);
}

TEST_CASE("Player") {
    Board board;
    OperationsExpert ope {board, City::Tehran};
    Virologist viro {board, City::Tehran};
    Medic med {board, City::Tehran};
    Dispatcher dis {board, City::Tehran};
    GeneSplicer gene {board, City::Tehran};
    Researcher red {board, City::Tehran};
    Scientist sci {board, City::Tehran, 5};
    FieldDoctor field {board, City::Tehran};
    CHECK_EQ(ope.role(), "OperationsExpert");
    CHECK_FALSE(ope.role() == "FieldDoctor");
    CHECK_EQ(field.role(), "FieldDoctor");
    CHECK_EQ(sci.role(), "Scientist");
    CHECK_FALSE(sci.role() == "FieldDoctor");
    CHECK_EQ(red.role(), "Researcher");
    CHECK_FALSE(red.role() == "FieldDoctor");
    CHECK_EQ(gene.role(), "GeneSplicer");
    CHECK_FALSE(gene.role() == "FieldDoctor");
    CHECK_EQ(dis.role(), "Dispatcher");
    CHECK_FALSE(dis.role() == "FieldDoctor");
    CHECK_EQ(med.role(), "Medic");
    CHECK_EQ(viro.role(), "Virologist");
    CHECK_NOTHROW(ope.take_card(City::Tehran));
    CHECK_NOTHROW(ope.take_card(City::Tehran).take_card(City::Tehran).take_card(City::Tehran).take_card(City::Tehran));
}

TEST_CASE("Player") {
    Board board;
	board[City::Tehran] = 3;
    Scientist sci {board, City::Tehran, 3};
    CHECK_THROWS(sci.discover_cure(Color::Black));
    sci.take_card(City::Tehran).take_card(City::Tehran).take_card(City::Tehran);
    CHECK_NOTHROW(sci.discover_cure(Color::Black));
    CHECK_THROWS(sci.discover_cure(Color::Red));
    CHECK_THROWS(sci.discover_cure(Color::Yellow));
    CHECK_THROWS(sci.discover_cure(Color::Blue));
}