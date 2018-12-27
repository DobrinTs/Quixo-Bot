#ifndef HUMAN_H
#define HUMAN_H

#include <Player.h>


class Human : public Player
{
    public:
        Human(Board board, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~Human();

        Board playMove();
        int readUserInputOfCellCoordinates();

    protected:

    private:
        Board board;
        char humanPlayingSymbol;
        char opponentPlayingSymbol;

        void pickCell();
        void putBackPiece();
};

#endif // HUMAN_H
