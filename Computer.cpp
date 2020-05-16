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
            MarkedBoard.fillBoard(col, row, ' ');
        }
    }
        shipInArea = false;
        GameStarted = false;
        Xinput = 0;
        Yinput = 0;
        isVertical = false;
        shipInArea = false;
        hitCount = 0;
        missCount = 0;


    //variables to hold the original x and y hit
        int XhitCoor = 0;
        int YhitCoor = 0;
}

//functions native to computer class
/****************************************************/
int Computer::getZeroNine()
{   
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
}

bool Computer::getIsVertical()
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
/****************************************************/



//redefined virtual functions from Player base class
/***************************************************/
void Computer::setXY()
{   
    if(shipInArea)
    {   
        cout << "in SHIPINAREA if" << endl;
        smartChoice();
    }
    else
    {
        Xinput = getZeroNine();
        Yinput = getZeroNine(); 
        while(checkMarkedBoard(Xinput, Yinput))
        {
            Xinput = getZeroNine();
            Yinput = getZeroNine();
        }
           
    }
}


int Computer::getX()
{
    return Xinput;
}

int Computer::getY()
{
    return Yinput;
}



bool Computer::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup) //used to set up ships
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
            //MarkedBoard.fillBoard(xCoor, yCoor, 'H');
            return true;
        }
    }
    return false;
}

void Computer::displayBoard()
{   
    cout << "GAMEBOARD" << endl;
    Board.showBoard();
    cout << endl << "MARKED BOARD " << endl;
    MarkedBoard.showBoard();
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
        int total = 0;
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            if(Ships[ship].getIsSunk())
            {
                total++;
            }
        }
        if(total == 5)
        {   
            cout << "YOU WON!!" << endl;
            return true;
        }
        return false;

    }//end for loop
}
/*************************************************************************/ //end virtual funcs


void Computer::FillASpot(int x, int y, char shot)
{   
    if(shot == 'H')
    {
        MarkedBoard.fillBoard(x, y, 'H');

    }
    else
    {
        MarkedBoard.fillBoard(x, y, 'O');
    }
    
}

void Computer::showShipCoor()
{
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
        {
            cout << "X coor " << Ships[ship].getShipXCoor(coor) << endl;
            cout << "Ycoor " << Ships[ship].getShipYCoor(coor) << endl;
        }
        cout << endl;
    }
}

/******************* SMART CHOICE FUNCTION NATIVE *******************/

void Computer::smartChoice()
{   
    //if in this function then a ship has been hit and shipinarea is true

    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    int x = getXhitCoor(); //getting the original hit cooordinates ever time
    int y = getYhitCoor();

    if (getMissCount() == 0) //x goes right
    {   
        setShipVertical(false);
        cout << "in misscount = 0" << endl;
        Xinput = x+=1;
        Yinput = y;
        

    }
    else if(getMissCount() == 1) //x goes left
    {   
        cout << "in misscount = 1" << endl;
        setShipVertical(false);
        Xinput = x-=1;
        Yinput = y;

        if(checkMarkedBoard(Xinput, Yinput) && !(getShipVertical()))
        {
            Xinput-=1;
            Yinput = y;
        }
    }
    else if(getMissCount() == 2) //y goes down
    {   
        cout << "in misscount = 2" << endl;
        setShipVertical(true);
        Xinput = x;
        Yinput = y+=1;

        if(checkMarkedBoard(Xinput, Yinput) && getShipVertical())
        {
            Xinput = x;
            Yinput += 1;
        }
    }
    else if(getMissCount() == 3) // y goes up
    {   
        cout << "in misscount = 3" << endl;
        setShipVertical(true);
        Xinput = x;
        Yinput = y-=1;

        if(checkMarkedBoard(Xinput, Yinput) && getShipVertical())
        {
            Xinput = x;
            Yinput -=1;
            
        }
    }
    else if (getMissCount() > 3) //everything reset
    {   
        
        shipInArea = false;
        setMissCount(0);
        setHitCount(0);
        XhitCoor = 0;
        YhitCoor = 0;
    }
}


void Computer::setShipVertical(bool vertical)
{
    if(vertical)
    {
        isShipVertical = true;
    }
    else
    {
        isShipVertical = false;
    }
    
}

bool Computer::getShipVertical()
{
    return isShipVertical;
}
//function checks for computer if his chosen shot is filled with a hit or miss
bool Computer::checkMarkedBoard(int x, int y) //checks marked board for a shot or hit
{
    if(MarkedBoard.isXYfilled(x, y))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Computer::setMissCount(int misses)
{
    missCount = misses;
}

int Computer::getMissCount()
{
    return missCount;
}


void Computer::setXhitCoor(int xCoor)
{
    XhitCoor = xCoor;
}

void Computer::setYhitCoor(int yCoor)
{
    YhitCoor = yCoor;
}

int Computer::getXhitCoor()
{
    return XhitCoor;
}

int Computer::getYhitCoor()
{
    return YhitCoor;
}

void Computer::setHitCount(int tempHitCount)
{
   
    hitCount+= tempHitCount;

}

int Computer::getHitCount()
{
    return hitCount;
}


bool Computer::setShipInArea()
{
      shipInArea = true;
}


bool Computer::getShipInArea()
{   
    return shipInArea;
}
