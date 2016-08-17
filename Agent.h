//
// Created by Mariano de Diego Biosca on 19/5/16.
//

#ifndef MODENGINE_AGENT_H
#define MODENGINE_AGENT_H

#include "Message.h"

class Agent
{
    public:
        Agent();
        ~Agent();

        MessageBus *_msgBus;

        virtual void handleMessage(Msg *msg);

};


#endif //MODENGINE_AGENT_H
