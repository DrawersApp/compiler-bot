//
// Created by Nishant Kumar Pathak on 05/02/16.
//

#include "DrawersBotString.h"

DrawersBotString::DrawersBotString(list<BotStringElement> botStringElements, string operationsType) {
    this->botStringElements = botStringElements;
    this->operationsType = operationsType;

}

template<typename Writer>
void DrawersBotString::Serialize(Writer &writer) const {
    writer.StartObject();
    writer.String("botStringElements");
    writer.StartArray();
    for (std::list<BotStringElement>::const_iterator dependentItr = botStringElements.begin();
         dependentItr != botStringElements.end(); ++dependentItr)
        dependentItr->Serialize(writer);
    writer.EndArray();
    writer.EndObject();

}
