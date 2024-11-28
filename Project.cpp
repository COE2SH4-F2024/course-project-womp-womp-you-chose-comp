#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 500000

Player *myPlayer;
GameMechs *myGM;

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
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
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
    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();
    //IMPLEMENT COPY ASSINGMENT OPERATOR TO MAKE THIS LINE WORK
    MacUILib_printf("Player is located at [x,y] = [%d, %d], %c\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    //MacUILib_printf("Key pressed %c", myGM->getInput());

    int i, j;
    for (j = 0; j<myGM->getBoardSizeY(); j++)
    {
        MacUILib_printf("\n");

        for (i = 0; i < myGM->getBoardSizeX(); i++)
        {
            if ( (j==0) || (j==(myGM->getBoardSizeY()-1)) || (i==0) || (i==(myGM->getBoardSizeX()-1)))
            {
                MacUILib_printf("#");
            }
            else if( (i==playerPos.pos->x) && (j==playerPos.pos->y) )
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
    }
    MacUILib_printf("\n");  

    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("You suck Biatch!\n");
        MacUILib_printf("Your score is: %d", myGM->getScore());
    }
    else if(myGM->getExitFlagStatus()){
        MacUILib_printf("You exited the Game, why come back please! PLEEEEAAAASEEEE!\n");
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
