#ifndef FOOD_H
#define FOOD_H

#include <time.h>
#include "Player.h"
#include "objPosArrayList.h"
#include "objPos.h"
#include "GameMechs.h"
#include <stdlib.h>


class Food
{

    private:
        objPos* food;
        GameMechs *mainGameMechsRef;

        int rand_x;
        int rand_y;

    public:
        Food(GameMechs *thisGMref);
        ~Food();

        void generateFood(const objPos& foodObj);
        objPos getFoodPos() const;
        int getFoodPosX() const;
        int getFoodPosY() const;

};
#endif