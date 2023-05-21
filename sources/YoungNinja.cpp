#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;

YoungNinja::YoungNinja(const std::string& name, const Point& location):Ninja(name,location){
    this->_type="N";
    this->_health=100;
    this->_speed=14;
    this->_member=false;
    this->_damage=40;
}