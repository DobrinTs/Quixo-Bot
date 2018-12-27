#ifndef BOT_H
#define BOT_H
#include <vector>

#include "Board.h"

class Bot
{
    public:
        Bot(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~Bot();

        int maxValue(const Board& board, int alpha, int beta, int depth);
        int minValue(const Board& board, int alpha, int beta, int depth);
        Board minMaxDecision();

    protected:

    private:
        static int MIN_INF;
        static int PLUS_INF;
        static int MAXIMUM_DEPTH;
        static std::vector<int> cellWorth;

        Board startingBoard;
        char botPlayingSymbol;
        char opponentPlayingSymbol;

        int eval(const Board& board);
};

#endif // BOT_H
