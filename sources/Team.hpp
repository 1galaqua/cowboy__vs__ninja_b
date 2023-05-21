

#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
namespace ariel {
using namespace std;
class Team {
    public:
        Team(Character* leader);
        virtual ~Team();
        virtual void add(Character* member);
        virtual void attack(Team* other);
        virtual int stillAlive() const;
        virtual void print() const;
        virtual Character* closeToleader(Team* other);
        virtual Character* getLeader(){return this->_leader;}
    protected:
        std::vector<Character*> _members;
        Character* _leader;
    };
    


}

#endif // TEAM_HPP