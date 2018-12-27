#include "BotHillClimb.h"

BotHillClimb::BotHillClimb(Board board, char botPlayingSymbol, char opponentPlayingSymbol) :
    botPlayingSymbol(botPlayingSymbol), opponentPlayingSymbol(opponentPlayingSymbol)
{
    this->board = board;
}

BotHillClimb::~BotHillClimb()
{}

Board BotHillClimb::playMove()
{
    return hillClimbDecision();
}

Board BotHillClimb::hillClimbDecision()
{
    int v = -10000;
    Board boardAfterPick, boardAfterPut;
    Board boardAfterBotPlayed;

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

                int evalResult = eval(boardAfterPut);

                if(evalResult > v)
                {
                    v=evalResult;
                    boardAfterBotPlayed = boardAfterPut;
                }
            }
        }

    }

    return boardAfterBotPlayed;
}

std::vector<int> BotHillClimb::cellWorth = {2, 3, 3, 3, 2,
                                            3, 1, 1, 1, 3,
                                            3, 1, 1, 1, 3,
                                            3, 1, 1, 1, 3,
                                            2, 3, 3, 3, 2
                                            };

int BotHillClimb::eval(const Board& board)
{
    if(board.terminalTest() == botPlayingSymbol) {
        return 1000;
    }
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

