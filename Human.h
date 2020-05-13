#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "GameBoard.h"

class Human : Player
{
    private:
        int Xinput;
        int Yinput;
        GameBoard Board;
    
    public:
    //constructor 
        Human();
    //setters
        void setXY();
        void setShips();

    //getters
        int getX();
        int getY();


};

#endif 

