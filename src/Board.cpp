#include "Board.h"
#include<vector>
#include<iostream>

Board::Board()
{
    board = std::vector<char>(25, ' ');
}

Board::~Board()
{}

void Board::print() const
{
    for(int i=0; i<25; i++)
    {
        if(i!=0 && i%5 == 0)
        {
            std::cout<<std::endl<<"-----------------"
                     <<std::endl;
        }
        std::cout<<board[i];
        if(i%5 != 4)
        {
            std::cout<<" | ";
        }
    }
    std::cout<<std::endl;
}

int Board::readUserInputOfCellCoordinates()
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

char Board::cellValue(int cellNumber) const
{
    return board[cellNumber];
}

const std::set<int> Board::pickableCells {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 21, 22, 23, 24};

bool Board::isCellPickable(int cellNumber)
{
    return pickableCells.count(cellNumber);
}

void Board::readAndPickCell(char playingSymbol)
{
    int cellNumber = readUserInputOfCellCoordinates();

    while(!( Board::isCellPickable(cellNumber) &&
             (cellValue(cellNumber)==' ' || cellValue(cellNumber) == playingSymbol)))
    {
        std::cout<<"Incorrect cell! Please enter a new one!"<<std::endl;
        cellNumber = readUserInputOfCellCoordinates();

    }

    pickCell(cellNumber);
}

void Board::pickCell(int cellNumber) {
    int topOfColumnCellNumber = cellNumber%5;
    int bottomOfColumnCellNumber = topOfColumnCellNumber + 20;
    int leftmostOfRowCellNumber = cellNumber/5 * 5;
    int rightmostOfRowCellNumber = leftmostOfRowCellNumber + 4;

    pickedCell = cellNumber;
    board[cellNumber] = '*';

    validCellsToPutBack.clear();
    validCellsToPutBack.insert(topOfColumnCellNumber);
    validCellsToPutBack.insert(bottomOfColumnCellNumber);
    validCellsToPutBack.insert(leftmostOfRowCellNumber);
    validCellsToPutBack.insert(rightmostOfRowCellNumber);

    validCellsToPutBack.erase(cellNumber);
}

void Board::readAndPutBack(char pieceSymbol) {
    int x, y, cellNumber;
    std::cout<<"Valid moves to play: "<<std::endl;
    for(auto it = validCellsToPutBack.begin(); it != validCellsToPutBack.end(); ++it)
    {
        y = *it % 5 + 1;
        x = *it / 5 + 1;
        std::cout<<x<<" "<<y<<" "<<std::endl;
    }
    cellNumber = readUserInputOfCellCoordinates();
    while(!validCellsToPutBack.count(cellNumber))
    {
        std::cout<<"Not a playable move!"<<std::endl;
        cellNumber = readUserInputOfCellCoordinates();
    }

    putPieceBack(pieceSymbol, cellNumber);
}

void Board::putPieceBack(char pieceSymbol, int putBackCell)
{
    int step;

    if(putBackCell%5 == pickedCell%5)
    {
        step = putBackCell > pickedCell ? 5 : -5;
    }
    else
    {
        step = putBackCell > pickedCell ? 1 : -1;
    }

    for(int i = pickedCell; i != putBackCell; i+=step)
    {
        board[i] = board[i+step];
    }
    board[putBackCell] = pieceSymbol;
}

bool Board::checkSequence(int startCell, int endCell, int step) const {
    if(board[startCell] == ' ') {
        return false;
    }
    bool result = true;
    for(int j=startCell; j<endCell; j+=step)
    {
        if(board[j] != board[j+step]) {
            result = false;
        }
    }
    return result;
}

char Board::terminalTest() const  //returns N if not terminal, symbol of winer if terminal
{
    if(checkSequence(0, 24, 6)) {
        return board[0];
    }
    if(checkSequence(4, 20, 4)) {
        return board[4];
    }

    for(int i=0; i<5; i++)
    {
        int rowStart = i*5;
        int colStart = i;

        if(checkSequence(rowStart, rowStart+4, 1)) {
            return board[rowStart];
        }

        if(checkSequence(colStart, colStart+20, 5)) {
            return board[colStart];
        }
    }

    return 'N';
}
