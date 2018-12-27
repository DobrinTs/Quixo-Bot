#ifndef BOTTYPE2_H
#define BOTTYPE2_H

#include <Bot.h>


class BotType2 : public Bot
{
    public:
        BotType2(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotType2();

    protected:

    private:
        int eval(const Board& board);

};

#endif // BOTTYPE2_H
