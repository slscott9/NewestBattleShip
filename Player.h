#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    private:
        int Xinput;
        int Yinput;
        bool isVertical;
        

    public:
    //constructor 
        Player();
        //setters
            void setXYinput();
            void setCompXY();

        //getters
            int returnX();
            int returnY();

        //function for the computer player
                //getters
                    int getZeroNine();//generates random 0 - 9 for x and y coord
                    bool getIsVert();

                    bool setVertical();//generates 1 for vertical or 0 for hoizontal

};

#endif 

//jjjjjjjjjkkkkk