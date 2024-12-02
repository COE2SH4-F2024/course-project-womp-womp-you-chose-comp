#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFRef)    
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFRef;
    myDir = STOP;
    // more actions to be included
    //New initialization of head position. 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(10,5,'o'));
}


Player::~Player()           // Destructor
{
    delete playerPosList;   // Deleting PlayerPosList from the heap
}

objPosArrayList* Player::getPlayerPos() const   // Getter
{
    
    return playerPosList;           // Return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()  
{
    // PPA3 input processing logic:
    char input = mainGameMechsRef->getInput();

    switch(input) // Switch Case to determine input
    {
        case 27:  // Case if "esc" key
            mainGameMechsRef->setExitTrue();    // Ends Game
            break;

        case 'w': //Case if w key
            if (myDir != DOWN){
                myDir = UP;
            }
            break;

        case 'a': // Case if a key
            if (myDir != RIGHT){ 
            myDir = LEFT;
            }
            break;
        
        case 's': // Case if s key
            if (myDir != UP){ 
            myDir = DOWN;
            }
            break;
        
        case 'd': // Case if d key
            if (myDir != LEFT){ 
            myDir = RIGHT;
            }
            break;
        
                //Debugging cases/cheat code ;)
        case 'p':
            mainGameMechsRef->incrementScore();
            break;
        case 'l':
            mainGameMechsRef->setLoseFlag();
            break;
            
        default:    // Default case, no key pressed
            break; 
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    
    int boardX = mainGameMechsRef->getBoardSizeX();     // X board coordinate
    int boardY = mainGameMechsRef->getBoardSizeY();     // Y board coordinate
    
    objPos FoodPos = mainFoodRef->getFoodPos();         // Getting Food element x-y coordinates
    objPos nextPosition = objPos(playerPosList->getHeadElement());
    
    int headXPos = nextPosition.pos->x;     // Setting next head position (x)
    int headYPos = nextPosition.pos->y;     // Setting next head position (y) 

    switch(myDir) // Updating Position Based on Direction
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
    nextPosition.setObjPos(headXPos,headYPos);      // Setting next Head x/y position
    playerPosList->insertHead(nextPosition);        // Placing Head of snake at next position
    if(!FoodPos.isPosEqual(&nextPosition)){         // Checking if head is eating food
        playerPosList->removeTail();                // Removes snake tail
    }
    else
    {
      mainFoodRef->generateFood(*playerPosList);    // Generates a new food
      mainGameMechsRef->incrementScore();           // INcrements score
    }

    if(checkSelfCollision()){                       // Checks self conflict flag
        mainGameMechsRef->setLoseFlag();            // Ends Game
    }
    
}

// More methods to be added
int Player::getPlayerDir()
{
    return myDir;
}

bool Player::checkSelfCollision()
{
    objPos headObjPos = playerPosList->getHeadElement(); 
    objPos bodyElement;

    for(int k = 1; k < playerPosList->getSize(); k++){      // Iterates through snake body
        bodyElement = playerPosList->getElement(k);         // Sets objPos bodyElement
        if(headObjPos.isPosEqual(&bodyElement)){            // Checks if head is ever hitting body element
            return true;
        }
    }
    return false;
}