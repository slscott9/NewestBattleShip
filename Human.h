#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "GameBoard.h"
#include "Ships.h"

class Human : public Player
{
    private:
        int Xinput;
        int Yinput;

    //aggregate classes
        GameBoard Board;
        Ship Ships[MAXNUMSHIPS]; //contains each ship

    //arrays containing ship info
        char ShipAbrev[MAXNUMSHIPS] ={'P','S','D','B','C'};
        std::string ShipNames[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};

    
    public:
    //constructor 
        Human();
    

    //redefined virtual set functions
        void setXY();
        void setShips();

        int getX();
        int getY();

        bool boardIsShipsHit(int, int, int);


    //display function
        void displayBoard();


    //validation functions
        int validateNumInput();
        char validateLetterInput();

    //converts letter to number for x coordinates
        int convertLetter(char);


};

#endif 

