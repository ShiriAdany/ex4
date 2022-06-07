//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player
{
    public:
        Wizard(std::string name);
        ~Wizard() = default;
        Wizard(const Wizard& other) = default;
        Wizard& operator=(const Wizard& other) = default;

        void heal(int hp) override;
};




#endif //EX4_WIZARD_H
