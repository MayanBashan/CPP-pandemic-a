#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class FieldDoctor : public Player{
        public:
            string player_role;
            pandemic::Board board;
            pandemic::City city;

            FieldDoctor();
            FieldDoctor(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
                }
            ~FieldDoctor(){}; // destructor
            string role() const;
            Player& treat(City city);
    };
}