#include "Bot.h"

Bot::Bot() {
    JID jid("harshit1@ejabberd.sandwitch.in");
    client = new Client( jid, "tractor" );
    connListener = new ConnListener();
    client->registerMessageHandler( this );
    client->registerConnectionListener(connListener);
    client->connect(true);
}

Bot::~Bot() {
    delete client;
    delete connListener;
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
