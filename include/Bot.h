#ifndef BOT_H
#define BOT_H
#include <vector>

#include "Board.h"

class Bot
{
    public:
        Bot(Board board, char botPlayingSymbol, char playerPlayingSymbol);
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

        Board currentBoard;
        char botPlayingSymbol;
        char playerPlayingSymbol;

        int eval(const Board& board);
};

#endif // BOT_H
