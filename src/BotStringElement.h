//
// Created by Nishant Kumar Pathak on 05/02/16.
//

#ifndef ECHO_BOT_BOTSTRINGELEMENT_H
#define ECHO_BOT_BOTSTRINGELEMENT_H

#include <list>
#include <string>
#include "../include/rapidjson/writer.h"
#include "BotStringType.h"

using namespace std;
using namespace rapidjson;

class BotStringElement {
private:
    string placeHolder;
    string text;
    list <string> defaults;
    BotStringType type;

public:
    BotStringElement(BotStringType, string, string, list <string>);
    BotStringElement(BotStringType, string, string);
    BotStringElement(BotStringType, string);

    virtual ~BotStringElement() {}

    template <typename Writer>
    void Serialize(Writer& writer) const;
};


#endif //ECHO_BOT_BOTSTRINGELEMENT_H
