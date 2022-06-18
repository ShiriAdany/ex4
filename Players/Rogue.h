//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"
#include <string.h>
#include <sstream>
#include "../utilities.h"



class Rogue : public Player
{
public:

    Rogue(std::string m_name);

    void addCoins(int coins) override;
    std::string getJob() const override;


    Rogue(const Rogue& other) = default;
    ~Rogue() override = default;
    Rogue& operator=(const Rogue& other) = default;

private:
    void printInfo(std::ostream &os) const override;

};
#endif //EX4_ROGUE_H
