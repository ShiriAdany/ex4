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

    virtual void applyEncounter(Player& player) const =0;

    virtual std::string getType() const =0;

    int getForce() const override;

    int getLoot() const override;

    int getDamage() const override;

    Battle(const Battle& other) = default;
    virtual ~Battle() override = default;
    Battle& operator=(const Battle& other) = default;



protected:
    int m_force;
    int m_loot;
    int m_damage;
    virtual void printInfo(std::ostream &os) const =0;


};
#endif //EX4_BATTLE_H
