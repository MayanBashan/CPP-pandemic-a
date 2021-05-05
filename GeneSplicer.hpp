#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class GeneSplicer : public Player{
        public:
            string player_role;
            pandemic::Board board;
            pandemic::City city;

            GeneSplicer();
            GeneSplicer(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
                }
            ~GeneSplicer(){}; // destructor
            string role() const;
            void discover_cure(Color color);
    };
}