//
// Created by shiri on 06/06/2022.
//

#include "Mtmchkin.h"
using std::ifstream;
using std::string;
using std::cin;

Mtmchkin::Mtmchkin(const string fileName) {
    printStartGameMessage();

    initiateDeck(fileName);
    initiatePlayers();

}

void Mtmchkin::initiateDeck(const string fileName) {

    ifstream source(fileName);
    if(!source)
    {
        //throw exception
    }

    char line[256];
    while(source.getline(line, sizeof(line)))
    {
        string cardName = line;
        Card* newCard;
        if(cardName == "Goblin")
        {
            newCard = new Goblin();
        }
        else if(cardName == "Vampire")
        {
            newCard = new Vampire();
        }
        else if(cardName == "Dragon")
        {
            newCard = new Dragon();
        }
        else if(cardName == "Merchant")
        {
            newCard = new Merchant();
        }
        else if(cardName == "Treasure")
        {
            newCard = new Treasure();
        }
        else if(cardName == "Pitfall")
        {
            newCard = new Pitfall();
        }
        else if(cardName == "Barfight")
        {
            newCard = new Barfight();
        }
        else if(cardName == "Fairy")
        {
            newCard = new Fairy();
        }
        else
        {
            //throw error of unknown card type
        }
        m_deck.push(newCard);
    }
}

void Mtmchkin::initiatePlayers() {
    printEnterTeamSizeMessage();
    m_numberOfPlayers = getNumberOfPlayers();

    std::vector<string> words;
    bool done = false;
    for(int i =0; i<m_numberOfPlayers; i++) {
        while(!done)
        {
            words.clear();
            words = getPlayerArguments();
            done = isValidArguments(words);
        }
    }

}

bool Mtmchkin::isValidArguments(std::vector<string> words)
{
    string playerName = words[0];
    string playerClass = words[1];

    if (validName(playerName)) {
        if (playerClass == "Rogue") {
            m_playersQueue.push(new Rogue(playerName));
        } else if (playerClass == "Fighter") {
            m_playersQueue.push(new Fighter(playerName));
        } else if (playerClass == "Wizard") {
            m_playersQueue.push(new Wizard(playerName));
        } else {
            printInvalidClass();
            return false;
        }
    } else {
        printInvalidName();
        return false;
    }

    return true;

}

int Mtmchkin::getNumberOfPlayers() {
    string input;
    int numberOfPlayers;
    bool valid = false;
    do{
        std::getline(cin, input);
        numberOfPlayers = stoi(input);
        if(isdigit(numberOfPlayers) && numberOfPlayers <= 6 && numberOfPlayers >= 2 )
        {
            valid = true;
        }
        printInvalidInput();
    }while(!valid);

    return numberOfPlayers;
}

std::vector<std::string> Mtmchkin::getPlayerArguments() {
    printInsertPlayerMessage();

    string input;
    string argument;
    std::vector<string> words;
    bool valid = false;

    do{
        std::getline(cin,input);
        std::istringstream seperateString(input);
        while(seperateString >> argument)
        {
            words.push_back(argument);
        }

        if(words.size() == NUMBER_OF_ARGUMENTS)
        {
            valid = true;
        }
        else{
            printInvalidNumberOfArgumens();
            words.clear();
        }
    }while(!valid);

    return words;
}

void Mtmchkin::printInvalidNumberOfArgumens() {
    std::cout << "Please enter " << std::to_string(NUMBER_OF_ARGUMENTS) << " arguments" << std::endl;
}

bool Mtmchkin::validName(const std::string& name) {
    if(name.size() >15)
    {
        return false;
    }

    for(char i : name){
        if( !isalpha(i) || isspace(i)){
            return false;
        }
    }
    return true;
}



