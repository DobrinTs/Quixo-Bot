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
        void pickCell(int cellNumber);
        void putPieceBack(char pieceSymbol, int cellNumber);

        char terminalTest() const;
        bool checkSequence(int startCell, int endCell, int step) const;

        static std::vector<int> generateRandomPickOrder();
        static bool isCellPickable(int cellNumber);

    protected:

    private:
        static const std::set<int> pickableCells;

        std::vector<char> board;

        int pickedCell;
        std::set<int> validCellsToPutBack;

        friend class Bot;
        friend class Human;
};

#endif // BOARD_H
