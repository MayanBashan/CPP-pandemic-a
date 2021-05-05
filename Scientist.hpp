#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class Scientist : public Player{
        public:
            string player_role;
            int cards_num;
            pandemic::Board board;
            pandemic::City city;

            Scientist();
            Scientist(Board &_board, City _city){
                    this->board = _board;
                    this->city = _city;
            }
            Scientist(Board &_board, City _city, int _cards_num){
                    this->board = _board;
                    this->city = _city;
                    this->cards_num = _cards_num;
            }
            ~Scientist(){}; // destructor
            string role() const;
            void discover_cure(Color color);
    };
}