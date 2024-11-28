#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2 ;
    playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructotr, hence no heap member.

    // we can leave the destructor empty for now...
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
       char input = mainGameMechsRef->getInput();
        //Where do i get the input

        switch(input)
        {
            case 27:  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w': //w key
                if (myDir != DOWN){
                    myDir = UP;
                }
                break;
            case 'a': // a key
                if (myDir != RIGHT){ 
                myDir = LEFT;
                }
                break;
            case 's': // s key
                if (myDir != UP){ 
                myDir = DOWN;
                }
                break;
            case 'd': // d key
                if (myDir != LEFT){ 
                myDir = RIGHT;
                }
                break;
           
            //debugging cases
            case 'p':
                mainGameMechsRef->incrementScore();
                break;
            case 'l':
                mainGameMechsRef->setLoseFlag();
                break;
                
            default:
                myDir = STOP;
                break; 
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if (myDir == UP){
        if (playerPos.pos->y > 1){
            playerPos.pos->y--;
        }
        else{
            playerPos.pos->y = (mainGameMechsRef->getBoardSizeY()-2);
        }
    }

    else if(myDir == DOWN){
        if (playerPos.pos->y < (mainGameMechsRef->getBoardSizeY()-2)){
            playerPos.pos->y++;
        }
        else{
            playerPos.pos->y = 1;
        }
    }

    else if(myDir == RIGHT){
        if (playerPos.pos->x < (mainGameMechsRef->getBoardSizeX()-2)){
            playerPos.pos->x++;
        }
        else{
            playerPos.pos->x = 1;
        }
    }

    else if(myDir == LEFT){
        if (playerPos.pos->x > 1){
            playerPos.pos->x--;
        }
        else{
            playerPos.pos->x = (mainGameMechsRef->getBoardSizeX()-2);
        }
    }
}

// More methods to be added