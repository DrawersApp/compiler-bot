//
// Created by Nishant Kumar Pathak on 05/02/16.
//

#ifndef ECHO_BOT_DRAWERSBOTSTRING_H
#define ECHO_BOT_DRAWERSBOTSTRING_H


#include "BotStringElement.h"

class DrawersBotString {
private:
    list<BotStringElement> botStringElements;
    string operationsType;

public:
    DrawersBotString(list<BotStringElement>, string operationsType);
    template <typename Writer>
    void Serialize(Writer& writer) const;

};


#endif //ECHO_BOT_DRAWERSBOTSTRING_H
