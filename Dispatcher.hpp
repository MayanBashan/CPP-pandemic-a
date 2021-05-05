#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class Dispatcher : public Player{
        public:
            string player_role;
            pandemic::Board board;
            pandemic::City city;

        
            Dispatcher();
            Dispatcher(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
                }
            ~Dispatcher(){}; // destructor
            string role() const;
            Player& fly_direct(City city);
    };
}