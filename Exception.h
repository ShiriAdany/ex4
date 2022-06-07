//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>

class Exception: public std::exception
{
    class DeckFileNotFound{};

    class DeckFileFormatError{};

    class DeckFileInvalidSize{};

};
#endif //EX4_EXCEPTION_H
