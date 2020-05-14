#include <iostream>
using namespace std;

int main()
{   

    bool locatedHit = false;
    bool xLeft = false, xRight = false, yUp = false, yDown = false;

    int Xinput, Yinput;

    int XhitCoor = 5, YhitCoor = 5;

    int loopCount = 0;
    int hitCount = 0;

    bool good = true;

    do
    {   
        
        if (!locatedHit)//if true we have not going in the right direction
        {
            
            if(loopCount == 1)
            {
                xRight = false;
            }
            else if(loopCount == 2)
            {
                xLeft = false;
            }
            else if(loopCount == 3)
            {
                yDown = false;
            }
            else if(loopCount == 4)
            {
                yUp = false;
            }
            
            if(xRight && xLeft && yUp && yDown)
            {
                Xinput = XhitCoor++; //x goes right
                Yinput = YhitCoor;
                loopCount++;
            }
            else if(!xRight)
            {
                Xinput = XhitCoor--;// x goes left
                Yinput = YhitCoor;
            }
            else if(!xRight && !xLeft)
            {
                Xinput = XhitCoor;
                Yinput = YhitCoor++; // y goes down
            }
            else if(!xRight && !xLeft && !yDown)
            {
                Xinput = XhitCoor;
                Yinput = YhitCoor--; // y goes up
            }
        }
    

    else if (locatedHit) //if true we are going in the right direction
    {   
        if(loopCount == 1)
        {
            Xinput = XhitCoor++; //x goes right
            Yinput = YhitCoor;
        }
        else if(loopCount == 2)
        {
            Xinput = XhitCoor--; //x goes left
            Yinput = YhitCoor;
        }
        else if(loopCount == 3)
        {
            Xinput = XhitCoor;// y goes up
            Yinput = YhitCoor--;
        }
        else if(loopCount == 4)
        {
            Xinput = XhitCoor;
            Yinput = YhitCoor++; // y goes down
        }
    } //end else if locatedHit


} while (good);
    

    