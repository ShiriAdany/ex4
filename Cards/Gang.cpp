//
// Created by shiri on 19/06/2022.
//

#include "Gang.h"
using std::string;


void Gang::applyEncounter(Player &player) const {

    bool isDefeated = false;
    for(const std::unique_ptr<Card> &current : m_gang)
    {
        if(isDefeated)
        {
            player.damage(current->getDamage());
            if(current->getType() == "Vampire")
            {
                player.decreaseForce(1);
            }
            printLossBattle(player.getName(), current->getType());

        }
        else if(player.getAttackStrength() >= current->getForce())
        {
            player.addCoins(current->getLoot());
        }
        else
        {
            isDefeated = true;
            player.damage(current->getDamage());
            if(current->getType() == "Vampire")
            {
                player.decreaseForce(1);
            }
            printLossBattle(player.getName(), current->getType());
        }
    }
    if(!isDefeated)
    {
        player.levelUp();
        printWinBattle(player.getName(), this->getType());
    }
}


std::string Gang::getType() const {
    return "Gang";
}

Gang::Gang(std::ifstream &source, int *lineNumber) :Card(CardType::Gang){
    string cardName;
    bool endGang = false;
    while(!endGang && getline(source,cardName)) {
        (*lineNumber)++;
        if(cardName == "Vampire")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Vampire()));
        }
        else if(cardName == "Goblin")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Goblin()));
        }
        else if(cardName == "Dragon")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Dragon()));
        }
        else if(cardName == "EndGang")
        {
            endGang = true;
        }
        else
        {
            throw DeckFileFormatError(*lineNumber);
        }

    }
    if(!endGang)
    {
        (*lineNumber)++;
        throw DeckFileFormatError(*lineNumber); //there wasn't an EndGang card.
    }
}


void Gang::printInfo(std::ostream &os) const {
    for(const std::unique_ptr<Card> &current : m_gang)
    {
        os << *current;
    }
}

Gang::Gang(const Gang& other): Card(CardType::Gang)
{
    for(const std::unique_ptr<Card> &current : other.m_gang)
    {
        if(current->getType() == "Vampire")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Vampire()));
        }
        else if(current->getType() == "Goblin")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Goblin()));
        }
        else if(current->getType() == "Dragon")
        {
            m_gang.push_back(std::unique_ptr<Card>(new Dragon()));
        }
        else
        {
            throw InvalidGangMember();
        }
    }
}


Gang& Gang::operator=(const Gang &other)
{
    if(this == &other)
    {
        return *this;
    }

    std::vector<std::unique_ptr<Card>> temp;
    for(const std::unique_ptr<Card> &current : other.m_gang)    {
        try
        {
            if(current->getType() == "Vampire")
            {
                temp.push_back(std::unique_ptr<Card>(new Vampire()));
            }
            else if(current->getType() == "Goblin")
            {
                temp.push_back(std::unique_ptr<Card>(new Goblin()));
            }
            else if(current->getType() == "Dragon")
            {
                temp.push_back(std::unique_ptr<Card>(new Dragon()));
            }
            else
            {
                throw InvalidGangMember();
            }
        }
        catch(...)
        {
            throw;
        }
    }

    m_gang.clear();
    m_gang = std::move(temp);
    return *this;
}
