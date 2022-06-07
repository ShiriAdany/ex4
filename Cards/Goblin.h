//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Goblin : public Card
{
public:
    Goblin();

    void applyEncounter(Player &player) const;

    void printInfo();

    Goblin(const Goblin& other) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;

private:
    int m_force;
    int m_loot;
    int m_damage;

    static const int DEFAULT_FORCE = 6;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;
};
#endif //EX4_GOBLIN_H
