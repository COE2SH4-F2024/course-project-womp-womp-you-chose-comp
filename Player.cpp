#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    //New initialization of head position. 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(5,5,'*'));

    // Original initialization of player Coords
    // playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    // playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2 ;
    // playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructotr, hence no heap member.

    // we can leave the destructor empty for now...
    // Iteration 3 update: NOT ANYMORE??

}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
    
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();
    

    objPos nextPosition = objPos(playerPosList->getHeadElement());
    
    int headXPos = nextPosition.pos->x;
    int headYPos = nextPosition.pos->y;

    // if (myDir == UP){
    //     if (headYPos > 1){
    //         headYPos--;
    //     }
    //     else{
    //         headYPos = (boardY-2);
    //     }
    // }

    // else if(myDir == DOWN){
    //     if (headYPos < (boardY-2)){
    //         headYPos++;
    //     }
    //     else{
    //         headYPos = 1;
    //     }
    // }

    // else if(myDir == RIGHT){
    //     if (headXPos < (boardX-2)){
    //         headXPos++;
    //     }
    //     else{
    //         headXPos = 1;
    //     }
    // }

    // else if(myDir == LEFT){
    //     if (headXPos > 1){
    //         headXPos--;
    //     }
    //     else{
    //         headXPos = (boardX-2);
    //     }
    // }

    switch(myDir)
    {
        case UP:
            headYPos--;
            break;
        case LEFT:
            headXPos--;
            break;
        case RIGHT:
            headXPos++;
            break;
        case DOWN:
            headYPos++;
            break;
        default:
            break;
    }

    //Top/bottom wraparound
    if(headYPos>=boardY-1)
    {
        headYPos = 1;
    }
    else if(headYPos<=0)
    {
        headYPos=boardY-2;
    }

    //Left/right wraparound
    if(headXPos>=boardX-1)
    {
        headXPos = 1;
    }
    else if(headXPos<=0)
    {
        headXPos=boardX-2;
    }

    //New Head position:
    nextPosition.setObjPos(headXPos,headYPos);
    playerPosList->insertHead(nextPosition);
    playerPosList->removeTail();
}

// More methods to be added
int Player::getPlayerDir()
{
    return myDir;
}