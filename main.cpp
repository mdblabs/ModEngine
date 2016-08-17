#include <iostream>
#include <list>
#include <time.h>
#include "Message.h"
#include "Console.h"
#include "Gamer.h"

using namespace std;

int main()
{

    MessageBus bus = MessageBus();
    MessageBus* ptrBus = &bus;
    Msg initialMsg;
    Msg* ptrInitialMsg;

    srand (time(NULL));

    int numberOfPlayers = rand() % 10;
    int numberOfTurns = rand() % 10;
    if ((numberOfPlayers > 3) && (numberOfTurns > 2))
    {
        initialMsg.sender = 0;
        initialMsg.receiver = rand() % (numberOfPlayers-1);
        initialMsg.msg = BUNNY_BUNNY;
        ptrInitialMsg = &initialMsg;
        ptrBus->pushMessage(ptrInitialMsg);
    }
    else
    {
        cout << "Not enought bunnies in the circle! " << endl;
        return -1;
    }


    std::list<Gamer> circle;

    for(int i = 0;i<numberOfPlayers;i++)
    {
        Gamer Player = Gamer(i,numberOfPlayers,ptrBus);
        circle.push_back(Player);
    }
    std::cout << "Starting Bunny Bunny Game!!" << std::endl;
    std::cout << "Number of Players: " << numberOfPlayers << std::endl;
    std::cout << "Number of Turns: " << numberOfTurns << std::endl;

    while(numberOfTurns)
    {
        std::cout << "====== TURNS LEFT: " << numberOfTurns << "======" << std::endl;
        numberOfTurns--;
        for (std::list<Gamer>::iterator it=circle.begin(); it != circle.end(); ++it)
        {
            (it)->handleMessage(ptrBus->getMessage());
        }
        for (std::list<Gamer>::iterator it=circle.begin(); it != circle.end(); ++it)
        {
            (it)->pushMessage();
        }
    }


    return 0;
}