#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "time.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;
GameMechs *myGM;
Food *myF;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
   
    //srand(time(NULL));
    myGM = new GameMechs();
    myF = new Food(myGM);
    myPlayer = new Player(myGM,myF);
    objPosArrayList* initialFood = myPlayer->getPlayerPos();
    //myF->generateFood(*initialFood);
}

void GetInput(void)
{
    myGM->clearInput();
    myGM->collectAsyncInput();
}

void RunLogic(void)
{
    if(myGM->getInput() != '\0'){
        myPlayer->updatePlayerDir();
    }
    myPlayer->movePlayer();
    
}

void DrawScreen(void)
{
    //IMPLEMENT COPY ASSINGMENT OPERATOR TO MAKE THIS LINE WORK
    
    int i, j, k;
    bool snake = false;
    
    MacUILib_clearScreen();
    //MacUILib_printf("Key pressed: %c", myGM->getInput());
    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // getting player location
    objPos tempObj;
    objPos BoardObj;
    objPos FoodLoc;

    for (j = 0; j < myGM->getBoardSizeY(); j++)
    {
        MacUILib_printf("\n");
        for (i = 0; i < myGM->getBoardSizeX(); i++)
        {
            snake = 0;
            for(k = 0; k < playerPosList->getSize(); k++)
            {
                //cout<<playerPosList->getSize()<<endl;
                tempObj.setObjPos(playerPosList->getElement(k));

                //cout<<tempObj.pos->x<<endl;

                if(i == tempObj.pos->x && j == tempObj.pos->y)
                {
                    MacUILib_printf("%c", tempObj.symbol);
                    snake = 1;
                }
            
            }
            if(!snake)
            {
                // BoardObj.setObjPos(i,j);
                // FoodLoc.getObjPos();
                if ( (j==0) || (j==(myGM->getBoardSizeY()-1)) || (i==0) || (i==(myGM->getBoardSizeX()-1))) // Print game board
                {
                    MacUILib_printf("#");
                }
                // else if(BoardObj.isPosEqual(&FoodLoc)){
                //     MacUILib_printf("%c", myF->getFoodSymbol());
                // }
                else if(i == myF->getFoodPosX() && j == myF->getFoodPosY()){
                    MacUILib_printf("%c", myF->getFoodSymbol());
                }
                else    // Print Empty Space
                {
                    MacUILib_printf(" ");
                }
            }
        }
    }
    MacUILib_printf("\n");  
    MacUILib_printf("Your score is: %d\n", myGM->getScore());
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("Hi Scott!! You lost! Sorry!\n");
    }
    else if(myGM->getExitFlagStatus()){
        MacUILib_printf("You exited the Game!?!?! Why!?!?! Come back! Please! PLEEEEAAAASEEEE!\n");
    }

    //MacUILib_printf("Here!\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{   
    
    delete myPlayer;
        MacUILib_printf("Here!\n");


    delete myGM;

    MacUILib_uninit();
}
