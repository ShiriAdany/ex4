//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    //C'tor of Treasure class
    Treasure();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    //Returns the type of the card
    std::string getType() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Treasure(const Treasure& other) = default;
    ~Treasure() override = default;
    Treasure& operator=(const Treasure& other) = default;

private:
    int m_coins;
    static const int DEFAULT_COINS = 10;
    void printInfo(std::ostream &os) const override;

    const std::string TYPE = "Treasure";

};
#endif //EX4_TREASURE_H
