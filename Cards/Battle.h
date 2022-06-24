//
// Created by shiri on 08/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include "Card.h"

class Battle : public Card
{
public:
    //C'tor of Battle abstract class
    //Gets the name of the battle card.
    Battle(CardType type);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const =0;

    //Returns the type of card
    virtual std::string getType() const =0;

    //Returns the force of the card
    int getForce() const override;

    //Returns the loot of the card
    int getLoot() const override;

    //Returns the damage of the card
    int getDamage() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
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
