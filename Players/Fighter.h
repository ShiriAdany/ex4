//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
    public:
        Fighter(std::string name);

        ~Fighter() = default;
        Fighter(const Fighter& other) = default;
        Fighter& operator=(const Fighter& other) = default;

        int getAttackStrength() const override;

        void PrintInfo() const;
};




#endif //EX4_FIGHTER_H
