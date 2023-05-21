#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;

TrainedNinja::TrainedNinja(const std::string& name, const Point& location):Ninja(name,location){
    this->_type="N";
    this->_health=120;
    this->_speed=12;
    this->_member=false;
    this->_damage=40;
}