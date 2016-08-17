//
// Created by Mariano de Diego Biosca on 19/5/16.
//

#include <iostream>
#include "Gamer.h"

Gamer::Gamer(int ID, int numPlayers,MessageBus* msgBus)
{
    _msg.msg = BUNNY_BUNNY;
    _msg.receiver = -1;
    _msg.sender = ID;
    _msg.checksum = 0;
    _msgBus = msgBus;
    _ID = ID;
    _numPlayers = numPlayers;
}
Gamer::~Gamer()
{

}

void Gamer::handleMessage(Msg *msg)
{

    if ((msg->msg == BUNNY_BUNNY)&&(msg->receiver == _ID))
    {
        int rec = -1;
        do
        {
            rec = rand() % (_numPlayers-1);
        }while(rec == _ID);
        std::cout << rec << std::endl;

        std::cout << "GAMER ID:" << _ID << " says: BUNNY BUNNY!! to GAMER ID:" << rec << std::endl;
        _msgBus->popMessage();
        _msg.sender = _ID;
        _msg.receiver = rec;

        _msg.msg = BUNNY_BUNNY;
        //_msgBus->pushMessage(&_msg);
    }
    else if ( ((msg->receiver+1) == _ID) || ((msg->receiver-1) == _ID) )
    {
        std::cout << "GAMER ID:" << _ID << " says: TOKI TOKI!!" << std::endl;
        _msg.sender = -1;
        _msg.receiver = -1;
        std::cout << _msg.receiver << std::endl;
    }
    else
    {
        std::cout << "GAMER ID:" << _ID << " says: OOGA CHAKA!!" << std::endl;
        _msg.sender = -1;
        _msg.receiver = -1;
        std::cout << _msg.receiver << std::endl;
    }

}

void Gamer::pushMessage()
{
    if(_msg.msg == BUNNY_BUNNY)
    {
        _msgBus->pushMessage(&_msg);
    }
}