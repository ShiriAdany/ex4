//
// Created by shiri on 08/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include "Card.h"

class Battle : public Card
{
public:
    Battle(CardType type);

    virtual void applyEncounter(Player& player) =0;

    virtual void printInfo() const =0;

    Battle(const Battle& other) = default;
    ~Battle() = default;
    Battle& operator=(const Battle& other) = default;

protected:
    int m_force;
    int m_loot;
    int m_damage;

};
#endif //EX4_BATTLE_H
