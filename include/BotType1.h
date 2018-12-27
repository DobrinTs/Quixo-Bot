#ifndef BOTTYPE1_H
#define BOTTYPE1_H

#include <Bot.h>


class BotType1 : public Bot
{
    public:
        BotType1(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotType1();

    protected:

    private:
        static std::vector<int> cellWorth;
        int eval(const Board& board);

};

#endif // BOTTYPE1_H
