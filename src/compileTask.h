//
// Created by Nishant Kumar Pathak on 31/01/16.
//

#include "builder.h"
#include "DrawersBotString.h"

#ifndef ECHO_BOT_COMPILETASK_H
#define ECHO_BOT_COMPILETASK_H

class CompileOperation : public Operation {
public:
    static DrawersBotString compile;
    CompileOperation(string fileName, string lang) {
        file = fileName;
        language = lang;
        rspDoc = new Document();
    }


    virtual ~CompileOperation() {
        delete rspDoc;
    }

    Document * execute();

private:
    Document *rspDoc;
};
#endif //ECHO_BOT_COMPILETASK_H
