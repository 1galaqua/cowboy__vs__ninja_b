#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel{
class Ninja : public Character {
    public:
        Ninja(const std::string& name, const Point& location);
        virtual ~Ninja(){};
        virtual void slash(Character* other);
        virtual void move(Character* other);

    protected:
        int _speed;
        int _damage;

    };
}



#endif 