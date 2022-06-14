//
// Created by shiri on 06/06/2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "utilities.h"
#include <iostream>
#include <string>



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
    explicit Player(std::string name, std::string job);
    

    /*
     * Upgrades the player's level by one.
     * max level is 10. if the level is already 10 then the function will not add anything.
    */
    void levelUp();


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
    virtual void heal(int hp);


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
     virtual void addCoins(int coins);


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


    // @param damage - the amount of force the player loses
    void decreaseForce(int damage);


    // @return the player's name
    std::string getName() const;

    // @return the player's job
    std::string getJob() const;

    // @return player's level.
    int getLevel() const;
    
    // @return the player's current health points
    int getHP() const;

    // @return the number of coins the player has
    int getCoins() const;
    
    // @return the player's force
    int getForce() const;


    /*
     * Returns the attack strangth of the player.
     * Calculated by adding the force and the level of the player.
     *
     * @return The attack strength.
    */
    virtual int getAttackStrength() const;



    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    virtual ~Player() = default;
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;

protected:

    static const int MAX_HP = 100;
    static const int TOP_LEVEL = 10;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;

    int m_HP; // the amount of the health points of the player, in range of [0,maxHP]
    int m_coins; // number of coins

private:
    


    std::string m_name; // the name of the player, maximum 15 letters
    std::string m_job; // a player's job can be Wizard, Fighter or Rogue
    int m_level; // the level of the player, in range of [1,10]
    int m_force; // the force of the player

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void printInfo(std::ostream &os) const = 0;

};

#endif //PLAYER_H