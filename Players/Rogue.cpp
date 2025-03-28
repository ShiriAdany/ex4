//
// Created by shiri on 06/06/2022.
//

#include "Rogue.h"
using std::string;

Rogue::Rogue(string name): Player(name) {
}

void Rogue::addCoins(int coins)
{
    if(coins>0)
    {
        Player::addCoins(2*coins);
    }
}

void Rogue::printInfo(std::ostream &os) const {
    printPlayerDetails(os, getName(), getJob(), getLevel(), getForce(), getHP(), getCoins());
}

std::string Rogue::getJob() const {
    return JOB;
}


