//
// Created by shiri on 06/06/2022.
//

#include "Dragon.h"

Dragon::Dragon() : Battle(CardType::Dragon){
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}

void Dragon::printInfo() const {
    bool isDragon = true;
    printMonsterDetails(std::cout, m_force,m_damage,m_loot, isDragon);
}

void Dragon::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else{
        int allHP = player.getHP();
        player.damage(allHP);
    }
}

void Dragon::printInfo(std::ostream &os) const {
    printCardDetails(os,"Dragon");
    printEndOfCardDetails(os);
}
