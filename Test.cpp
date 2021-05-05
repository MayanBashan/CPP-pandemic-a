/**
 * Unit tests for Pandemic exercise
 * AUTHOR: Mayan Bashan
 * Date: 2021-05
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
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace pandemic;
using namespace std;
    
    TEST_CASE("OperationsExpert Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        OperationsExpert player {board, City::Miami};
        player.take_card(City::Washington).take_card(City::Lagos).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco);
        CHECK_NOTHROW(player.build()); //can build in any city without throwing the matching card
        CHECK_THROWS(player.fly_direct(City::Kinshasa));
        player.treat(player.city);
        CHECK_EQ(board[player.city], 5);
        CHECK_EQ(player.role(), "OperationsExpert");
    }

    TEST_CASE("Dispatcher Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 1;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        Dispatcher player {board, City::Washington};
        player.take_card(City::Miami).take_card(City::Lagos).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco);
        CHECK_THROWS(player.build()); //cannot build a station in Washington cause he does not have it's card
        player.take_card(City::Washington);
        CHECK_NOTHROW(player.build()); //now can build a station
        CHECK_NOTHROW(player.fly_direct(City::Kinshasa)); //can fly to a city even if he does not have the city card
        player.treat(player.city);
        CHECK_EQ(board[player.city], 0);
        CHECK_THROWS(player.treat(player.city)); // board[Washington] = 0, so will throw an exeption when try to treat 
        CHECK_EQ(player.role(), "Dispatcher");
    }

    TEST_CASE("Scientist Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 1;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        Scientist player {board, City::Washington, 3};
        player.take_card(City::Miami).take_card(City::Lagos).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork);
        CHECK_THROWS(player.build()); //cannot build a station in Washington cause he does not have it's card
        player.take_card(City::Washington);
        CHECK_NOTHROW(player.build()); //now can build a station
        CHECK_THROWS(player.fly_direct(City::Kinshasa)); //cannot fly to a city if he does not have the city card
        player.treat(player.city);
        CHECK_EQ(board[player.city], 0);
        CHECK_THROWS(player.treat(player.city)); // board[Washington] = 0, so will throw an exeption when try to treat 
        CHECK_NOTHROW(player.discover_cure(Blue)); // can discover cure because it has at least 3 cards of blue disease 
        CHECK_EQ(player.role(), "Scientist");
    }

    TEST_CASE("Researcher Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 1;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        Researcher player {board, City::Washington};
        player.take_card(City::Miami).take_card(City::Lagos).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork);
        CHECK_THROWS(player.build()); //cannot build a station in Washington cause he does not have it's card        
        CHECK_THROWS(player.fly_direct(City::Kinshasa)); //cannot fly to a city if he does not have the city card
        player.treat(player.city);
        CHECK_EQ(board[player.city], 0);
        CHECK_THROWS(player.treat(player.city)); // board[Washington] = 0, so will throw an exeption when try to treat 
        CHECK_NOTHROW(player.discover_cure(Blue)); // can discover cure even if city does not have a station
        CHECK_EQ(player.role(), "Researcher");
    }
    
    TEST_CASE("Medic Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 9;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        Medic player {board, City::Washington};
        player.take_card(City::Miami).take_card(City::Lagos).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork);
        CHECK_THROWS(player.build()); //cannot build a station in Washington cause he does not have it's card        
        CHECK_THROWS(player.fly_direct(City::Kinshasa)); //cannot fly to a city if he does not have the city card
        player.treat(player.city); // remove all disease cubes from city
        CHECK_EQ(board[player.city], 0);
        board[City::Washington] = 3;
        CHECK_NOTHROW(player.discover_cure(Blue)); // can discover cure even if city does not have a station
        CHECK_EQ(board[player.city], 0); // needs to be 0 because cure was discovered
        CHECK_EQ(player.role(), "Medic");
    }

    TEST_CASE("Virologist Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 9;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        Virologist player {board, City::HoChiMinhCity};
        player.take_card(City::Miami).take_card(City::Chicago).take_card(City::Chennai).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork);
        player.treat(City::Chicago); //can treat a disease in any city in the world by throwing city's card
        player.treat(City::Miami); //can treat a disease in any city in the world by throwing city's card
        CHECK_EQ(board[City::Chicago], 0);
        CHECK_EQ(board[City::Miami], 5);
        CHECK_THROWS(player.treat(City::Miami)); // cannot treat a disease in Kinshasa because he doesn't have Kinshasa's card
        CHECK_EQ(player.role(), "Virologist");
    }
    
     TEST_CASE("GeneSplicer Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Kinshasa] = 3;
        board[City::Kinshasa] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 9;
        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        GeneSplicer player {board, City::HoChiMinhCity};
        player.take_card(City::Miami).take_card(City::Chicago).take_card(City::HoChiMinhCity).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork).take_card(City::Essen);
        player.build();
        player.treat(City::Chicago); //can treat a disease in any city in the world by throwing city's card
        player.treat(City::Miami); //can treat a disease in any city in the world by throwing city's card
        CHECK_EQ(board[City::Chicago], 0);
        CHECK_EQ(board[City::Miami], 5);
        CHECK_THROWS(player.discover_cure(Color::Yellow)); // can discover cure by throwing 5 blue cards (he doesn't have to throw 5 yellow cards)
        CHECK_EQ(player.role(), "GeneSplicer");
    }

    TEST_CASE("FieldDoctor Player"){
        Board board;
        CHECK(board.is_clean() == true);
        board[City::Bogota] = 3;
        board[City::BuenosAires] = 2;
        board[City::MexicoCity] = 3;
        board[City::HoChiMinhCity] = 1;
        board[City::Chicago] = 1; 
        board[City::Miami] = 6;
        board[City::Washington] = 9;

        CHECK_FALSE(board.is_clean());
        CHECK(board[City::Kinshasa] == 2);

        FieldDoctor player {board, City::SaoPaulo};
        player.take_card(City::Miami).take_card(City::Chicago).take_card(City::HoChiMinhCity).take_card(City::Delhi).take_card(City::SanFrancisco).take_card(City::SanFrancisco).take_card(City::Paris).take_card(City::NewYork).take_card(City::Essen);
        player.build();
        player.treat(City::Bogota); //can treat a disease in any city that is connected to SaoPaulo
        player.treat(City::BuenosAires); //can treat a disease in any city that is connected to SaoPaulo
        CHECK_EQ(board[City::Bogota], 2);
        CHECK_EQ(board[City::BuenosAires], 1);
        player.treat(City::HoChiMinhCity); //can treat by throwing HoChiMinhCity card
        CHECK_EQ(board[City::HoChiMinhCity], 0);
        CHECK_THROWS(player.treat(City::SanFrancisco)); // cannot treat - SanFrancisco does not connected to SaoPaulo, and player doesn't have SanFrancisco's card
        CHECK_EQ(player.role(), "FieldDoctor");
    }