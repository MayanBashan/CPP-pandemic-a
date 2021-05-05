/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
#include <map>
#include "Color.hpp"
#include "City.hpp"

using namespace std;

namespace pandemic{
    
    class Board{
        map<City, int> cities;
        public:
            Board(){};
            ~Board(){}; // destructor
            
            int& operator[](City city);
            static bool is_clean();
            void remove_cures();
            friend ostream& operator <<(ostream& output, const Board& board); //?? friend

    };
}