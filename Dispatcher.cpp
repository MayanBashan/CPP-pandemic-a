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
#include "Dispatcher.hpp"
using namespace std;


namespace pandemic{
    string Dispatcher::role() const{
        return this->player_role;
    }
    Player& Dispatcher::fly_direct(City city){
        return *this;
    }
}