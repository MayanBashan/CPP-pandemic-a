/**
 * Author: Mayan Bashan
 */

#include <string>
#include <map>

using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"


namespace pandemic{
    int& Board::operator[](City city){return cities[city];}
    bool Board::is_clean(){
        return true;
    }
    void Board::remove_cures(){}
    ostream& operator <<(ostream& output, const Board& board){
        return output;
    }

}