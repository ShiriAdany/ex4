//
// Created by shiri on 06/06/2022.
//

#include "Goblin.h"

Goblin::Goblin() : Battle(CardType::Goblin) {
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}


void Goblin::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), getType());
    }
    else{
        player.damage(m_damage);
        printLossBattle(player.getName(), getType());
    }
}

void Goblin::printInfo(std::ostream &os) const {
    bool isDragon = false;
    printCardDetails(os,TYPE);
    printMonsterDetails(os,m_force,m_damage,m_loot,isDragon);
    printEndOfCardDetails(os);
}

std::string Goblin::getType() const {
    return TYPE;
}
