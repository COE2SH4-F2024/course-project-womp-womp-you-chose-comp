#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = 5;
    playerPos.pos->y = 5;
    playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructotr, hence no heap member.

    // we can leae the destructor empty for now...
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic

        //Where do i get the input

        switch(input)
        {
            case 27:  // exit
                exitFlag = 1;
                break;
            case 'w': //w key
                if (state != DOWN){
                    state = UP;
                }
                break;
            case 'a': // a key
                if (state != RIGHT){ 
                state = LEFT;
                }
                break;
            case 's': // s key
                if (state != UP){ 
                state = DOWN;
                }
                break;
            case 'd': // d key
                if (state != LEFT){ 
                state = RIGHT;
                }
                break;
            default:
                state = STOP;
                break; 
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added