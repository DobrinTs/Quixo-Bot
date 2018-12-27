#ifndef HUMAN_H
#define HUMAN_H

#include <Player.h>


class Human : public Player
{
    public:
        Human(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~Human();

        Board playMove();

    protected:

    private:
        Board startingBoard;
        char humanPlayingSymbol;
        char opponentPlayingSymbol;
};

#endif // HUMAN_H
