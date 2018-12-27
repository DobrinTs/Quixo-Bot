#include <algorithm>

#include "BotMinMax.h"

BotMinMax::BotMinMax(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol) :
    botPlayingSymbol(botPlayingSymbol), opponentPlayingSymbol(opponentPlayingSymbol)
{
    this->startingBoard = startingBoard;
}

BotMinMax::~BotMinMax()
{}

int BotMinMax::MIN_INF = -1000;
int BotMinMax::PLUS_INF = 1000;

Board BotMinMax::minMaxDecision()
{
    int v = MIN_INF;
    Board boardAfterPick, boardAfterPut;
    Board boardAfterBotPlayed;

    int alpha = MIN_INF;
    int beta = PLUS_INF;

    std::vector<int> pickOrder = Board::generateRandomPickOrder();
    for(auto it = pickOrder.begin(); it != pickOrder.end(); ++it)
    {
        char pickableCellValue = startingBoard.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == botPlayingSymbol)
        {
            boardAfterPick=startingBoard;
            boardAfterPick.pickCell(*it);
            for(auto putBackCell = boardAfterPick.validCellsToPutBack.begin();
                    putBackCell != boardAfterPick.validCellsToPutBack.end(); ++putBackCell)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(botPlayingSymbol, *putBackCell);

                int minResult = minValue(boardAfterPut, alpha, beta, 1);

                if(minResult > v)
                {
                    v=minResult;
                    boardAfterBotPlayed = boardAfterPut;
                }
                if(v >= beta) break;
                alpha = std::max(alpha, v);
            }
        }

    }

    return boardAfterBotPlayed;
}

int BotMinMax::MAXIMUM_DEPTH = 5;

int BotMinMax::minValue(const Board& board, int alpha, int beta, int depth)
{
    char isTerminalResult = board.terminalTest();
    if(isTerminalResult == botPlayingSymbol)
    {
        return 120-depth;
    }
    else if(isTerminalResult == opponentPlayingSymbol)
    {
        return depth - 120;
    }

    if(depth == MAXIMUM_DEPTH)
    {
        return eval(board);
    }

    int v = PLUS_INF;
    Board boardAfterPick, boardAfterPut;

    std::vector<int> pickOrder = Board::generateRandomPickOrder();
    for(auto it = pickOrder.begin(); it != pickOrder.end(); ++it)
    {
        char pickableCellValue = board.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == opponentPlayingSymbol)
        {
            boardAfterPick=board;
            boardAfterPick.pickCell(*it);
            for(auto putBackCell = boardAfterPick.validCellsToPutBack.begin();
                    putBackCell != boardAfterPick.validCellsToPutBack.end(); ++putBackCell)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(opponentPlayingSymbol, *putBackCell);

                v=std::min(v, maxValue(boardAfterPut, alpha, beta, depth+1));
                if(v <= alpha)
                {
                    return v;
                }
                beta = std::min(beta, v);
            }
        }
    }

    return v;
}

int BotMinMax::maxValue(const Board& board, int alpha, int beta, int depth)
{
    char isTerminalResult = board.terminalTest();
    if(isTerminalResult == botPlayingSymbol)
    {
        return 120-depth;
    }
    else if(isTerminalResult == opponentPlayingSymbol)
    {
        return depth - 120;
    }

    if(depth == MAXIMUM_DEPTH)
    {
        return eval(board);
    }

    int v = MIN_INF;
    Board boardAfterPick, boardAfterPut;

    std::vector<int> pickOrder = Board::generateRandomPickOrder();
    for(auto it = pickOrder.begin(); it != pickOrder.end(); ++it)
    {
        char pickableCellValue = board.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == botPlayingSymbol)
        {
            boardAfterPick=board;
            boardAfterPick.pickCell(*it);
            for(auto putBackCell = boardAfterPick.validCellsToPutBack.begin();
                    putBackCell != boardAfterPick.validCellsToPutBack.end(); ++putBackCell)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(botPlayingSymbol, *putBackCell);

                v=std::max(v, minValue(boardAfterPut, alpha, beta, depth+1));
                if(v >= beta) return v;
                alpha = std::max(alpha, v);
            }
        }
    }

    return v;
}

Board BotMinMax::playMove() {
    return minMaxDecision();
}
