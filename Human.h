#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "GameBoard.h"
#include "Ships.h"
#include <string>

class Human : public Player
{
    private:
        std::string playerName;
        bool GameStarted; //will be set to false in constructor
        int Xinput,Yinput;
        char letter;

    //aggregate classes
        GameBoard Board,MarkedBoard;
        Ship Ships[MAXNUMSHIPS]; //contains each ship

    //arrays containing ship info
        char ShipAbrev[MAXNUMSHIPS] ={'P','S','D','B','C'};
        std::string ShipNames[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};

    
    public:
    //constructor 
        Human();
    
        void setPlayerName(std::string);
        std::string getPlayerName();
    //redefined virtual set functions

        void setXY(); //virtual function
        void setShips(); //virtual function

        int getX(); //virtual function
        int getY(); //virtual function
        char getLetter();

        bool boardIsShipsHit(int, int, int);//virtual function
        bool boardIsShipsHit(int, int); //virtual overloaded from player

        void displayBoard(); //virtual function


    //validation functions
        int validateNumInput();
        char validateLetterInput();

    //converts letter to number for x coordinates
        int convertLetter(char);
        char convertNum(int);


    //if players shot is a hit on the computer's board this function fill the players
    //board with a hit to show him where he hit on the computers board.
        void setHitMarker(int, int, char);

    //virtual function to check for winner
        bool isWinner();




};

#endif 

