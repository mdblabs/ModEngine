//
// Created by Mariano de Diego Biosca on 4/5/16.
//

#ifndef MODENGINE_MESSAGE_H
#define MODENGINE_MESSAGE_H

#include <queue>
#include <string>

#define BUNNY_BUNNY 1
#define TOKI_TOKI 2
#define OOGA_CHAKA 3

struct Msg
{
    int msg;
    int receiver;
    int sender;
    int checksum;
};

class MessageBus
{
    public:
        MessageBus();
        ~MessageBus();

        unsigned long getSize();
        Msg* getMessage();
        void pushMessage(Msg* msg);
        void popMessage();

    private:
        std::queue<Msg*> _msgQueue;
};

#endif //MODENGINE_MESSAGE_H
