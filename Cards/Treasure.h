//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    Treasure();

    void applyEncounter(Player& player) override;

    Treasure(const Treasure& other) = default;
    ~Treasure() = default;
    Treasure& operator=(const Treasure& other) = default;

private:
    int m_coins;
    static const int DEFAULT_COINS = 10;
    void printInfo(std::ostream &os) const override;

};
#endif //EX4_TREASURE_H
