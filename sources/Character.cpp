#include "Character.hpp"
#include<iostream>
using namespace ariel;
using namespace std;

Character::Character(const std::string& name, const Point& location) : _name(name) , _location(location),_member(false){};

std::string Character::print() const{
    if(this->_health > 0){
        if(this->getType()=="C"){
            return "Type:C name:"+this->getName() +" location: ( "+ std::to_string(this->_location.getX())+ " , "+ std::to_string(this->_location.getY())+" ) " + "health: "+std::to_string( this->_health);
        }else{
            return "Type:N name:"+this->getName() +" location: ( "+ std::to_string(this->_location.getX())+ " , "+ std::to_string(this->_location.getY())+" ) " + "health: "+ std::to_string(this->_health);
        }

    }
    return "dead ("+this->getName() +") location: ( "+ std::to_string(this->_location.getX())+ " , "+ std::to_string(this->_location.getY())+" )"  ;
} 

double Character::distance(const Character* other) const{
    return this->_location.distance(other->getLocation());
}

void Character::hit(int damage){
    if(damage > 0){
        this->_health-=damage;
        if(this->_health<0){
            this->_health=0;
        }
    }else{throw std::invalid_argument("damage cannot be negative");}
}

bool Character::isAlive() const {
    if(this->_health>0){
        return true;
    }else{
        return false;
    }
}

const std::string& Character::getName() const {
    return this->_name;
}

const Point& Character::getLocation() const  {
    return this->_location;
}

bool Character::ismember() const{
    return this->_member;
}

void Character::member_change(){
    this->_member=!this->_member;
}