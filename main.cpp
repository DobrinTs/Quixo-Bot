#include <iostream>
#include <vector>

#include "Board.h"
#include "Human.h"
#include "BotMinMax.h"
#include "BotType1.h"
#include "BotType2.h"
#include "BotType3.h"
#include "BotHillClimb.h"

using namespace std;

void playQuixo()
{
    int playerTypes[2];
    cout<<"Player 1 should be: 0 for human, 1 for type1, 2 for type2, 3 for type3, 4 for hillclimb: ";
    cin>>playerTypes[0];

    cout<<"Player 2 should be: 0 for human, 1 for type1, 2 for type2, 3 for type3, 4 for hillclimb: ";
    cin>>playerTypes[1];

    Board playingBoard;
    playingBoard.print();

    char currentStatus;
    int turn = 0;
    while((currentStatus = playingBoard.terminalTest()) == 'N')
    {
        int playerIdx = turn%2;
        int playerType = playerTypes[playerIdx];
        char currentPlayerSymbol = playerIdx == 0 ? 'X' : 'O';
        char otherPlayerSymbol = playerIdx == 0 ? 'O' : 'X';

        cout<<"--------------------------------"<<endl;
        cout<<"PLAYER "<< playerIdx+1  <<" TURN!"<<endl;
        cout<<"--------------------------------"<<endl;

        Player* currentPlayer;

        switch(playerType)
        {
        case 0:
            currentPlayer = new Human(playingBoard, currentPlayerSymbol, otherPlayerSymbol);
            break;
        case 1:
            currentPlayer = new BotType1(playingBoard, currentPlayerSymbol, otherPlayerSymbol);
            break;
        case 2:
            currentPlayer = new BotType2(playingBoard, currentPlayerSymbol, otherPlayerSymbol);
            break;
        case 3:
            currentPlayer = new BotType3(playingBoard, currentPlayerSymbol, otherPlayerSymbol);
            break;
        case 4:
            currentPlayer = new BotHillClimb(playingBoard, currentPlayerSymbol, otherPlayerSymbol);
            break;
        }

        playingBoard = currentPlayer->playMove();
        playingBoard.print();

        turn++;
    }

    if(currentStatus == 'X')
    {
        cout<<"X WINS!!"<<endl;
        cout<<"Played for "<<turn<<" turns.";
    }
    else if(currentStatus == 'O')
    {
        cout<<"O WINS!!"<<endl;
        cout<<"Played for "<<turn<<" turns.";

    }
}

int main()
{
    playQuixo();
}
