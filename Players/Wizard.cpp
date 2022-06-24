//
// Created by shiri on 06/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(std::string name): Player(name){}


void Wizard::heal(int hp)
{
    while(hp > 0){
        if(getHP() < MAX_HP) {
            Player::heal(2);
            hp--;
        }

        else {
            break;
        }
    }
}

void Wizard::printInfo(std::ostream &os) const {
    printPlayerDetails(os, getName(), getJob(), getLevel(), getForce(), getHP(), getCoins());
}

std::string Wizard::getJob() const {
    return JOB;
}

