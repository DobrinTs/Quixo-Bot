#ifndef BOT_H
#define BOT_H
#include <vector>

#include "Board.h"
#include "Player.h"

class BotMinMax : public Player
{
    public:
        BotMinMax(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotMinMax();

        Board playMove();

    protected:
        static int MIN_INF;
        static int PLUS_INF;
        static int MAXIMUM_DEPTH;

        Board startingBoard;
        char botPlayingSymbol;
        char opponentPlayingSymbol;

        Board minMaxDecision();
        int maxValue(const Board& board, int alpha, int beta, int depth);
        int minValue(const Board& board, int alpha, int beta, int depth);
        virtual int eval(const Board& board) = 0;
    private:
};

#endif // BOT_H
