#include<iostream>

#include "Human.h"

Human::Human(Board board, char humanPlayingSymbol, char opponentPlayingSymbol) :
    humanPlayingSymbol(humanPlayingSymbol), opponentPlayingSymbol(opponentPlayingSymbol)
{
    this->board = board;
}

Human::~Human()
{}

int Human::readUserInputOfCellCoordinates()
{
    int cellNumber;
    int row, col;

    std::cout<<std::endl<<"Enter cell coordinates: ";
    std::cin>>row>>col;
    while(row<1 || row>5 || col<0 || col>5)
    {
        std::cout<<std::endl<<"Coordinates out of range! Enter new coordinates: ";
        std::cin>>row>>col;
    }
    cellNumber = 5*(row -1) + (col - 1);

    return cellNumber;
}

Board Human::playMove(){
    pickCell();
    putBackPiece();

    return board;
}

void Human::pickCell() {
    int cellNumber = readUserInputOfCellCoordinates();

    while(!( Board::isCellPickable(cellNumber) &&
             (board.cellValue(cellNumber)==' '
                || board.cellValue(cellNumber) == humanPlayingSymbol)))
    {
        std::cout<<"Incorrect cell! Please enter a new one!"<<std::endl;
        cellNumber = readUserInputOfCellCoordinates();
    }
    board.pickCell(cellNumber);
    board.print();
}

void Human::putBackPiece() {
    int x, y;
    int cellNumber;

    std::cout<<"Valid moves to play: "<<std::endl;
    for(auto it = board.validCellsToPutBack.begin(); it != board.validCellsToPutBack.end(); ++it)
    {
        y = *it % 5 + 1;
        x = *it / 5 + 1;
        std::cout<<x<<" "<<y<<" "<<std::endl;
    }

    cellNumber = readUserInputOfCellCoordinates();
    while(!board.validCellsToPutBack.count(cellNumber))
    {
        std::cout<<"Not a playable move!"<<std::endl;
        cellNumber = readUserInputOfCellCoordinates();
    }

    board.putPieceBack(humanPlayingSymbol, cellNumber);
}
