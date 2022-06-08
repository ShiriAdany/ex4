//
// Created by shiri on 06/06/2022.
//


#include "Player.h"
#include <iostream>


Player::Player(std::string name, player_job job): m_name(name),
                                                           m_job(job),
                                                           m_level(1),
                                                           m_HP(MAX_HP),
                                                           m_coins(DEFAULT_COINS),
                                                           m_force(DEFAULT_FORCE)
{}


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
        if(m_HP < MAX_HP) {
            m_HP++;
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
            m_HP--;
            hp--;
        }

        else{
            break;
        }
    }
}


bool Player::isKnockedOut() const
{
    if(m_HP == 0){
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
    if(m_coins < coins){
        return false;
    }

    if(coins > 0){
        m_coins -= coins;
    }
    return true;
}


int Player::getAttackStrength() const
{
    return (m_force + m_level);
}

std::string Player::getName() const{
    return m_name;
}

int Player::getCoins() const{
    return m_coins;
}

void Player::decreaseForce(int damage) {
    if(m_force -damage >= 0)
    {
        m_force -=damage;
    }
    else{
        m_force=0;
    }
}

int Player::getHP() const {
    return m_HP;
}

player_job Player::getJob() const {
    return m_job;
}


