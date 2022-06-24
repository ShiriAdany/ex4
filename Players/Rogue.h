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
    //C'tor of Rogue class
    Rogue(std::string m_name);

    /*
     * Adds coins to the player's coins bag.
     *
     * @param coins - the amount of coins to add.
    */
    void addCoins(int coins) override;

    // @return the player's job
    std::string getJob() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Rogue(const Rogue& other) = default;
    ~Rogue() override = default;
    Rogue& operator=(const Rogue& other) = default;

private:
    void printInfo(std::ostream &os) const override;
    const std::string JOB = "Rogue";


};
#endif //EX4_ROGUE_H
