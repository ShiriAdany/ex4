//
// Created by shiri on 06/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(std::string name): Player(name, player_job::wizard){}


void Wizard::heal(int hp)
{
    while(hp > 0){
        if(m_HP < MAX_HP) {
            m_HP += 2;
            hp--;
        }

        else {
            break;
        }
    }
}

void Wizard::printInfo() const {
    printPlayerDetails(std::cout,m_name,"Wizard",m_level,m_force,m_HP,m_coins);
}

