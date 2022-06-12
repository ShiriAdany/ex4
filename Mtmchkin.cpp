//
// Created by shiri on 06/06/2022.
//

#include "Mtmchkin.h"
using std::ifstream;
using std::string;
using std::cin;

Mtmchkin::Mtmchkin(const string fileName): m_roundCounter(0) {
    printStartGameMessage();
    initiateDeck(fileName);
    initiatePlayers();
}

//
//template<typename T>
//Card* Mtmchkin::createInstance() {
//    return new T();
//}
//
//
//Card* Mtmchkin::mapToConstructor(std::string line)
//{
//    std::map<std::string, *Card(*)> mapFile;
//    scriptMap mapFile;
//    mapFile["Goblin"] = &createInstance;
//    return mapFile[line];
//
//}

//void Mtmchkin::initiateDeck(std::string fileName) {
//    ifstream source(fileName);
//    if(!source)
//    {
//        throw DeckFileNotFound();
//    }
//
//    char line[256];
//    int lineNumber = 0;
//    Card* newCard;
//    while(source.getline(line, sizeof(line))) {
//        newCard = mapToConstructor(line);
//        lineNumber++;
//        m_deck.push_back(newCard);
//    }
//
//    if(lineNumber < 5)
//    {
//        throw DeckFileInvalidSize();
//    }
//
//}



void Mtmchkin::initiateDeck(const string fileName) {

    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }

    char line[256];
    int lineNumber = 0;
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
            throw DeckFileFormatError(lineNumber);
        }
        lineNumber++;
        m_deck.push_back(newCard);
    }

    if(lineNumber < 5)
    {
        throw DeckFileInvalidSize();
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
    std::unique_ptr<Player> newPlayer;

    if (validName(playerName)) {
        if (playerClass == "Rogue") {
            std::unique_ptr<Player> newPlayer(new Rogue(playerName));
        } else if (playerClass == "Fighter") {
            std::unique_ptr<Player> newPlayer(new Fighter(playerName));
        } else if (playerClass == "Wizard") {
            std::unique_ptr<Player> newPlayer(new Wizard(playerName));
        } else {
            printInvalidClass();
            return false;
        }

        m_playersQueue.push_back(newPlayer.get());
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

void Mtmchkin::playRound() {
    printRoundStartMessage(m_roundCounter);
    Player* currentPlayer;
    const Card* currentCard;
    for(Player *p : m_playersQueue)
    {
        currentPlayer = m_playersQueue.front();
        printTurnStartMessage(currentPlayer->getName());
        currentCard = m_deck.front();
        playCard(currentCard, currentPlayer);

        m_playersQueue.push_back(currentPlayer);
        m_deck.push_back(currentCard);
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }


}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCounter;
}

void Mtmchkin::playCard(const Card* card, Player *player) {
    card->applyEncounter(*player);
}

bool Mtmchkin::isGameOver() const {
    for(Player *p : m_playersQueue)
    {
        if(!p->isWinning() || !p->isLosing())
        {
            return false;
        }
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const {


}







