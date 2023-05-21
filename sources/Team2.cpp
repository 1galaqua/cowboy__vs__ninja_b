#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) :Team(leader){
     
}

// Team2::~Team2(){
//     for(Character* member : _members){
//         delete member;
//     }
// }
void Team2::attack(Team* other){
     if(!this->_leader->isAlive() && this->closeToleader(this)!= nullptr){
            this->_leader=this->closeToleader(this);
        }
    if(other!=nullptr && other->stillAlive()!=0)
    {
        
        
        for (Character* member : _members) {
            if(!other->getLeader()->isAlive() && other->closeToleader(other)!=nullptr){
            Character* newleader=other->getLeader();
            newleader=other->closeToleader(other);
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
