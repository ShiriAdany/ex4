//
// Created by shiri on 06/06/2022.
//

#include "Mtmchkin.h"
using std::ifstream;
using std::string;
using std::cin;
using std::endl;

Mtmchkin::Mtmchkin(const string fileName): m_roundCounter(0) {
    printStartGameMessage();
    
    try{
        initiateDeck(fileName);
    }
    catch(const Exception& e){
        std::cerr << e.what() << endl;
    }
    
    m_numberOfPlayers = getNumberOfPlayers();
    initiatePlayers();
    m_activePlayers.reserve(m_numberOfPlayers);
    initiateLeaderBoard();
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
        printEnterTeamSizeMessage();
        std::getline(cin, input);
        numberOfPlayers = stoi(input);
        if(input.find_first_not_of("0123456789") == std::string::npos && numberOfPlayers <= MAX_PLAYERS && numberOfPlayers >= MIN_PLAYERS )
        {
            valid = true;
        }
        else{
            printInvalidInput();
        }
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

    for(int i=0; i<m_activePlayers.size(); i++)
    {
            currentPlayer = std::move(m_activePlayers.at(i));
            printTurnStartMessage(currentPlayer->getName());
            currentCard = std::move(m_deck.at(i));

            playCard(std::move(currentCard), std::move(currentPlayer));
            updateLeaderBoard(i);

        if(isGameOver()){
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
    if(!m_activePlayers.empty()){
        return false;
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;

    for(int i=0; i<m_winners.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_winners.at(i));
        ranking++;
    }
    for(int i=0; i<m_activePlayers.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_activePlayers.at(i));
        ranking++;
    }
    for(int i=0; i<m_losers.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_losers.at(i));
        ranking++;
    }
}

void Mtmchkin::updateLeaderBoard(int playerIndex) {

    if(m_activePlayers.at(playerIndex)->isWinning())
    {
        m_winners.push_back(std::move(m_activePlayers.at(playerIndex)));
        m_activePlayers.erase(m_activePlayers.begin() + playerIndex);
    }
    else if(m_activePlayers.at(playerIndex)-> isLosing())
    {
        m_losers.insert(m_losers.begin(),std::move(m_activePlayers.at(playerIndex)));
        m_activePlayers.erase(m_activePlayers.begin() +playerIndex);
    }

}

void Mtmchkin::initiateLeaderBoard() {
    for(int i=0; i<m_playersQueue.size(); i++)
    {
        m_activePlayers.push_back(std::move(m_playersQueue.at(i)));
    }
}







