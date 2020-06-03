#include "GameBoard.h"
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Ships.h"
#include <iostream>
using namespace std;
void DisplayComputer();
void DisplayUserPrompt(string);
void CompSetupPrompt();

int main()
{   
        string name;

        Player *ptrPlayer, *ptrComputer;

        Human PlayerOne;
        Computer Comp;

        ptrPlayer = &PlayerOne;
        ptrComputer = &Comp;


        cout << setw(16) << "BATTLESHIP" << endl;
        cout << setw(16) <<  "******************************" << endl;
        cout << "SHIP TYPES " << endl << endl;
                cout << "-----------------" << endl;

        cout << setw(10) << "Carrier " << endl;
        cout << "Size: " << 5 << endl;
        cout << "Board abreviation: C " << endl << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Battle ship " << endl;
        cout << "Size: 4" << endl;
        cout << "Board abreviation: B" << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Destroyer " << endl;
        cout << "Size: 3" << endl;
        cout << "Board abreviation: D" << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Submarine " << endl;
        cout << "Size: 3" << endl;
        cout << "Board abreviation: S" << endl;
                cout << "-----------------" << endl;

        cout << setw(10) << "Patrol Boat " << endl;
        cout << "Size: 2" << endl;
        cout << "Board abreviation: P" << endl << endl;
                cout << "-----------------" << endl;



        cout << "Player one enter your name: ";
        getline(cin,name);

        PlayerOne.setPlayerName(name);

        
//sets up players ships and computer ships
        ptrPlayer->displayBoard();

        cout << endl << endl << "You will be asked to enter each ships coordinates on the board ";
        cout << endl << "Press enter key to begin: ";
        cin.get();
        cout << endl << endl;

        ptrPlayer->setShips();

        CompSetupPrompt(); // computer will not setup ship enter to continue

        ptrComputer->setShips();

        cout << endl;
        cout << "*COMPUTER SHIPS SET*" << endl;
        cout << "**READY FOR WAR** " << endl;
        cout << "-----------------------------------------------------------------------------------" << endl << endl;

        cout << "The computer will shoot first, if its shot is a hit, your ship will be marked with an H" << endl;
        cout << "Your hits on the computer's ships will be marked as an X." << endl;
        cout << "Your misses will be marked as an O" << endl << endl;

        cout << "Press enter to begin: ";
        cin.get();

        bool gameOver = false;
        int misses = 0;
        bool hit;
       //START OF GAME*******
        do
        {       
                int hitCount = 0;

                DisplayComputer(); //"computer is picking spots press enter to continue"

                
        /*this function sets the computer's x and y coordinates*/
                ptrComputer->setXY();

                //cout << "Computer chose Xinput " << ptrComputer->getX() << " Yinput " << ptrComputer->getY() << endl;



        /**********************************************************************************************************************/
                /*starts if statements to check if COMPUTER HIT computer 2's ship*/

                if(ptrPlayer->boardIsShipsHit(ptrComputer->getX(), ptrComputer->getY()))
                {       
                        ptrPlayer->displayBoard();
                        cout << endl;
                        cout << "COMPUTER HIT YOUR SHIP " << PlayerOne.convertNum(ptrComputer->getX()) << ", " << ptrComputer->getY() << endl;
                        Comp.FillASpot(ptrComputer->getX(), ptrComputer->getY(), 'H'); //fills computers board with hit shot
                        PlayerOne.setHitMarker(ptrComputer->getX(), ptrComputer->getY(), 'H');



                        hitCount++;
                        Comp.setHitCount(hitCount);
                        Comp.setShipInArea(); // ship in area is true
                        Comp.setXhitCoor(ptrComputer->getX());
                        Comp.setYhitCoor(ptrComputer->getY());
                        if(ptrComputer->isWinner())
                        {
                                cout << "THE COMPUTER WON";
                                exit;
                        }

                }
                else
                {       
                        Comp.FillASpot(ptrComputer->getX(), ptrComputer->getY(), 'O'); //fills computers board with missed shot

                        if(Comp.getShipInArea())
                        {
                                misses++;
                                Comp.setMissCount(misses);
                        }

                        cout << " COMPUTER SHOT MISSED" << endl;

                }
                if(Comp.getMissCount() == 4)
                {
                        misses = 0;
                        hitCount = 0;
                }
        /**************************************************************************************************************/


                cout << endl;


                //displays coordinates set press enter to continue
                        DisplayUserPrompt(name);

                ptrPlayer->displayBoard();

                
                ptrPlayer->setXY();


                
                cout << "Coordinates set press enter to fire: ";
                cin.get();

                if(ptrComputer->boardIsShipsHit(ptrPlayer->getX(), ptrPlayer->getY()))
                {       
                        hit = true;
                        PlayerOne.setHitMarker(ptrPlayer->getX(), ptrPlayer->getY(), 'X');
                        ptrPlayer->displayBoard();

                        cout << endl << "COMPUTER SHIP HIT: " << PlayerOne.getLetter() << ", " << ptrPlayer->getY() << endl;

                        cout << "A hit marker X, has been placed on your board" << endl;
                        if(ptrPlayer->isWinner())
                        {
                                cout << "YOU WON!!";
                                
                                exit;
                        }

                }
                else
                {       
                        hit = false;
                        PlayerOne.setHitMarker(ptrPlayer->getX(), ptrPlayer->getY(), 'O');
                        ptrPlayer->displayBoard();

                        cout << endl << "YOUR SHOT MISSED." << endl;
                        cout << "A miss marker O has been set on your board." << endl;

                }

                
        } while (!gameOver);
        
  
}

void DisplayComputer()
{
        cout << "Computer is picking coordinates" << endl << endl;
                cout << "Computer has fired shot" << endl;
                cout << "Press enter to continue: ";
                cin.get();
                cout << endl;
}

void DisplayUserPrompt(string name)
{
        cout << endl << endl<< name <<  " prepare to select coordinates to fire on." << endl;

                cout << "Press any key to continue: ";
                cin.get();
                cout << endl << "--------------------" << endl;
}

void CompSetupPrompt()
{
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "The computer will now set it's ships, press enter to continue: " << endl;
        cin.get();
}
