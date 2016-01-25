#ifndef CONNLISTENER_H
#define CONNLISTENER_H

#include <gloox/connectionlistener.h>
#include <iostream>
#include <string>

using namespace gloox;
using namespace std;

class ConnListener : public ConnectionListener {
    public:
        virtual void onConnect();
        virtual void onDisconnect(ConnectionError e);
        virtual bool onTLSConnect(const CertInfo& info);
};

#endif
