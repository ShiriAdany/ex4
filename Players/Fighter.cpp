//
// Created by shiri on 06/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name): Player(name, player_job::fighter){}


int Fighter::getAttackStrength() const {
    return(2*m_force + m_level);
}

void Fighter::printInfo(std::ostream &os) const {
    printPlayerDetails(os, m_name,"Fighter",m_level,m_force,m_HP,m_coins);
}



