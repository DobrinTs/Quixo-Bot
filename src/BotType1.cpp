#include "BotType1.h"

BotType1::BotType1(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol)
    : Bot(startingBoard, botPlayingSymbol, opponentPlayingSymbol)
{}

BotType1::~BotType1()
{}

std::vector<int> BotType1::cellWorth = {2, 3, 3, 3, 2,
                                   3, 1, 1, 1, 3,
                                   3, 1, 1, 1, 3,
                                   3, 1, 1, 1, 3,
                                   2, 3, 3, 3, 2
                                  };

int BotType1::eval(const Board& board)
{
    int boardGoodness = 0;
    for(int i=0; i<25; i++)
    {
        char cellValue = board.cellValue(i);
        if(cellValue == botPlayingSymbol)
        {
            boardGoodness += cellWorth[i];
        }
        else if(cellValue == opponentPlayingSymbol)
        {
            boardGoodness -= cellWorth[i];
        }
    }
    return boardGoodness;
}
