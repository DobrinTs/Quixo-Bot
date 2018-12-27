#include "Human.h"

Human::Human(Board startingBoard, char humanPlayingSymbol, char opponentPlayingSymbol) :
    humanPlayingSymbol(humanPlayingSymbol), opponentPlayingSymbol(opponentPlayingSymbol)
{
    this->startingBoard = startingBoard;
}

Human::~Human()
{}


Board Human::playMove(){}
