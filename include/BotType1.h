#ifndef BOTTYPE1_H
#define BOTTYPE1_H

#include <BotMinMax.h>


class BotType1 : public virtual BotMinMax
{
    public:
        BotType1(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotType1();

    protected:
        int eval(const Board& board);
    private:
        static std::vector<int> cellWorth;
};

#endif // BOTTYPE1_H
