#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs *thisGMref)
{
    mainGameMechsRef = thisGMref;
    food = new objPos(10,10,'@');
}

Food::~Food()
{
    delete[] food;
}

void Food::generateFood(const objPos& blockoff)
{
    int valid = 0;
    while(!valid)
    {
        valid = 1; 
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        food->setObjPos(rand_x, rand_y, '@');

        if(food->isPosEqual(&blockoff)){
            valid = 0; 
        }
    }
}

objPos Food::getFoodPos() const
{
    return *food;
}

int Food::getFoodPosX()
{
    return food->pos->x;
}

int Food::getFoodPosY()
{
    return food->pos->y;
}

char Food::getFoodSymbol()
{
    return food->symbol;
}