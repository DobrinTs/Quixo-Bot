#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        virtual Board playMove() = 0;

    protected:

    private:
};

#endif // PLAYER_H
