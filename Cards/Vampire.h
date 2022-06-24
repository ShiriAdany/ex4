//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle
{
public:
    //C'tor of Vampire class
    Vampire();

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
    Vampire(const Vampire& other) = default;
    ~Vampire() override = default;
    Vampire& operator=(const Vampire& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE =  10;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;

    const std::string TYPE = "Vampire";

};
#endif //EX4_VAMPIRE_H
