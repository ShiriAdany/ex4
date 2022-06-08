//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card
{
public:
    Fairy();

    void applyEncounter(Player& player) override;

    Fairy(const Fairy& other) = default;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;

private:
    int m_heal;

    static const int DEFAULT_HEAL = 10;

};
#endif //EX4_FAIRY_H
