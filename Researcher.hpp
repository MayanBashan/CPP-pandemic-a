#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class Researcher : public Player{
        public:
            string player_role;
            pandemic::Board board;
            pandemic::City city;

            Researcher();
            Researcher(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
                }
            ~Researcher(){}; // destructor
            string role() const;
            void discover_cure(Color color);
    };
}