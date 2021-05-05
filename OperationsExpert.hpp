#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    
    class OperationsExpert : public Player{
        public:
            string player_role;
            pandemic::Board board;
            pandemic::City city;

            OperationsExpert();
            OperationsExpert(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
                }
            ~OperationsExpert(){}; // destructor
            string role() const;
            Player& build();
    };
}