#include "bot.h"
#include "jsonExtension.h"
#include <gloox/disco.h>
#include <gloox/client.h>
#include <gloox/jid.h>
#include <ctime>
#include <sstream>

#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "builder.h"
#include "compileTask.h"

using namespace gloox;
using namespace rapidjson;


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

        Message msg(Message::Chat, stanza.from(), processMessage(stanza.body()));

        std::stringstream ss;
        // convert it to mills
        ss << std::time(nullptr) * 1000;
        std::string json("{\"timestamp\": " + ss.str() + ",\"subType\": \"TEXT\"}");
        Document d;
        d.Parse(json.c_str());
        Value& s = d["timestamp"];

        cout << s.GetDouble() << endl;

        msg.addExtension(new JsonExtension(json));
        msg.setID(ss.str());
        client->send(msg);
    }
}


const char * Bot::processMessage(const string incomingMessage) {

    string task = "compile";
    string file = "rawFiles/test.cpp";
    string language = "CPP";
    CompileOperation *compileTask = new CompileOperation(file, language);
   // DrawersBotString botString = new DrawersBotString(new list<BotStringElement>(), nullptr);
    Document *d = compileTask->execute();

    return (const char *) new string();
}
