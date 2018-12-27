#ifndef BOTTYPE3_H
#define BOTTYPE3_H

#include <BotType1.h>
#include <BotType2.h>


class BotType3 : public BotType1, public BotType2
{
    public:
        BotType3(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotType3();

    protected:

    private:
        int eval(const Board& board);

};

#endif // BOTTYPE3_H
