#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    
    class Player{
        public:
            pandemic::Board board;
            pandemic::City city;
            Player();
            Player(Board &_board, City _city){
                this->board = _board;
                this->city = _city;
            }
            ~Player(){}; // destructor
            Player& drive(City city);
            virtual Player& fly_direct(City city); //for Dispatcher
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            virtual Player& build(); //for OperationsExpert
            virtual void discover_cure(Color color); //for Scientist | for Researcher | for GeneSplicer
            virtual Player& treat(City city); //for Medic | for Virologist | for FieldDoctor
            Player& take_card(City city); 
            static string role();
    };
}