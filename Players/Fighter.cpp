//
// Created by shiri on 06/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name)
{
    Player(name);
}

int getAttackStrength() const override
{
    return(2*m_force + m_level);
}