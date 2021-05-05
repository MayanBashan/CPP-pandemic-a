/**
 * Author: Mayan Bashan
 */

#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>
#include <map>
using namespace std;


namespace pandemic{
    Player::Player(){}
    Player& Player::drive(City city){return *this;}
    Player& Player::fly_direct(City city){return *this;} 
    Player& Player::fly_charter(City city){return *this;}
    Player& Player::fly_shuttle(City city){return *this;}
    Player& Player::build(){return *this;}
    void Player::discover_cure(Color color){}
    Player& Player::treat(City city){return *this;}
    Player& Player::take_card(City city){return *this;}
    string Player::role(){
        return "Player";
    }

}