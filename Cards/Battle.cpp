//
// Created by shiri on 08/06/2022.
//



#include "Battle.h"

Battle::Battle(CardType type) :Card(type) {}

int Battle::getForce() const {
    return m_force;
}

int Battle::getLoot() const {
    return m_loot;
}

int Battle::getDamage() const {
    return m_damage;
}




