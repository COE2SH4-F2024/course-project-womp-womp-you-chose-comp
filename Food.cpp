#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs *thisGMref)
{
    mainGameMechsRef = thisGMref;
    foodPos = new objPos(5,6,'@');
}

Food::~Food()
{
    delete[] foodPos;
}

void Food::generateFood(const objPosArrayList& blockoff)
{
    srand(time(NULL));
    int valid = 0;
    int size = blockoff.getSize();
    while(!valid)
    {
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        foodPos->setObjPos(rand_x, rand_y, '@');

        valid = 1; 
        for(int i = 0; i < size; i++ ){
            objPos bodElement = blockoff.getElement(i);
            if(foodPos->isPosEqual(&bodElement)){
                valid = 0; 
            }
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