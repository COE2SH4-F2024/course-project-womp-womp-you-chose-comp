#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 1000
#define XSIZE 20
#define YSIZE 10

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
    
    MacUILib_clearScreen();    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
