//
// Created by shiri on 06/06/2022.
//

#include "Vampire.h"

Vampire::Vampire() {
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}

void Vampire::printInfo() {
    bool isDragon = false;
    std::ostream stream;
    printMonsterDetails(stream, m_force,m_damage,m_loot, isDragon);
}

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else{
        player.damage(m_damage);
        player.damageForce(1);
    }
}