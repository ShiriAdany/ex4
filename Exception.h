//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>
#include <cstring>
#include <string>

class DeckExeptions: public std::exception
{
public:
    virtual const char* what() const noexcept = 0;
};

class PlayerExeptions : public std::exception
{
public:
    const char* what() const noexcept override{
        return exception::what();
    };
};

class InvalidName : public PlayerExeptions
{
public:
    const char * what() const noexcept override
    {
        return "Player error: Invalid Name";
    }
};


class DeckFileNotFound : public DeckExeptions{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    };
};


class DeckFileInvalidSize: public DeckExeptions{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    };
};



class DeckFileFormatError: public DeckExeptions{
public:
    DeckFileFormatError(int line): message("Deck File Error: File format error in line " + std::to_string(line)){};

    const char* what() const noexcept override{
        return message.c_str();
    }

private:
    std::string message;

};



#endif //EX4_EXCEPTION_H
