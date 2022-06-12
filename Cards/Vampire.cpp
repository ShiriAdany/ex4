//
// Created by shiri on 06/06/2022.
//

#include "Vampire.h"

Vampire::Vampire() : Battle(CardType::Vampire){
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}

void Vampire::printInfo() const {
    bool isDragon = false;
    printMonsterDetails(std::cout, m_force,m_damage,m_loot, isDragon);
}

void Vampire::applyEncounter(Player &player){
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else{
        player.damage(m_damage);
        player.decreaseForce(1);
    }
}

void Vampire::printInfo(std::ostream &os) const {
    printCardDetails(os,"Vampire");
    printEndOfCardDetails(os);
}
