#include <iostream>
#include <vector>

#include "Board.h"
#include "Bot.h"
#include "BotType1.h"
#include "BotType2.h"

using namespace std;

void playQuixo()
{
    Board playingBoard;
    playingBoard.print();


    char currentStatus;
    while((currentStatus = playingBoard.terminalTest()) == 'N')
    {
        cout<<"--------------------------------"<<endl;
        cout<<"YOUR TURN!"<<endl;
        cout<<"--------------------------------"<<endl;
        playingBoard.readAndPickCell('X');

        playingBoard.print();
        playingBoard.readAndPutBack('X');
        playingBoard.print();

        currentStatus = playingBoard.terminalTest();
        if(currentStatus != 'N') {
            break;
        }

        cout<<"--------------------------------"<<endl;
        cout<<"BOT PLAYS!"<<endl;
        cout<<"--------------------------------"<<endl;
        BotType2 ai(playingBoard, 'O', 'X');
        playingBoard = ai.minMaxDecision();
        playingBoard.print();

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
