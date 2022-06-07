//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"
#include <string.h>
#include <sstream>


class Rogue : public Player
{
public:

    Rogue(std::string m_name);

    void addCoins(int coins) override;

    void printInfo() const;

    Rogue(const Rogue& other) = default;
    ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;

};
#endif //EX4_ROGUE_H
