#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Player::Player()
{
    srand((unsigned) time(0));
}

//function to set players input to x and y coordinates

void Player::setXYinput()
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

//function to get randomly generated computer numbers and set them to x and y coordinates
void Player::setCompXY()
{   

    Xinput = getZeroNine();

    Yinput = getZeroNine();
}

int Player::returnX()
{
    return Xinput;
}

int Player ::returnY()
{
    return Yinput;
}

//function for the computer player

bool Player::getIsVert()
{
    return isVertical;
}

int Player::getZeroNine()
{   
    //srand((unsigned) time(0));

    //srand(time(NULL));
    //int randomNumber = rand() % 10;
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
    
}


bool Player::setVertical()
{
    //either 0 or 1
    //srand(time(NULL));
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
