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
    Merchant();

    void applyEncounter(Player& player) override;

    static int getPlayerChoice(Player &player);

    static void makeTrade(Player &player);

    Merchant(const Merchant& other) = default;
    ~Merchant() override = default;
    Merchant& operator=(const Merchant& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int HEALTH_POTION_COST = 5;
    static const int FORCE_BOOST_COST = 10;
};


#endif //EX4_MERCHANT_H
