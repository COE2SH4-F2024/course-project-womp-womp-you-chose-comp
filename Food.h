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
        Food(GameMechs *thisGMref);                         // specific constructor
        ~Food();                                            // destructor

        void generateFood(const objPosArrayList& blockoff); // generates food with positions of all snake elements
        objPos getFoodPos() const;                          // returns objPos object of Food position
        int getFoodPosX();                                  // returns int of food x position
        int getFoodPosY();                                  // returns int of food y position
        char getFoodSymbol();                               // returns char of food symbol

};
#endif