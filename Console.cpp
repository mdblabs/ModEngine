//
// Created by Mariano de Diego Biosca on 3/5/16.
//
#include <iostream>
#include "Console.h"

Console::Console(MessageBus* msgBus)
{
    _msgBus = msgBus;
}

Console::~Console()
{

}

void Console::Update()
{
    handleMessage(_msgBus->getMessage());
}

void Console::handleMessage(Msg *msg)
{
    std::cout << "MESSAGE:" << msg->msg << " SEND FROM:"<< msg->sender <<" SENT TO:" << msg->receiver << std::endl;
}
