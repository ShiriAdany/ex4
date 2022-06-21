//
// Created by shiri on 06/06/2022.
//

#include "Vampire.h"

Vampire::Vampire() : Battle(CardType::Vampire){
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}


void Vampire::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Vampire");
    }
    else{
        player.damage(m_damage);
        player.decreaseForce(1);
        printLossBattle(player.getName(), "Vampire");

    }
}

void Vampire::printInfo(std::ostream &os) const {
    bool isDragon = false;
    printCardDetails(os,"Vampire");
    printMonsterDetails(os,m_force,m_damage,m_loot,isDragon);
    printEndOfCardDetails(os);
}

std::string Vampire::getType() const {
    return "Vampire";
}
