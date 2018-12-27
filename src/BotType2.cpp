#include "BotType2.h"

BotType2::BotType2(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol)
    : Bot(startingBoard, botPlayingSymbol, opponentPlayingSymbol)
{}

BotType2::~BotType2()
{}

int BotType2::eval(const Board& board)
{
    int boardGoodness = 0;

    for(int i=0; i<25; i+=5)
    {
        for(int j=i; j<i+3; j++)
        {
            if(board.cellValue(j) == board.cellValue(j+1) && board.cellValue(j) == board.cellValue(j+2) )
            {
                if(board.cellValue(j) == botPlayingSymbol)
                {
                    boardGoodness += 1;
                }
                else if(board.cellValue(j) == opponentPlayingSymbol)
                {
                    boardGoodness -= 1;
                }
            }
        }

        for(int j=i; j<i+2; j++)
        {
            if(board.cellValue(j) == board.cellValue(j+1) && board.cellValue(j) == board.cellValue(j+2)
                    && board.cellValue(j) == board.cellValue(j+3))
            {
                if(board.cellValue(j) == botPlayingSymbol)
                {
                    boardGoodness += 3;
                }
                else if(board.cellValue(j) == opponentPlayingSymbol)
                {
                    boardGoodness -= 3;
                }
            }
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=i; j<i+15; j+=5)
        {
            if(board.cellValue(j) == board.cellValue(j+5) && board.cellValue(j) == board.cellValue(j+10) )
            {
                if(board.cellValue(j) == botPlayingSymbol)
                {
                    boardGoodness += 1;
                }
                else if(board.cellValue(j) == opponentPlayingSymbol)
                {
                    boardGoodness -= 1;
                }
            }
        }

        for(int j=i; j<i+10; j+=5)
        {
            if(board.cellValue(j) == board.cellValue(j+5) && board.cellValue(j) == board.cellValue(j+10)
                    && board.cellValue(j) == board.cellValue(j+15))
            {
                if(board.cellValue(j) == botPlayingSymbol)
                {
                    boardGoodness += 3;
                }
                else if(board.cellValue(j) == opponentPlayingSymbol)
                {
                    boardGoodness -= 3;
                }
            }
        }
    }

    for(int j=0; j<18; j+=6)
    {
        if(board.cellValue(j) == board.cellValue(j+6) && board.cellValue(j) == board.cellValue(j+12) )
        {
            if(board.cellValue(j) == botPlayingSymbol)
            {
                boardGoodness += 1;
            }
            else if(board.cellValue(j) == opponentPlayingSymbol)
            {
                boardGoodness -= 1;
            }
        }
    }

    for(int j=0; j<12; j+=6)
    {
        if(board.cellValue(j) == board.cellValue(j+6) && board.cellValue(j) == board.cellValue(j+12)
            && board.cellValue(j) == board.cellValue(j+18) )
        {
            if(board.cellValue(j) == botPlayingSymbol)
            {
                boardGoodness += 3;
            }
            else if(board.cellValue(j) == opponentPlayingSymbol)
            {
                boardGoodness -= 3;
            }
        }
    }

    for(int j=4; j<16; j+=4)
    {
        if(board.cellValue(j) == board.cellValue(j+4) && board.cellValue(j) == board.cellValue(j+8) )
        {
            if(board.cellValue(j) == botPlayingSymbol)
            {
                boardGoodness += 1;
            }
            else if(board.cellValue(j) == opponentPlayingSymbol)
            {
                boardGoodness -= 1;
            }
        }
    }

    for(int j=0; j<12; j+=4)
    {
        if(board.cellValue(j) == board.cellValue(j+4) && board.cellValue(j) == board.cellValue(j+8)
            && board.cellValue(j) == board.cellValue(j+12) )
        {
            if(board.cellValue(j) == botPlayingSymbol)
            {
                boardGoodness += 3;
            }
            else if(board.cellValue(j) == opponentPlayingSymbol)
            {
                boardGoodness -= 3;
            }
        }
    }


    return boardGoodness;
}
