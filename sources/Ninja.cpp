#include "Ninja.hpp"
#include <stdexcept>
using namespace ariel;

Ninja::Ninja(const std::string& name, const Point& location):Character(name,location){};
        
   void  Ninja::slash(Character* other){
    //can we slash dead ninja?
    if(this!=other){
        if(this->getLocation().distance(other->getLocation())<=1){
            if( this->isAlive() && other->isAlive()){
                other->hit(this->_damage);

            }else{throw std::runtime_error("cannot slash a dead enemy");}
        }
    }else{throw std::runtime_error("cannot slash myself");}
   };
   void Ninja::move(Character* other){
        Point temp=this->getLocation().moveTowards(this->getLocation(),other->getLocation(),this->_speed);
        this->setlocation(temp.getX(),temp.getY());
        // this->getLocation().setX(temp.getX());
        // this->getLocation().setY(temp.getY());
        
   };