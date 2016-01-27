//
// Created by Nishant Kumar Pathak on 05/02/16.
//

#include "BotStringElement.h"

BotStringElement::BotStringElement(BotStringType type, string placeHolder, string text, list <string> defaults) {
    this->type = type;
    this->placeHolder = placeHolder;
    this->text = text;
    this->defaults = defaults;
}
BotStringElement::BotStringElement(BotStringType type, string placeHolder, string text) {
    this->type = type;
    this->placeHolder = placeHolder;
    this->text = text;
}

BotStringElement::BotStringElement(BotStringType type, string text) {
    this->type = type;
    this->placeHolder = text;
    this->text = text;
}

template<typename Writer>
void BotStringElement::Serialize(Writer &writer) const {
    writer.String("type");
    writer.String(type);
    writer.String("placeholder");
    writer.String(placeHolder);
    writer.String("text");
    writer.String(text);
    writer.String("defaults");
    writer.List(defaults);
}
