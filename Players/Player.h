//
// Created by shiri on 06/06/2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "utilities.h"

enum player_job {wizard, fighter, rogue};

class Player{

public:

    /*
     * C'tor of Player class
     *
     * @param name- the name of the player
     * @param job- wizard, fighter or rogue
     * 
     * @return A new instance of Player.
    */
    explicit Player(std::string name, player_job job);
    

    /*
     * Upgrades the player's level by one.
     * max level is 10. if the level is already 10 then the function will not add anything.
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
    */
    void buff(int force);

    
    /*
     * Raises the HP of the player according to the given argument, until the maxHP:
     * @param hp - the quantity of HP to raise.
     *
    */
    void heal(int hp);


    /*
     * Decrease the HP points according to the given argument, until zero:
     * @param hp - the quantity of the HP to decrease.
     *
    */
    void damage(int hp);


    /*
     * Checks if the HP is zero:
     *
     * @return true if the HP is zero, false otherwise.
    */
    bool isKnockedOut() const;


    /*
     * Adds coins to the player's coins bag.
     *
     * @param coins - the amount of coins to add.
    */
    void addCoins(int coins);


    /*
     * Pays with coins. 
     * Taking coins from the coins bag. 
     * if there are not enough coins to complete the payment, the amount of coins will not change.
     *
     * @param coins - the amount of coins to pay.
     *
     * @return True if the payment succeed, false otherwise.
    */
    bool pay(int coins);


    /*
     * Returns the attack strangth of the player.
     * Calculated by adding the force and the level of the player.
     *
     * @return The attack strength.
    */
    int getAttackStrength() const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    virtual ~Player();
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;


    protected:

    std::string m_name; // the name of the player, maximum 15 letters
    player_job m_job; // a player's job can be wizard, fighter or rogue
    int m_level; // the level of the player, in range of [1,10]
    int m_HP; // the amount of the health points of the player, in range of [0,maxHP]
    int m_coins; // number of coins
    int m_force; // the force of the player

    private:
    
    static const int TOP_LEVEL = 10;
    static const int MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;


};

#endif //PLAYER_H
