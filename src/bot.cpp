#include "Bot.h"

Bot::Bot() {
    // mailto: harshit.bangar@gmail.com for username and password
    string username = "REPLACE_ME";
    string password = "REPLACE_ME";
    JID jid(username);
    client = new Client( jid, password );
    connListener = new ConnListener();
    client->registerMessageHandler( this );
    client->registerConnectionListener(connListener);
    client->connect(true);
}

Bot::~Bot() {
    delete client;
    delete connListener;
}

ostream& operator<<(ostream& os, Message::MessageType type) {
    switch (type) {
        case Message::Chat:
            os << "Chat";
            break;
        case Message::Error:
            os << "Error";
            break;
        case Message::Groupchat:
            os << "Groupchat";
            break;
        case Message::Headline:
            os << "Headline";
            break;
        case Message::Normal:
            os << "Normal";
            break;
        case Message::Invalid:
            os << "Invalid";
            break;
        default:
            os << "unknown type";
            break;
    }
    return os;
}

ostream& operator<<(ostream& os, const Message& stanza) {
    os << "type:'" << stanza.subtype()
       << "' from:'" << stanza.from().full()
       << "' body:'" << stanza.body() << "'";
    return os;
}

void Bot::handleMessage( const Message& stanza, MessageSession* session ) {
    cout << "Received message: " << stanza << endl;
    Message msg(Message::Chat, stanza.from(), stanza.body() );
    client->send( msg );
}
