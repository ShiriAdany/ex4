//
// Created by shiri on 06/06/2022.
//

#include "Rogue.h"
using std::string;

Rogue::Rogue(string name) {
    Player{name};
}

Rogue::addCoins(int coins)
{
    if(coins>0)
    {
        m_coins += (2*coins);
    }
}

void Rogue::printInfo() const {
    std::ostream stream;
    printPlayerDetails(stream,m_name, "Rogue",m_level,m_force,m_HP,m_coins);
}


