#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel{
    class Character {

        public:
            Character(const std::string& name, const Point& location);
            virtual ~Character() {};

            virtual std::string print() const ;
            virtual double distance(const Character* other) const;
            virtual void hit(int damage);
            virtual bool isAlive() const ; 
            virtual const std::string& getName() const ;
            virtual const Point& getLocation() const ;
            virtual bool ismember() const;
            virtual void member_change();
            virtual void setType(string type){this->_type=type;}
            virtual std::string getType()const{return this->_type;}
            virtual void setlocation(double dotx,double doty){this->_location.setX(dotx);this->_location.setY(doty);}
        protected:
            string _name;
            Point _location;
            int _health;
            bool _member;
            string _type;
       };

}


#endif
