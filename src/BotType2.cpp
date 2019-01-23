#include "BotType2.h"

BotType2::BotType2(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol)
    : BotMinMax(startingBoard, botPlayingSymbol, opponentPlayingSymbol)
{}

BotType2::~BotType2()
{}

int BotType2::checkSymbolAndChangeGoodness(char cellValue, int& boardGoodness, int addedGoodness)
{
    if(cellValue == botPlayingSymbol)
    {
        boardGoodness += addedGoodness;
    }
    else if(cellValue == opponentPlayingSymbol)
    {
        boardGoodness -= addedGoodness;
    }
}

void BotType2::checkForThreesAndFours(const Board& board, int& boardGoodness, int start, int end, int step)
{
    for(int j=start; j<end; j+= step)
    {
        if(board.checkSequence(j, j + 2*step, step))
        {
            checkSymbolAndChangeGoodness(board.cellValue(j), boardGoodness, 1);
        }

        if(j< (start + 2*step) && board.checkSequence(j, j + 3*step, step))
        {
            checkSymbolAndChangeGoodness(board.cellValue(j), boardGoodness, 3);
        }
    }
}

int BotType2::eval(const Board& board)
{
    int boardGoodness = 0;
    int mainDiagStart = 0;
    int mainDiagStep = 6;
    int secondaryDiagStart = 4;
    int secondaryDiagStep= 4;

    checkForThreesAndFours(board, boardGoodness, mainDiagStart,
                           mainDiagStart + 3*mainDiagStep, mainDiagStep);
    checkForThreesAndFours(board, boardGoodness, secondaryDiagStart,
                           secondaryDiagStart + 3*secondaryDiagStep, secondaryDiagStep);

    for(int i=0; i<5; i++)
    {
        int rowStart = i*5;
        int rowStep = 1;
        int colStart = i;
        int colStep = 5;
        checkForThreesAndFours(board, boardGoodness, rowStart, rowStart + 3*rowStep, rowStep);
        checkForThreesAndFours(board, boardGoodness, colStart, colStart + 3*colStep, colStep);
    }

    return boardGoodness;
}
