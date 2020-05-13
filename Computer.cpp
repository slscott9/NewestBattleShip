#include "Computer.h"
#include <iostream>
using namespace std;


//constructor
Computer::Computer()
{
    Xinput = 0;
    Yinput = 0;
    
}


//functions native to computer class
int Computer::getZeroNine()
{   
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
}

bool Computer::getIsVert()
{
    return isVertical;
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


void Computer::setXYVert()
{
    Xinput = getZeroNine();
    Yinput = getZeroNine();
    setVertical();
}

int Computer::getX()
{
    return Xinput;
}

int Computer::getY()
{
    return Yinput
}

bool Computer::getIsVertical()
{
    return isVertical;
}




void Computer::setShips()
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

            setXY(); //sets X, Y, and Vertical

            if(getIsVertical())
            {   
                 Xdirection = XNOCHANGE;
                if((getX() + board.getShipSize(ship)-1) > 9)
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

                if((getY() + board.getShipSize(ship)-1) > 9)
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

            for(int coor = 0; coor < board.getShipSize(ship); coor++)
            {   
                if(boardIsShipsHit(x,y,shipsSetup))//THIS IS WHERE YOU STOPPEDDD
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
}