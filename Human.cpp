#include "Human.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Human::Human()
{
    setXY();
}

//function to set Humans input to x and y coordinates

void Human::setXY()
{       
    int xCoor;
    int yCoor;

    cout << "Enter the x coordinate: ";
    cin >> xCoor;
    cout << "Enter the y coordinate: ";
    cin >> yCoor;

    Xinput = xCoor;
    Yinput = yCoor;
}

void Human::setShips()
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Board.getShipName(ship) << endl;
        cout << "-------------------" << endl;
        for(int coorIndex = 0; coorIndex < Board.getShipSize(ship); coorIndex++)
        {
            setXY();
            Board.setShipCoor(ship, getX(), getY(), coorIndex);

            int x = Board.getShipXCoor(ship, coorIndex);
            int y = Board.getShipYCoor(ship, coorIndex);

            Board.fillBoard(x, y, ship);

            Board.displayBoard();  
        }
    }
}


int Human::getX()
{
    return Xinput;
}

int Human ::getY()
{
    return Yinput;
}


