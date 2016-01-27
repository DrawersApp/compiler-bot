//
// Created by Nishant Kumar Pathak on 05/02/16.
//

#ifndef ECHO_BOT_BOTSTRINGTYPE_H
#define ECHO_BOT_BOTSTRINGTYPE_H

#include <map>

enum class BotStringType {
    D,
    L,
    T,
    S,
    U,
    LI,
    I
};


using namespace std;
static const map <BotStringType, const char *> EnumStringsMap = {
        {BotStringType::D, "DATE"},
        {BotStringType::L, "LOCATION"},
        {BotStringType::T, "TIME"},
        {BotStringType::S, "STRING"},
        {BotStringType::U, "UNEDITABLE"},
        {BotStringType::LI, "LIST"},
        {BotStringType::I, "INTEGER"}
};

#endif //ECHO_BOT_BOTSTRINGTYPE_H
