//
// Created by Nishant Kumar Pathak on 31/01/16.
//

#ifndef ECHO_BOT_BUILDER_H
#define ECHO_BOT_BUILDER_H

#include <string>
#include "../include/rapidjson/document.h"
#include "DrawersBotString.h"

using namespace std;
using namespace rapidjson;

class Operation {
public:
    virtual Document * execute() = 0;

protected:
    string client_secret = "0bc8b2b7d544c92a6f81150454c7cd412b995070";

    // cloudinary path to cpp file
    string file;

    // language
    string language;
};

#endif //ECHO_BOT_BUILDER_H