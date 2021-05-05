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
#include "Medic.hpp"
using namespace std;


namespace pandemic{
    string Medic::role() const{
        return this->player_role;
    }
    Player& Medic::treat(City city){return *this;}
}