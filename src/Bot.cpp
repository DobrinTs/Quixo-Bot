#include <algorithm>
#include <iostream>
using namespace std;
#include "Bot.h"

Bot::Bot(Board board, char botPlayingSymbol, char playerPlayingSymbol) :
    botPlayingSymbol(botPlayingSymbol), playerPlayingSymbol(playerPlayingSymbol)
{
    currentBoard = board;
}

Bot::~Bot()
{}

int Bot::MIN_INF = -1000;
int Bot::PLUS_INF = 1000;

Board Bot::minMaxDecision()
{
    int v = MIN_INF;
    Board boardAfterPick, boardAfterPut;
    Board boardAfterBotPlayed;

    int alpha = MIN_INF;
    int beta = PLUS_INF;

    for(auto it = Board::pickableCells.begin(); it != Board::pickableCells.end(); ++it)
    {
        char pickableCellValue = currentBoard.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == botPlayingSymbol)
        {
            boardAfterPick=currentBoard;
            boardAfterPick.pickCell(*it);
            for(auto putBack = boardAfterPick.validCellsToPutBack.begin();
                    putBack != boardAfterPick.validCellsToPutBack.end(); ++putBack)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(botPlayingSymbol, *putBack);

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
std::vector<int> Bot::cellWorth = {2, 3, 3, 3, 2,
                                   3, 1, 1, 1, 3,
                                   3, 1, 1, 1, 3,
                                   3, 1, 1, 1, 3,
                                   2, 3, 3, 3, 2
                                  };

int Bot::eval(const Board& board)
{
    int boardGoodness = 0;
    for(int i=0; i<25; i++)
    {
        char cellValue = board.cellValue(i);
        if(cellValue == botPlayingSymbol)
        {
            boardGoodness += cellWorth[i];
        }
        else if(cellValue == playerPlayingSymbol)
        {
            boardGoodness -= cellWorth[i];
        }
    }
    return boardGoodness;
}

int Bot::MAXIMUM_DEPTH = 5;

int Bot::minValue(const Board& board, int alpha, int beta, int depth)
{
    /*cout<<"--------------------------"<<endl;
    cout<<"MIN VALUE BOARD:"<<endl;
    board.print();
    cout<<"--------------------------"<<endl;*/
    char isTerminalResult = board.terminalTest();
    if(isTerminalResult == botPlayingSymbol)
    {
        return 120-depth;
    }
    else if(isTerminalResult == playerPlayingSymbol)
    {
        return depth - 120;
    }

    if(depth == MAXIMUM_DEPTH)
    {
        return eval(board);
    }

    int v = PLUS_INF;
    Board boardAfterPick, boardAfterPut;

    for(auto it = Board::pickableCells.begin(); it != Board::pickableCells.end(); ++it)
    {
        char pickableCellValue = board.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == playerPlayingSymbol)
        {
            boardAfterPick=board;
            boardAfterPick.pickCell(*it);
            for(auto putBack = boardAfterPick.validCellsToPutBack.begin();
                    putBack != boardAfterPick.validCellsToPutBack.end(); ++putBack)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(playerPlayingSymbol, *putBack);

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

int Bot::maxValue(const Board& board, int alpha, int beta, int depth)
{
    /*cout<<"--------------------------------"<<endl;
    cout<<"MAX VALUE BOARD:"<<endl;
    board.print();
    cout<<"--------------------------------"<<endl;*/
    char isTerminalResult = board.terminalTest();
    if(isTerminalResult == botPlayingSymbol)
    {
        return 120-depth;
    }
    else if(isTerminalResult == playerPlayingSymbol)
    {
        return depth - 120;
    }

    if(depth == MAXIMUM_DEPTH)
    {
        return eval(board);
    }

    int v = MIN_INF;
    Board boardAfterPick, boardAfterPut;

    for(auto it = Board::pickableCells.begin(); it != Board::pickableCells.end(); ++it)
    {
        char pickableCellValue = board.cellValue(*it);
        if(pickableCellValue == ' ' || pickableCellValue == botPlayingSymbol)
        {
            boardAfterPick=board;
            boardAfterPick.pickCell(*it);
            for(auto putBack = boardAfterPick.validCellsToPutBack.begin();
                    putBack != boardAfterPick.validCellsToPutBack.end(); ++putBack)
            {
                boardAfterPut = boardAfterPick;
                boardAfterPut.putPieceBack(botPlayingSymbol, *putBack);

                v=std::max(v, minValue(boardAfterPut, alpha, beta, depth+1));
                if(v >= beta) return v;
                alpha = std::max(alpha, v);
            }
        }
    }

    return v;
}
