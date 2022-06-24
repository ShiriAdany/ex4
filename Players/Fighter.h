//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"
#include "../utilities.h"


class Fighter : public Player
{
public:
    //C'tor of Fighter class
    Fighter(std::string name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fighter() override = default;
    Fighter(const Fighter& other) = default;
    Fighter& operator=(const Fighter& other) = default;

    /*
     * Returns the attack strangth of the player.
     * Calculated by adding the force and the level of the player.
     *
     * @return The attack strength.
    */
    int getAttackStrength() const override;

    //Returns the job of the player
    std::string getJob() const override;

private:
    void printInfo(std::ostream &os) const override;

    const std::string JOB = "Fighter";

};




#endif //EX4_FIGHTER_H
