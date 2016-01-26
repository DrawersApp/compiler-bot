#ifndef BOT_H
#define BOT_H

#include <gloox/messagehandler.h>
#include <gloox/client.h>
#include <gloox/message.h>
#include "ConnListener.h"
#include <iostream>

using namespace std;
class Bot : public MessageHandler {
    private:
        Client* client;
        ConnListener* connListener;
    public:
        Bot();
        ~Bot();
        virtual void handleMessage( const Message& stanza, MessageSession* session = 0 );
        friend ostream& operator<<(ostream& os, const Message& stanza);

};

#endif
