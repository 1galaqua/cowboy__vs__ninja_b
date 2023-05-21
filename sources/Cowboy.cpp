#include "Cowboy.hpp"

#include <string>
#include <stdexcept>
using namespace ariel;

Cowboy::Cowboy(const std::string& name, const Point& location):Character(name,location), _stack(6),_damage(10) {
    this->_type="C";
    this->_health=110;
}

void Cowboy::reload(){
    if(this->isAlive()){
        this->_stack=6;
    }else{throw std::runtime_error("dead cowboy cant reload");}

}
void Cowboy::shoot(Character* other){
    //can we shoot on death character?
    
    if(this->_stack!=0 ){
        
    if(this->isAlive() && other->isAlive()&& (this!=other)){
            other->hit(this->_damage);
            this->_stack-=1;
        
     }else{throw std::runtime_error("cannot shoot dead enemy");}
    }
}