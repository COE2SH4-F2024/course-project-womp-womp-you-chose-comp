#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 1000
#define XSIZE 20
#define YSIZE 10

Player *myPlayer;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    myPlayer = new Player(nullptr);

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();
    //IMPLEMENT COPY ASSINGMENT OPERATOR TO MAKE THIS LINE WORK
    MacUILib_printf("Player is located at [x,y] = [%d, %d, %c]", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);


    objPos a = objPos(9,3,'@');
    
    int i, j;
    for (j = 0; j<YSIZE; j++)
    {
        MacUILib_printf("\n");

        for (i = 0; i < XSIZE; i++)
        {
            if ( (j==0) || (j==(YSIZE-1)) || (i==0) || (i==(XSIZE-1)))
            {
                MacUILib_printf("#");
            }
            else if( (i==a.pos->x) && (j==a.pos->y) )
            {
                MacUILib_printf("%c", a.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
    }
    
       
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;

    MacUILib_uninit();
}
