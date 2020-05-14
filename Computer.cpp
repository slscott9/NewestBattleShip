#include "Computer.h"
#include <iostream>
using namespace std;


//constructor
Computer::Computer()
{   
    srand((unsigned) time(0));

   for (int x = 0; x < MAXNUMSHIPS; x++) //sets each ship instance variables 
    {
        Ships[x].setAll(ShipNames[x], ShipAbrev[x], ShipSizes[x]);
    }
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            Board.fillBoard(col, row, ' ');
        }
    }

    GameStarted = false;
}


//functions native to computer class

int Computer::getZeroNine()
{   
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
}




bool Computer::setVertical()
{
    int rand0or1 =  rand() % 2;

    if(rand0or1 == 1)
    {
        isVertical = true;
    }
    else
    {
        isVertical = false;
    }
    
}

bool Computer::getIsVertical()
{
    return isVertical;
}




//redefined virtual functions from Player base class

void Computer::setXY()
{
    Xinput = getZeroNine();
    Yinput = getZeroNine();
}

int Computer::getX()
{
    return Xinput;
}

int Computer::getY()
{
    return Yinput;
}



bool Computer::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup)
{   
    for(int ship = 0; ship < numShipSetup; ship++)
    {
        if(Ships[ship].isHit(xCoor, yCoor, GameStarted))
        {
            return true;
        }
    }
    return false;
}

bool Computer::boardIsShipsHit(int xCoor, int yCoor)//redefined virtual and overloaded
{   
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {
        if(Ships[ship].isHit(xCoor, yCoor, GameStarted))
        {   
            Board.fillBoard(xCoor, yCoor, 'H');
            return true;
        }
    }
    return false;
}





void Computer::displayBoard()
{
    Board.showBoard();
}

void Computer::setShips()
{   
    
    //enum class will tell the  direction we should go
    //based on isVertical.
    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    xDir Xdirection = RIGHT; //defaults
    yDir Ydirection = DOWN;

    int shipsSetup = 0;

    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        bool good = true;
        do
        {   
            good = true;

            setXY(); //sets X, Y, and Vertical
            setVertical();

            if(getIsVertical())
            {   
                 Xdirection = XNOCHANGE;
                if((getY() + Ships[ship].getShipSize()-1) > 9)
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

                if((getX() + Ships[ship].getShipSize()-1) > 9)
                {   
                     Xdirection = LEFT;
                }
                else
                {
                    Xdirection = RIGHT;
                }
                
            }//end if vertical

            int x = getX();
            int y = getY();

            for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
            {   
                if(boardIsShipsHit(x,y,shipsSetup))//THIS IS WHERE YOU STOPPEDDD
                {
                    good = false;
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
                x = getX();
                y = getY();
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Ships[ship].setCoor(x,y,coor);
                    Board.fillBoard(x,y, Ships[ship].getShipAbrev());
                   
                    y+=Ydirection;
                    x+=Xdirection;
                }
            }

        } while (!good);

        shipsSetup++;
            

    }//end ship for loop

    GameStarted = true; //When this function is done the ships will be set
                        //and game is ready to start
}



bool Computer::isWinner()
{   
    cout << "Computer's hits " << endl;
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << "hit count is " <<  Ships[ship].getHitCount() << endl;
         cout << Ships[ship].getShipName() <<  "is sunk is "  << Ships[ship].getIsSunk() << endl;;

    }
}