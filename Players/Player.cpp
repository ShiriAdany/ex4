//
// Created by shiri on 06/06/2022.
//


#include "Player.h"
#include "../utilities.h"

using std::cin;

Player::Player(std::string name, std::string job): m_name(name),
                                                   m_job(job),
                                                   m_level(1),
                                                   m_HP(MAX_HP),
                                                   m_coins(DEFAULT_COINS),
                                                   m_force(DEFAULT_FORCE)
{
    while(invalidName(name) || invalidClass(job)){
        if(invalidName(name)){
            printInvalidName();
            cin >> name >> job;
            continue;
        }
        if(invalidClass(job)){
            printInvalidClass();
            cin >> name >> job;
            continue;
        }   
    }
    m_name = name;
    m_job = job;
}

bool Player::invalidName(std::string name)
{
    bool isInvalid = false;
    if(name.std::string::length() > MAX_NAME_LEN){
        isInvalid = true;
    }
    for(int i=0; i < name.length(); i++){
        if(name[i] == ' ' || (name[i] < 'A' && name[i] != ' ') || name[i] > 'z' || (name[i] > 'Z' && name[i] < 'a'))
            isInvalid = true;
    }
    return isInvalid;
}

bool Player::invalidClass(std::string job)
{
    bool isInvalid = false;
    if(job != "Wizard" && job != "Fighter" && job != "Rogue"){
        isInvalid = true;
    }
    return isInvalid;
}

void Player::levelUp()
{
    if(m_level<TOP_LEVEL){
        m_level++;
    }
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

bool Player::isWinning() const
{
    if(m_level == TOP_LEVEL)
    {
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



std::string Player::getName() const
{
    return m_name;
}

std::string Player::getJob() const
{
    return m_job;
}

int Player::getLevel() const
{
    return m_level;
}

int Player::getHP() const
{
    return m_HP;
}

int Player::getCoins() const
{
    return m_coins;
}

int Player::getForce() const
{
    return m_force;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}

void Player::decreaseForce(int damage)
{
    if(m_force -damage >= 0){
        m_force -=damage;
    }
    else{
        m_force=0;
    }
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    player.printInfo(os);
    return os;
}

