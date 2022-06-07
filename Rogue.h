//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"
#include <string.h>

class Rogue : public Player
{
private:

public:

    Rogue(string m_name);

    void addCoins(int coins) override;

    Rogue(const Rogue& other) = default;
    ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;

};
#endif //EX4_ROGUE_H
