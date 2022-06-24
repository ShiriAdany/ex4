//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
#include <iostream>
#include <string.h>

enum Action:int {Nothing, Health_Potion, Force_Boost, Number_Of_Options};

class Merchant : public Card{

public:
    //C'tor of Merchant class
    Merchant();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    //Gets from the user the particular option to deal with the merchant.
    static int getPlayerChoice(Player &player);

    //Make the trade with the merchant according to the choice of the player.
    static void makeTrade(Player &player);

    //Returns the type of the card
    std::string getType() const override;

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    Merchant(const Merchant& other) = default;
    ~Merchant() override = default;
    Merchant& operator=(const Merchant& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int HEALTH_POTION_COST = 5;
    static const int FORCE_BOOST_COST = 10;

    const std::string TYPE = "Merchant";

};


#endif //EX4_MERCHANT_H
