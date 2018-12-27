#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<set>

class Board
{
    public:
        Board();
        virtual ~Board();

        void print() const;
        char cellValue(int cellNumber) const;
        int readUserInputOfCellCoordinates();
        static bool isCellPickable(int cellNumber);
        void readAndPickCell(char playerSymbol);
        void pickCell(int cellNumber);
        void readAndPutBack(char pieceSymbol);
        void putPieceBack(char pieceSymbol, int cellNumber);

        char terminalTest() const;
        bool checkSequence(int startCell, int endCell, int step) const;

    protected:

    private:
        static const std::set<int> pickableCells;

        std::vector<char> board;

        int pickedCell;
        std::set<int> validCellsToPutBack;

        friend class Bot;
};

#endif // BOARD_H
