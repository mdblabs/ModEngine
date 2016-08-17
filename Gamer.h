//
// Created by Mariano de Diego Biosca on 19/5/16.
//

#ifndef MODENGINE_GAMER_H
#define MODENGINE_GAMER_H


#include "Agent.h"
#include "Message.h"

class Gamer : public Agent
{

    public:
        Gamer(int ID, int numPlayers,MessageBus* msgBus);
        ~Gamer();

        void handleMessage(Msg* msg);
        void pushMessage();
        int getID(){return _ID;};

    private:
        Msg _msg;
        int _ID;
        int _numPlayers;

};


#endif //MODENGINE_GAMER_H
