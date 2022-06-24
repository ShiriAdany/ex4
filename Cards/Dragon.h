//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"
#include <limits.h>

class Dragon : public Battle
{
public:

    //C'tor of Dragon class
    Dragon();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) const override;

    //Returns the type of the card
    std::string getType() const override;

    //Returns the damage of the card
    int getDamage() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon& other) = default;
    ~Dragon() override = default;
    Dragon& operator=(const Dragon& other) = default;

private:

    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int DEFAULT_DAMAGE = 0;

    const std::string TYPE = "Dragon";
};
#endif //EX4_DRAGON_H
