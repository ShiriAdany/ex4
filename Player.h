//
// Created by shiri on 06/06/2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "utilities.h"


class Player{

public:

    /*
     * C'tor of Player class
     *
     * @param name- the name of the player
     * @param maxHP- maximal health points. default is 100 HP
     * @param force- the force of the player. default is 5.
     * @return
     *      A new instance of Player.
    */
    explicit Player(std::string m_name, int m_maxHP=DEFAULT_MAX_HP, int m_force=DEFAULT_FORCE);


    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo() const;


    /*
     * Upgrades the player's level by one.
     * max level is 10. if the level is already 10 then the function will not add anything.
     *
     * @return
     *      void
    */
    void levelUp();


    /*
     * Returns the level of the player:
     *
     * @return
     *      player's level.
    */
    int getLevel() const;


    /*
     * Raises the force points:
     * @param force - the quantity of the force points to raise.
     *
     * @return
     *      void
    */
    void buff(int force);


    /*
     * Raises the HP of the player according to the given argument, until the maxHP:
     * @param hp - the quantity of HP to raise.
     *
     * @return
     *      void
    */
    void heal(int hp);


    /*
     * Decrease the HP points according to the given argument, until zero:
     * @param hp - the quantity of the HP to decrease.
     *
     * @return
     *      void
    */
    void damage(int hp);


    /*
     * Checks if the HP is zero:
     *
     * @return
     *      true if the HP is zero, false otherwise.
    */
    bool isKnockedOut() const;


    /*
     * Adds coins to the player's coins bag.
     *
     * @param coins - the amount of coins to add.
     *
     * @return
     *      void
    */
    void addCoins(int coins);


    /*
     * Pays with coins. 
     * Taking coins from the coins bag. 
     * if there are not enough coins to complete the payment, the amount of coins will not change.
     *
     * @param coins - the amount of coins to pay.
     *
     * @return
     *      True if the payment succeed , false otherwise.
    */
    bool pay(int coins);


    /*
     * Returns the attack strangth of the player.
     * Calculated by adding the force and the level of the player.
     *
     * @return
     *      The attack strength.
    */
    int getAttackStrength() const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player& other) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


    protected:

    std::string m_name; // the name of the player
    int m_level; // the level of the player. in range of [1,10].
    int m_HP; // the amount of the health points of the player. in range of [0,maxHP]
    int m_coins; // number of coins.
    int m_maxHP; // maximal health points
    int m_force; // the force of the player.

    private:
    
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int TOP_LEVEL = 10;

};

#endif //PLAYER_H