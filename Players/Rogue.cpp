//
// Created by shiri on 06/06/2022.
//

#include "Rogue.h"
using std::string;

Rogue::Rogue(string name): Player(name, player_job::rogue) {
}

void Rogue::addCoins(int coins)
{
    if(coins>0)
    {
        m_coins += (2*coins);
    }
}

void Rogue::printInfo(std::ostream &os) const {
    printPlayerDetails(os,m_name, "Rogue",m_level,m_force,m_HP,m_coins);
}

std::ostream &operator<<(std::ostream &os, const Rogue &player) {
    player.printInfo(os);
    return os;
}
