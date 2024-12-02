#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs *thisGMref)    // specific constructor
{
    mainGameMechsRef = thisGMref;
    foodPos = new objPos(5,6,'@');  // setting default position and symbol of first food
}

Food::~Food()       // destructor
{
    delete foodPos; // not an array no []
}

void Food::generateFood(const objPosArrayList& blockoff)    // generates food with positions of all snake elements
{
    srand(time(NULL));                                      // seed random generation function
    int valid = 0;
    int size = blockoff.getSize();                          // get size of snake
    while(!valid)                                           // while we haven't found a valid (not on snake element) position for food, generate food position
    {
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        foodPos->setObjPos(rand_x, rand_y, '@');

        valid = 1;                                          // make valid to start
        for(int i = 0; i < size; i++ ){                     // check if generated position is the same as any element of snake
            objPos bodElement = blockoff.getElement(i);
            if(foodPos->isPosEqual(&bodElement)){
                valid = 0;                                  // make invalid if position if taken
            }
        }

    }
}

objPos Food::getFoodPos() const // getter: returns objPos object of Food position
{
    return *foodPos;
}

int Food::getFoodPosX() // getter: returns int of food x position
{
    return foodPos->pos->x;
}

int Food::getFoodPosY() // getter: returns int of food y position
{
    return foodPos->pos->y;
}

char Food::getFoodSymbol()  // getter: returns char of food symbol
{
    return foodPos->symbol;
}