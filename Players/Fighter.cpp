//
// Created by shiri on 06/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name): Player(name, "Fighter"){}


int Fighter::getAttackStrength() const {
    return(2*getForce() + getLevel());
}

void Fighter::printInfo(std::ostream &os) const {
    printPlayerDetails(os, getName(), getJob() ,getLevel() ,getForce(), getHP(), getCoins());
}



