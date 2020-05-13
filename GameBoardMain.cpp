#include "GameBoard.h"
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Ships.h"

#include <iostream>
using namespace std;

int main()
{   
    
        Player *ptrHuman = new Human;

        Player *ptrComputer = new Computer;

        //ptrHuman->displayBoard();

        //ptrHuman->setShips();


        ptrComputer->setShips();
        ptrComputer->displayBoard();
  
}