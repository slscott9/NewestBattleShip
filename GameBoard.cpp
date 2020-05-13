#include "GameBoard.h"
#include <iostream>
#include <iomanip>
using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard()
{   
    for (int x = 0; x < MAXNUMSHIPS; x++) //sets each ship instance variables 
    {
        Ships[x].setAll(ShipNames[x], ShipAbrev[x], ShipSizes[x]);
    }
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            Board[row][col] = ' ';
        }
    }
}

void GameBoard::displayBoard()
{   
    cout << '\t'; //tabs header number over

    for (int x = 0; x < TENSIZE; x++)
    {
        cout << setw(WIDTH) << headerArray[x]; //prints header numbers 0 - 9
    }
    cout << endl << endl;

//prints side numbers then game board
    for (int row = 0; row < ROWS; row++)
    {   
        cout << setw(WIDTH) << sideArray[row];

        for (int col = 0; col < COLS; col++)
        {
            cout << setw(WIDTH) << Board[row][col];
        }
        cout << endl << endl;
    }
}

//function uses Ships class setCoor function to set a ship and a single coordinate
//use this in a loop in gameboard
bool GameBoard::offBoardPositive(int index, int coor)
{
    if(Ships[index].getShipSize() + coor-1 > 9)
    {
        return true;
    }
    return false;
}


bool GameBoard::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup)
{   
    cout << "                 x coor is " << xCoor << " y coor is " << yCoor << " num ships setup is " << numShipSetup << endl;
    for(int ship = 0; ship < numShipSetup; ship++)
    {
        if(Ships[ship].isHit(xCoor, yCoor))
        {
            return true;
        }
    }
    return false;
}



//new functions

int GameBoard::getShipSize(int index)
{
    return Ships[index].getShipSize();
}

string GameBoard::getShipName(int index)
{
    return Ships[index].getShipName();
}

void GameBoard::setShipCoor(int ship, int xCoor, int yCoor, int index)
{
    Ships[ship].setCoor(xCoor, yCoor, index);

}

int GameBoard::getShipXCoor(int ship, int index)
{
    return Ships[ship].getShipXCoor(index);
}


int GameBoard::getShipYCoor(int ship, int index)
{
    return Ships[ship].getShipYCoor(index);
}


char GameBoard::getShipAbrev(int ship)
{
    return Ships[ship].getShipAbrev();
}

void GameBoard::fillBoard(int xCoor, int yCoor, int ship)
{
    Board[yCoor][xCoor] = getShipAbrev(ship);
}