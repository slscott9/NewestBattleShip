#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include "GameBoard.h"

class Computer : public Player
{
    private:
        int Xinput;
        int Yinput;
        bool isVertical;

        GameBoard board;
        

    public:
    //constructors
        Computer();

    //function for Computer class
        int getZeroNine();//generates random 0 - 9 for x and y coor

        bool getIsVert();

        bool setVertical();//generates 1 for vertical or 0 for hoizontal

    //redefined virtual functions
        void setXYVert();

        void setShips();

        int getX();

        int getY();

        bool getIsVertical();

};

#endif 





