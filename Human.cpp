#include "Human.h"
#include <iostream>
using namespace std;

Human::Human()
{
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
}

//function to set Humans input to x and y coordinates

void Human::setXY()
{       
    int xCoor;
    int yCoor;
    char letter;

    cout << "Enter the letter coordinate: ";
    letter = validateLetterInput();

    xCoor = convertLetter(letter); //converts letter to number

    cout << "Enter the number coordinate: ";
    yCoor = validateNumInput();

    Xinput = xCoor;
    Yinput = yCoor;
}

void Human::setShips()
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        cout << "-------------------" << endl;
        for(int coorIndex = 0; coorIndex < Ships[ship].getShipSize(); coorIndex++)
        {
            setXY();
            Ships[ship].setCoor(getX(), getY(), coorIndex);

            int x = Ships[ship].getShipXCoor(coorIndex);
            int y = Ships[ship].getShipYCoor(coorIndex);

            Board.fillBoard(x, y, Ships[ship].getShipAbrev());

            displayBoard();  
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





bool Human::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup)
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


void Human::displayBoard()
{
    Board.showBoard();
}

int Human::validateNumInput()
{
    int coor;
    while(!(cin >> coor) || coor < 0 || coor > 9)
    {
        cout << "Error coordinate must be in the range of 0 - 9" << endl;
        cout << "Enter again: ";
        cin.clear();
        cin.ignore();
    }
    return coor;
}

char Human::validateLetterInput()
{
    char letter;
    while(!(cin >> letter) ||  toupper(letter) > 'J')
    {
        cout << "Error letter must be in range of A - J" << endl;
        cout << "Enter again: ";
        cin.clear();
        cin.ignore();
    }
    return letter;
}

int Human::convertLetter(char letter)
{
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};

    for(int index = 0; index < 10; index++)
    {
        if(toupper(letter) == letters[index])
        {
            return index;
        }
    }
}