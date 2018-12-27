#include <iostream>
#include <vector>

#include "Board.h"
#include "Human.h"
#include "Bot.h"
#include "BotType1.h"
#include "BotType2.h"

using namespace std;

void playQuixo()
{
    char dummy;
    Board playingBoard;
    playingBoard.print();


    char currentStatus;
    while((currentStatus = playingBoard.terminalTest()) == 'N')
    {
        cout<<"--------------------------------"<<endl;
        cout<<"YOUR TURN!"<<endl;
        cout<<"--------------------------------"<<endl;

        //Human me(playingBoard, 'X', 'O');
        //playingBoard = me.playMove();
        //playingBoard.print();

        BotType1 ai1(playingBoard, 'X', 'O');
        playingBoard = ai1.playMove();
        playingBoard.print();
        //cin>>dummy;

        currentStatus = playingBoard.terminalTest();
        if(currentStatus != 'N') {
            break;
        }

        cout<<"--------------------------------"<<endl;
        cout<<"BOT PLAYS!"<<endl;
        cout<<"--------------------------------"<<endl;
        BotType2 ai(playingBoard, 'O', 'X');
        playingBoard = ai.playMove();
        playingBoard.print();
        //cin>>dummy;
    }

    if(currentStatus == 'X')
    {
        cout<<"X WINS!!";
    }
    else if(currentStatus == 'O')
    {
        cout<<"O WINS!!";
    }
}

int main()
{
    playQuixo();
}
