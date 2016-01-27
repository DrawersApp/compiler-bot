#ifndef BOT_H
#define BOT_H

#include <gloox/messagehandler.h>
#include <gloox/client.h>
#include <gloox/message.h>
#include "connListener.h"
#include <iostream>

using namespace std;
class Bot : public MessageHandler, LogHandler {
    private:
        Client* client;
        ConnListener* connListener;
    public:
        Bot();
        ~Bot();
        virtual void handleMessage( const Message& stanza, MessageSession* session = 0 );
        friend ostream& operator<<(ostream& os, const Message& stanza);
        virtual void handleLog( LogLevel level, LogArea area, const std::string& message )
        {
            cout << level << endl;
            cout << area << endl;
            cout << message.c_str() << endl;
        }

    const char * processMessage(const string);
};

#endif
