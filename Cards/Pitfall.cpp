//
// Created by shiri on 06/06/2022.
//

#include "Pitfall.h"

void Pitfall::applyEncounter(Player &player) const{
    bool isRogue = true;
    if(player.getJob() != player_job::rogue)
    {
        isRogue = false;
        player.damage(m_damage);
    }
    printPitfallMessage(isRogue);
}

Pitfall::Pitfall() : Card(CardType::Pitfall){
    m_damage = DEFAULT_DAMAGE;
}

void Pitfall::printInfo(std::ostream &os) const {
    printCardDetails(os,"Pitfall");
    printEndOfCardDetails(os);
}
