//
// Created by shiri on 06/06/2022.
//

#include "Barfight.h"

Barfight::Barfight() :Card(CardType::Barfight){
    m_damage = DEFAULT_DAMAGE;
}

void Barfight::applyEncounter(Player &player) const {
    bool isFighter = true;
    if(player.getJob() != "Fighter")
    {
        isFighter = false;
        player.damage(m_damage);
    }
    printBarfightMessage(isFighter);
}

void Barfight::printInfo(std::ostream &os) const {
    printCardDetails(os,"Barfight");
    printEndOfCardDetails(os);
}


