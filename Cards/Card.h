//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Goblin,Vampire,Dragon, Merchant, Pitfall, Treasure, Barfight, Fairy,Gang,EndGang}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(CardType type);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const =0;

    virtual std::string getType() const =0;

    virtual int getForce() const;

    virtual int getLoot() const;

    virtual int getDamage() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    CardType m_type;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual void printInfo(std::ostream &os) const = 0;

};



#endif //EX4_CARD_H
