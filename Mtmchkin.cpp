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
//
//void Mtmchkin::initiateDeck(std::string fileName) {
//    ifstream source(fileName);
//    if(!source)
//    {
//        throw DeckFileNotFound();
//    }
//
//    char line[256];
//    int lineNumber = 1;
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
    int lineNumber = 1;
    while(source.getline(line, sizeof(line)))
    {
        string cardName = line;
        if(cardName == "Goblin")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Goblin()));
        }
        else if(cardName == "Vampire")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Vampire()));
        }
        else if(cardName == "Dragon")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Dragon()));
        }
        else if(cardName == "Merchant")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Merchant()));
        }
        else if(cardName == "Treasure")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Treasure()));
        }
        else if(cardName == "Pitfall")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Pitfall()));
        }
        else if(cardName == "Barfight")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Barfight()));
        }
        else if(cardName == "Fairy")
        {
            m_deck.push_back(std::unique_ptr<Card>(new Fairy()));
        }
        else
        {
            throw DeckFileFormatError(lineNumber);
        }
        lineNumber++;
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
            m_playersQueue.push_back(std::unique_ptr<Player>(new Rogue(playerName)));
        } else if (playerClass == "Fighter") {
            m_playersQueue.push_back(std::unique_ptr<Player>(new Fighter(playerName)));
        } else if (playerClass == "Wizard") {
            m_playersQueue.push_back(std::unique_ptr<Player>(new Wizard(playerName)));
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

void Mtmchkin::playRound() {
    printRoundStartMessage(m_roundCounter);
    std::unique_ptr<Player> currentPlayer;
    std::unique_ptr<Card> currentCard;
    for(const std::unique_ptr<Player> &p : m_playersQueue)
    {
        currentPlayer = std::move(m_playersQueue.front());
        printTurnStartMessage(currentPlayer->getName());
        currentCard = std::move(m_deck.front());
        playCard(std::move(currentCard), std::move(currentPlayer));

        m_playersQueue.push_back(std::move(currentPlayer));
        m_deck.push_back(std::move(currentCard));
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }


}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCounter;
}

void Mtmchkin::playCard(std::unique_ptr<Card> card, std::unique_ptr<Player> player)
{
    card->applyEncounter(*player);
}

bool Mtmchkin::isGameOver() const {
    for(const std::unique_ptr<Player> &p : m_playersQueue)
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







