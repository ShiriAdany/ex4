//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "Player.h"
#include "utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

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
    Card(CardType type, const CardStats& stats);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const;

    // finds the type of a card
    //CardType getType() const;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    CardType m_effect;
    CardStats m_stats;

};



#endif //EX4_CARD_H
