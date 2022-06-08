//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

class Dragon : public Card
{
public:
    Dragon();

    void applyEncounter(Player &player) override;

    void printInfo() const;

    Dragon(const Dragon& other) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;

private:
    int m_force;
    int m_loot;
    int m_damage;

    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int DEFAULT_DAMAGE = 0;
};
#endif //EX4_DRAGON_H
