#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()  // Default constructor
{
    // Initialize all game settings
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;

}

GameMechs::GameMechs(int boardX, int boardY)    // Special Constructor
{
    // Initializes all game settings to specified board measurements
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // destructor not needed, no new objects initialized on the heap
}

bool GameMechs::getExitFlagStatus() const   // getter: gets exit flag status
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const   // getter: gets lose flag status
{
    return loseFlag;
}   
    
void GameMechs::collectAsyncInput()     // collects input using MacUILib
{
    if(MacUILib_hasChar()){             // check if char has been input, set input if true
        input = MacUILib_getChar();
    }

    if(input == 27) exitFlag = true;    // check if exit button has been pressed, exits game if true
}

char GameMechs::getInput() const    // getter: gets input
{
    return input;
}

int GameMechs::getScore() const     // getter: gets score
{
    return score;
}

void GameMechs::incrementScore()    // setter: increments score by one
{
    score += 1;
}

int GameMechs::getBoardSizeX() const    // getter: gets int of board x size
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const    // getter: gets int of board y size
{
    return boardSizeY;
}


void GameMechs::setExitTrue()   // setter: sets exit flag status to true
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()   // setter: sets lost and exit flag status to true
{
    loseFlag = true;
    exitFlag = true;
}

void GameMechs::setInput(char this_input)   // setter: sets input with input parameter
{
    input = this_input;
}

void GameMechs::clearInput()    // setter: clears input
{
    input = '\0';
}

// More methods should be added here

