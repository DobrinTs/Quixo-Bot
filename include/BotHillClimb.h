#ifndef BOTHILLCLIMB_H
#define BOTHILLCLIMB_H

#include <Player.h>


class BotHillClimb : public Player
{
    public:
        BotHillClimb(Board startingBoard, char botPlayingSymbol, char opponentPlayingSymbol);
        virtual ~BotHillClimb();

        Board playMove();
    protected:

    private:
        Board board;
        char botPlayingSymbol;
        char opponentPlayingSymbol;

        Board hillClimbDecision();
        static std::vector<int> cellWorth;
        int eval(const Board& board);
};

#endif // BOTHILLCLIMB_H
