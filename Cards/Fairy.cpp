//
// Created by shiri on 06/06/2022.
//

#include "Fairy.h"

Fairy::Fairy() : Card(CardType::Fairy){
    m_heal = DEFAULT_HEAL;
}

void Fairy::applyEncounter(Player &player) const {
    bool isWizard = false;
    if(player.getJob() == player_job::wizard)
    {
        isWizard= true;
        player.heal(m_heal);
    }
    printFairyMessage(isWizard);
}

void Fairy::printInfo(std::ostream &os) const {
    printCardDetails(os,"Fairy");
    printEndOfCardDetails(os);
}



