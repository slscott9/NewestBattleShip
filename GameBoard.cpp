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

//function to fill the board with ship positions



//function to set all of player one's ships coordinates
void GameBoard::setP1ships()
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        cout << "-------------------" << endl;
        for(int coorIndex = 0; coorIndex < Ships[ship].getShipSize(); coorIndex++)
        {
            player.setXYinput();
            Ships[ship].setCoor(player.returnX(), player.returnY(), coorIndex);

            int x = Ships[ship].getShipXCoor(coorIndex);
            int y = Ships[ship].getShipYCoor(coorIndex);

            Board[y][x] = Ships[ship].getShipAbrev();
            displayBoard();  
        }
    }
}

void GameBoard::setCompShips()
{   
    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    xDir Xdirection = RIGHT;
    yDir Ydirection = DOWN;

    int shipsSetup = 0;

    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        bool good = true;
        do
        {   
            good = true;

            Computer.setCompXY(); //x and y randomly chosen
            Computer.setVertical(); //verticle is chosen 0 for horizontal 1 for vertical

            if(Computer.getIsVert())
            {   
                 Xdirection = XNOCHANGE;
                if((Computer.returnY() + Ships[ship].getShipSize()-1) > 9)
                {   
                     Ydirection = UP;
                }
                else
                {
                    Ydirection = DOWN;
                }
                
            }
            else
            {   
                 Ydirection = YNOCHANGE;
                if((Computer.returnX() + Ships[ship].getShipSize() - 1) > 9)
                {   
                     Xdirection = LEFT;
                }
                else
                {
                    Xdirection = RIGHT;
                }
                
            }//end if vertical

            int x = Computer.returnX();
            int y = Computer.returnY();

            for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
            {   
                if(boardIsShipsHit(x,y,shipsSetup))
                {
                    good = false;
                    cout << "         In nested for loop if statement for is a hit" << endl;
                    break;
                }
                else
                {   
                     y+=Ydirection;
                     x+=Xdirection;
                }
                
            }//end nested for
            
            if(good)
            {   
                x = Computer.returnX();
                y = Computer.returnY();
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Ships[ship].setCoor(x,y,coor);
                    Board[y][x] = Ships[ship].getShipAbrev();
                   
                    y+=Ydirection;
                    x+=Xdirection;
                }
            }
            //cin.get();

        } while (!good);

        shipsSetup++;

        
    }//end first for

}//end of function




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
