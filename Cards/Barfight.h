//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight();

    void applyEncounter(Player& player) const override;

    Barfight(const Barfight& other) = default;
    ~Barfight() override = default;
    Barfight& operator=(const Barfight& other) = default;

private:
    int m_damage;
    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_DAMAGE = 10;

};
#endif //EX4_BARFIGHT_H
