//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle
{
public:
    //C'tor of Goblin class
    Goblin();

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

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Goblin(const Goblin& other) = default;
    ~Goblin() override = default;
    Goblin& operator=(const Goblin& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE = 6;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;

    const std::string TYPE = "Goblin";

};
#endif //EX4_GOBLIN_H
