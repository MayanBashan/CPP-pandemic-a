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
#include "GeneSplicer.hpp"
using namespace std;


namespace pandemic{
    string GeneSplicer::role() const{
        return this->player_role;
    }
    void GeneSplicer::discover_cure(Color color){}
    
}