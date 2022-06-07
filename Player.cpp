//
// Created by shiri on 06/06/2022.
//


#include "Player.h"
#include <iostream>


Player::Player(std::string name, int maxHP, int force): m_name(name),
                                                        m_level(1),
                                                        m_HP(DEFAULT_MAX_HP),
                                                        m_coins(0)
{
    if(maxHP>0){
        m_maxHP = maxHP;
    }
    else{
        m_maxHP = DEFAULT_MAX_HP;
    }

    if(force > 0){
        m_force = force;
    }
    else{
        m_force = DEFAULT_FORCE;
    }
    m_HP = m_maxHP;
}


void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}


void Player::levelUp()
{
    if(m_level<TOP_LEVEL){
        m_level++;
    }
}


int Player::getLevel() const
{
    return m_level;
}


void Player::buff(int force)
{
    if(force>0){
        m_force += force;
    }
}


void Player::heal(int hp)
{
    while(hp > 0){
        if(m_HP < m_maxHP) {
            m_HP ++;
            hp--;
        }

        else {
            break;
        }
    }
}


void Player::damage(int hp)
{
    while(hp > 0){
        if(m_HP > 0) {
            m_HP-- ;
            hp--;
        }

        else{
            break;
        }
    }
}


bool Player::isKnockedOut() const
{
    if(m_HP == 0) {
        return true;
    }
    return false;
}


void Player::addCoins(int coins)
{
    if(coins > 0){
        m_coins += coins;
    }
}


bool Player::pay(int coins)
{
    if(m_coins < coins) {
        return false;
    }

    if(coins > 0) {
        m_coins -= coins;
    }
    return true;
}


int Player::getAttackStrength() const
{
    return (m_force + m_level);
}