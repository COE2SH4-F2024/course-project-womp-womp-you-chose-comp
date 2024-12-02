#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "time.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 70000     // Delay constant Aka game speed

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
    myGM = new GameMechs();
    myF = new Food(myGM);
    myPlayer = new Player(myGM,myF);                            // Spawning First Snake head
    objPosArrayList* initialFood = myPlayer->getPlayerPos();    // Creating the Initial Food
}

void GetInput(void)
{
    myGM->clearInput();
    myGM->collectAsyncInput();      // Collecting User Input
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
    int i, j, k;
    bool snake = false;
    
    MacUILib_clearScreen();
    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // Getting player location
    objPos tempObj;

    for (j = 0; j < myGM->getBoardSizeY(); j++)                 // Iterate through X
    {
        MacUILib_printf("\n");
        for (i = 0; i < myGM->getBoardSizeX(); i++)             // Iterate through Y
        {
            snake = 0;
            for(k = 0; k < playerPosList->getSize(); k++)       // Iterate through Snake
            {
                tempObj.setObjPos(playerPosList->getElement(k));
                if(i == tempObj.pos->x && j == tempObj.pos->y)  // Checking if the Snake exists in each x-y coordinate
                {
                    MacUILib_printf("%c", tempObj.symbol);      // Printing the snake
                    snake = 1;
                    break; 
                }
            
            }
            if(!snake)  // Checking if snake was printed, if yes, skip
            {
                if ( (j==0) || (j==(myGM->getBoardSizeY()-1)) || (i==0) || (i==(myGM->getBoardSizeX()-1))) // Print game board
                {
                    MacUILib_printf("#");
                }
                else if(i == myF->getFoodPosX() && j == myF->getFoodPosY()){    // Print food
                    MacUILib_printf("%c", myF->getFoodSymbol());
                }
                else        // Print Empty Space
                {
                    MacUILib_printf(" ");
                }
            }
        }
    }
    MacUILib_printf("\n");  
    MacUILib_printf("Your score is: %d\n", myGM->getScore());   // Printing player score
    MacUILib_printf("Instructions: Use WASD to control the snake. You can use the escape key to exit the game.\nIf you can find it, there is also a secret button to increase your points!\n");
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("\nUnfortunately you hit yourself! You lost!\n");       // Printing Losing message
    }
    else if(myGM->getExitFlagStatus()){
        MacUILib_printf("\nYou exited the Game!?!?! Why!?!?! Come back! Please! PLEEEEAAAASEEEE!\n");     // Printing Exit message
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // Calling Delay Constant
}


void CleanUp(void)  // Deleting instances from the Heap
{   
    delete myPlayer;
    delete myGM;
    delete myF;
    MacUILib_uninit();
}
