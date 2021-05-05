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
#include "Researcher.hpp"
using namespace std;


namespace pandemic{
    string Researcher::role() const{
        return this->player_role;
    }
    void Researcher::discover_cure(Color color){}
}