//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:

    //C'tor of Barfight class
    Barfight();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    //Returns the type of card
    std::string getType() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Barfight(const Barfight& other) = default;
    ~Barfight() override = default;
    Barfight& operator=(const Barfight& other) = default;

private:
    int m_damage;

    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_DAMAGE = 10;
    const std::string TYPE = "Barfight";
};
#endif //EX4_BARFIGHT_H
