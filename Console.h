//
// Created by Mariano de Diego Biosca on 3/5/16.
//

#ifndef MODENGINE_CONSOLE_H
#define MODENGINE_CONSOLE_H

#include <string>

#include "Agent.h"
#include "Message.h"

class Console : public Agent
{
    public:
        Console(MessageBus* msgBus);
        ~Console();

        void Update();
        void handleMessage(Msg* msg);

    private:
};


#endif //MODENGINE_CONSOLE_H
