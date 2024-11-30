#ifndef FOOD_H
#define FOOD_H

#include <time.h>
#include "objPosArrayList.h"
#include "objPos.h"
#include "GameMechs.h"
#include <stdlib.h>


class Food
{

    private:
        objPos* foodPos;
        GameMechs *mainGameMechsRef;

        int rand_x;
        int rand_y;

    public:
        Food(GameMechs *thisGMref);
        ~Food();

        void generateFood(const objPosArrayList& blockoff);
        objPos getFoodPos() const;
        int getFoodPosX();
        int getFoodPosY();
        char getFoodSymbol();

};
#endif