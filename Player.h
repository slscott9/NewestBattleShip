#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        virtual void setXY() = 0;
        virtual void setShips() = 0;
        virtual int getX();
        virtual int getY();
        virtual bool getIsVertical();
};

#endif