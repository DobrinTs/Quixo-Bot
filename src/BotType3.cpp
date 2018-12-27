#include "BotType3.h"

BotType3::BotType3(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol) :
    BotType1(startingBoard, botPlayingSymbol, opponentPlayingSymbol),
    BotType2(startingBoard, botPlayingSymbol, opponentPlayingSymbol),
    BotMinMax(startingBoard, botPlayingSymbol, opponentPlayingSymbol)
{}

BotType3::~BotType3()
{}

int BotType3::eval(const Board& board) {
    int eval1 = BotType1::eval(board);
    int eval2 = BotType2::eval(board);

    return eval1 + eval2;
}
