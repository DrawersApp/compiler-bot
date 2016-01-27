#include "bot.h"
#include "jsonExtension.h"
#include <gloox/disco.h>
#include <ctime>
#include <sstream>

using namespace gloox;

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

    client->logInstance().registerLogHandler(LogLevelDebug, LogAreaAll, this);
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

    if (stanza.body().length()) {
        cout << "Received message: " << stanza << endl;
        Message msg(Message::Chat, stanza.from(), "Bot Says: " + stanza.body());

        std::stringstream ss;
        // convert it to mills
        ss << std::time(nullptr) * 1000;
        std::string json("{\"timestamp\": " + ss.str() + ",\"subType\": \"TEXT\"}");

        msg.addExtension(new JsonExtension(json));
        msg.setID(ss.str());
        client->send(msg);
    }
}
