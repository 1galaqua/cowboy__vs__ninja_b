#include "OldNinja.hpp"

using namespace ariel;
using namespace std;

OldNinja::OldNinja(const std::string& name, const Point& location):Ninja(name,location){
    this->_type="N";
    this->_health=150;
    this->_speed=8;
    this->_member=false;
    this->_damage=40;
}