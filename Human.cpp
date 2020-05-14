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

    GameStarted = false;
}

//function to setup player's name
void Human::setPlayerName(std::string tempName)
{
    playerName = tempName;
}

std::string Human::getPlayerName()
{
    return playerName;
}


void Human::setXY() //redefined virtual of base abstract class Player
{       
    int xCoor;
    int yCoor;
    char templetter;

    cout << "Enter an alphabetic coordinate: ";
    templetter = validateLetterInput();

    xCoor = convertLetter(templetter); //converts letter to number

    cout << "Enter a numeric coordinate: ";
    yCoor = validateNumInput();
    cout << endl << endl;

    Xinput = xCoor;
    Yinput = yCoor;
    letter = templetter;
}

void Human::setShips()//redefined virtual of base abstract class Player
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
    GameStarted = true; //after this function is done the game is ready to start
}


int Human::getX()//redefined virtual of base abstract class Player
{
    return Xinput;
}

int Human ::getY()//redefined virtual of base abstract class Player
{
    return Yinput;
}

char Human::getLetter()
{
    return letter;
}



bool Human::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup)//redefined virtual of base abstract class Player
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

bool Human::boardIsShipsHit(int xCoor, int yCoor)//redefined virtual and overloaded
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


void Human::displayBoard() //redefined virtual of base abstract class Player
{
    Board.showBoard();
}


//validation functions

int Human::validateNumInput() //validation function
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

char Human::validateLetterInput()//validation function
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


//converts a letter to a number
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


void Human::setHitMarker(int x, int y, bool hit)
{   
    if(hit)
    {
        Board.fillBoard(x, y, 'X');

    }
    else
    {
        Board.fillBoard(x, y, 'O');
    }
    
}



