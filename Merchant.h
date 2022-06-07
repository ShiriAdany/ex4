//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

enum class Action {Nothing, Health_Potion, Force_Boost, Options};

class Merchant : public Card{

public:
    Merchant();

    int getPlayerChoice(Player &player);

    void makeTrade(Player &player);

    Merchant(const Merchant& other) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;

private:
    static int HEALTH_POTION_COST 5;
    static int FORCE_BOOST_COST 10;
};


#endif //EX4_MERCHANT_H
