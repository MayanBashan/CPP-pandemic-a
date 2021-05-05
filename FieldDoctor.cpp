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
#include "FieldDoctor.hpp"
using namespace std;


namespace pandemic{
    string FieldDoctor::role() const{
        return this->player_role;
    }
    Player& FieldDoctor::treat(City city){return *this;}
}