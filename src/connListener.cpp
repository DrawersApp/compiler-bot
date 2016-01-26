#include <iostream>
#include "connListener.h"

void ConnListener::onConnect() {
    cout << "ConnListener::onConnect()" << endl;
}

void ConnListener::onDisconnect(ConnectionError e) {
    cout << "ConnListener::onDisconnect() " << e << endl;
}

bool ConnListener::onTLSConnect(const CertInfo& info) {
    cout << "ConnListener::onTLSConnect()" << endl;
    return true;
}

