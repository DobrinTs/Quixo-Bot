#ifndef BOTTYPE2_H
#define BOTTYPE2_H

#include <BotMinMax.h>


class BotType2 : public virtual BotMinMax
{
    public:
        BotType2(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotType2();

    protected:
        int eval(const Board& board);

    private:
        int checkSymbolAndChangeGoodness(char cellValue, int& boardGoodness, int addedGoodness);
        void checkForThreesAndFours(const Board& board, int& boardGoodness, int start, int end, int step);
};

#endif // BOTTYPE2_H
