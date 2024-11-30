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
   
    srand(time(NULL));
    myGM = new GameMechs();
    myF = new Food(myGM);
    myPlayer = new Player(myGM,myF);
    

    // For debugging
    //food1->generateFood(myPlayer->getPlayerPos());
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
    

    // For debugging, generating food with 'o'
    // if(myGM->getInput() == 'o'){
    //     myGM->setInput('\0');
    //     food1->generateFood(myPlayer->getPlayerPos());
    // }
}

void DrawScreen(void)
{
    //IMPLEMENT COPY ASSINGMENT OPERATOR TO MAKE THIS LINE WORK
    
    int i, j, k, snake = 0;
    
    MacUILib_clearScreen();
    //MacUILib_printf("Key pressed: %c", myGM->getInput());
    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // getting player location
    objPos tempObj;

    for (j = 0; j < myGM->getBoardSizeY(); j++)
    {
        MacUILib_printf("\n");
        for (i = 0; i < myGM->getBoardSizeX(); i++)
        {
            for(k = 0; k < playerPosList->getSize(); k++)
            {
                tempObj.setObjPos(playerPosList->getElement(k));

                if(i == tempObj.pos->x && j == tempObj.pos->y)
                {
                    MacUILib_printf("%c", tempObj.symbol);
                    snake = 1;
                    break;
                }
            }

            if(!snake)
            {
                if ( (j==0) || (j==(myGM->getBoardSizeY()-1)) || (i==0) || (i==(myGM->getBoardSizeX()-1))) // Print game board
                {
                    MacUILib_printf("#");
                }
                // else if(i == food1->getFoodPosX() && j == food1->getFoodPosY())
                // {
                //     MacUILib_printf("%c", food1->getFoodSymbol());
                // }
                else    // Print Empty Space
                {
                    MacUILib_printf(" ");
                }
            }
            snake = 0;
        }
    }
    MacUILib_printf("\n");  

    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("You suck Biatch!\n");
        MacUILib_printf("Your score is: %d", myGM->getScore());
    }
    else if(myGM->getExitFlagStatus()){
        MacUILib_printf("You exited the Game!?!?! Why!?!?! Come back! Please! PLEEEEAAAASEEEE!\n");
        MacUILib_printf("Your score is: %d", myGM->getScore());
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{   
    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
