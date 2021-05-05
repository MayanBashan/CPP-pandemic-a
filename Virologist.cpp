/**
 * Author: Mayan Bashan
 */

#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace std;


namespace pandemic{
    string Virologist::role() const{
        return this->player_role;
    }
    Player& Virologist::treat(City city){return *this;}
}