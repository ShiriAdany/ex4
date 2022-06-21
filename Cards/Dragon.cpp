//
// Created by shiri on 06/06/2022.
//

#include "Dragon.h"

Dragon::Dragon() : Battle(CardType::Dragon){
    m_force= DEFAULT_FORCE;
    m_loot = DEFAULT_LOOT;
    m_damage = DEFAULT_DAMAGE;
}


void Dragon::applyEncounter(Player &player) const{
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Dragon");

    }
    else{
        int allHP = player.getHP();
        player.damage(allHP);
        printLossBattle(player.getName(), "Dragon");

    }
}

void Dragon::printInfo(std::ostream &os) const {
    bool isDragon = true;
    printCardDetails(os,"Dragon");
    printMonsterDetails(os,m_force,m_damage,m_loot,isDragon);
    printEndOfCardDetails(os);

}

std::string Dragon::getType() const {
    return "Dragon";
}

int Dragon::getDamage() const {
    return INT_MAX;
}


