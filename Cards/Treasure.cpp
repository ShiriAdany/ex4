//
// Created by shiri on 06/06/2022.
//

#include "Treasure.h"

Treasure::Treasure() :Card(CardType::Treasure){
    m_coins = DEFAULT_COINS;
}

void Treasure::applyEncounter(Player &player) {
    player.addCoins(m_coins);
    printTreasureMessage();
}


