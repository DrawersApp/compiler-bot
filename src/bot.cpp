#include "bot.h"
#include "jsonExtension.h"
#include <gloox/disco.h>
#include <gloox/client.h>
#include <gloox/jid.h>
#include <ctime>
#include <sstream>

using namespace gloox;

Bot::Bot() {
    // mailto: harshit.bangar@gmail.com for username and password
    string username = "e0753a58-9919-4b91-9352-398f9fc67044@ejabberd.sandwitch.in";
    string password = "car";

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

        //{"timestamp":1453805268796,"subType":"TEXT"}
        std::stringstream ss;
        ss << std::time(nullptr);
        std::string json("{\"timestamp\": " + ss.str() + ",\"subType\": \"TEXT\"}");

        msg.addExtension(new JsonExtension(json));
        msg.setID(ss.str());
        client->send(msg);
    }
}
