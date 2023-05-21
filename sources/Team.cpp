#include "Team.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel; 


    
Team::Team(Character* leader) {
    
    if(!leader->ismember()){
        this->_members.push_back(leader);
        this->_leader=leader;
        leader->member_change();
    }else{throw std::runtime_error("member in other team");}
     
    }
Team::~Team() {
    for (Character* member : _members) {
        delete member;
    }
}
void Team::add(Character* member) { 
    if(this->_members.size()<10 && !member->ismember()){
    member->member_change();
    this->_members.push_back(member);
    }else {throw std::runtime_error("over 10 member");}
}

void Team::attack(Team* other) {
    
    if(!this->_leader->isAlive() && this->closeToleader(this)!= nullptr){
            this->_leader=this->closeToleader(this);
        }
    if(other!=nullptr && other->stillAlive()!=0)
    {
        
        
        for (Character* member : _members) {
            if(!other->_leader->isAlive() && other->closeToleader(other)!=nullptr){
            other->_leader=other->closeToleader(other);
            }
            Character* enemy=this->closeToleader(other);
            
            if(enemy!=nullptr){
                if(member->getType()=="C"){
                  Cowboy* temp_c =  dynamic_cast< ariel::Cowboy *>(member);
                    if(temp_c!=nullptr && temp_c->hasboolets()&& temp_c->isAlive() && enemy->isAlive()){
                        temp_c->shoot(enemy);
                    }else if(temp_c!=nullptr && temp_c->isAlive()){
                        temp_c->reload();
                    }
                }
            }
        }
        for (Character* member : _members) {
            Character* enemy=this->closeToleader(other);
            if(enemy!=nullptr){
                if(member->getType()=="N"){
                  Ninja* temp_n =  dynamic_cast< ariel::Ninja *>(member);
                    if(temp_n!=nullptr && temp_n->getLocation().distance(enemy->getLocation())<=1 && enemy->isAlive() && temp_n->isAlive()){
                        temp_n->slash(enemy);

                    }else if(temp_n!=nullptr && temp_n->isAlive()){
                        temp_n->move(enemy);
                    }
                }
            }
        }
    }else if(other==nullptr){throw std::invalid_argument("cannot attack nullptr");}
    else if(other->stillAlive()==0){throw std::runtime_error("cannot attack a dead team");}
}

Character* Team::closeToleader(Team* other){
    double temp_dis=std::numeric_limits<double>::max();
    Character* temp=nullptr;
    
    for (Character* member : other->_members) {
        double dis=this->_leader->getLocation().distance(member->getLocation());
        if(dis<temp_dis && member->isAlive()){
            temp_dis=dis;
            temp=member;
        }
    }
    return temp;
};


int Team::stillAlive() const {
   int countlive=0;
   for (Character* member : _members) {
        if(member->isAlive()){
            countlive+=1;
        }
    }
    return countlive;
}

void Team::print() const {
    cout<<"--------------------------------------------"<<endl;
    for (Character* member : _members) {
        cout << member->print() << endl;   
    }
    cout<<"--------------------------------------------"<<endl;
    
}

