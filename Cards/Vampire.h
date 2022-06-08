//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card
{
public:
    Vampire();

    void applyEncounter(Player &player) override;

    void printInfo() const;

    Vampire(const Vampire& other) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;

private:
    int m_force;
    int m_loot;
    int m_damage;

    static const int DEFAULT_FORCE =  10;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;
};
#endif //EX4_VAMPIRE_H
