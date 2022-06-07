//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Vampire : public Card
{
public:
    Vampire();

    void applyEncounter(Player &player) const override;

    void printInfo();

    Vampire(const Vampire& other) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;

private:
    int m_force;
    int m_loot;
    int m_damage;

    static int DEFAULT_FORCE 10;
    static int DEFAULT_LOOT 2;
    static int DEFAULT_DAMAGE 10;
};
#endif //EX4_GOBLIN_H
