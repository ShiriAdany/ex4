//
// Created by shiri on 06/06/2022.
//

#include "Goblin.h"

Goblin::Goblin() : Card(CardType::Goblin) {
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}

void Goblin::printInfo() {
    bool isDragon = false;
    printMonsterDetails(std::cout, m_force,m_damage,m_loot, isDragon);
}

void Goblin::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
    }
    else{
        player.damage(m_damage);
    }
}