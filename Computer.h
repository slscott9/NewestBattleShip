#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include "GameBoard.h"
#include "Ships.h"

class Computer : public Player
{
    private:
        int Xinput;
        int Yinput;
        bool isVertical;

    //aggregate class instances
        GameBoard Board;
        Ship Ships[MAXNUMSHIPS]; //contains each ship

    //arrays to hold ship information
        char ShipAbrev[MAXNUMSHIPS] ={'P','S','D','B','C'};
        std::string ShipNames[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};
        

    public:
    //constructors
        Computer();

    //Native functions for Computer class
        int getZeroNine();//generates random 0 - 9 for x and y coor

        bool getIsVert();

        bool setVertical();//generates 1 for vertical or 0 for hoizontal sets isVertical var

        bool getIsVertical();

    //redefined virtual functions
        void setXY();

        void setShips();

        int getX();

        int getY();

        bool boardIsShipsHit(int, int, int); //redefined virtual function

        void displayBoard();

};

#endif 





