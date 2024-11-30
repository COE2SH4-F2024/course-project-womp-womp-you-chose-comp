#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs *thisGMref)
{
    mainGameMechsRef = thisGMref;
    foodPos = new objPos(10,10,'@');
}

Food::~Food()
{
    delete[] foodPos;
}

void Food::generateFood(const objPos& blockoff)
{
    int valid = 0;
    while(!valid)
    {
        valid = 1; 
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        foodPos->setObjPos(rand_x, rand_y, '@');

        if(foodPos->isPosEqual(&blockoff)){
            valid = 0; 
        }
    }
}

objPos Food::getFoodPos() const
{
    return *foodPos;
}

int Food::getFoodPosX()
{
    return foodPos->pos->x;
}

int Food::getFoodPosY()
{
    return foodPos->pos->y;
}

char Food::getFoodSymbol()
{
    return foodPos->symbol;
}