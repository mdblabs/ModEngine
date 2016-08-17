//
// Created by Mariano de Diego Biosca on 4/5/16.
//

#include "Message.h"

MessageBus::MessageBus()
{

}

MessageBus::~MessageBus()
{

}

Msg* MessageBus::getMessage()
{
    return _msgQueue.back();
}

unsigned long MessageBus::getSize()
{
    return _msgQueue.size();
}

void MessageBus::pushMessage(Msg *msg)
{
    _msgQueue.push(msg);
}

void MessageBus::popMessage()
{
    _msgQueue.pop();
}