#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFRef);
        ~Player();

        objPosArrayList* getPlayerPos() const;  // Upgrade this in iteration 3.       
        void updatePlayerDir();                 // Function to update player direction
        void movePlayer();                      // Where all player movement takes place

        // More methods to be added here
        Player(const Player &d);                // Copy constructor
        Player& operator=(const Player &d);     // Copy assigment operator
        int getPlayerDir();                     // Getting Player Direction
        bool checkSelfCollision();              // Checks if player collides with itself

    private:
        objPosArrayList* playerPosList;         // Upgrade this in iteration 3.       
        enum Dir myDir;                         // Enumeration for direction selection

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;
};

#endif