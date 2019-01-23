#include<vector>
#include<iostream>
#include <algorithm>

#include "Board.h"

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

char Board::cellValue(int cellNumber) const
{
    return board[cellNumber];
}

const std::set<int> Board::pickableCells {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 21, 22, 23, 24};

bool Board::isCellPickable(int cellNumber)
{
    return pickableCells.count(cellNumber);
}

std::vector<int> Board::generateRandomPickOrder() {
    std::vector<int> order(pickableCells.begin(), pickableCells.end());
    std::random_shuffle ( order.begin(), order.end() );

    return order;
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

void Board::putPieceBack(char pieceSymbol, int putBackCell)
{
    int step;

    if(putBackCell%5 == pickedCell%5) //same column
    {
        step = putBackCell > pickedCell ? 5 : -5;
    }
    else
    {
        step = putBackCell > pickedCell ? 1 : -1; //same row
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
    if(checkSequence(0, 24, 6)) { //main diagonal
        return board[0];
    }
    if(checkSequence(4, 20, 4)) { //secondary diagonal
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
