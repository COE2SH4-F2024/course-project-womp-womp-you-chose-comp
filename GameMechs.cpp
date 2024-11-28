#include "GameMechs.h"

GameMechs::GameMechs()
{
    char input = 0;
    bool exitFlag = false;
    bool loseFlag = false;
    int score = 0;

    int boardSizeX = 20;
    int boardSizeY = 10;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    char input = 0;
    bool exitFlag = false;
    bool loseFlag = false;
    int score = 0;

    int boardSizeX = boardX;
    int boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // NOT YET!
}

bool GameMechs::getExitFlagStatus() const
{

}

bool GameMechs::getLoseFlagStatus() const
{

}
    

char GameMechs::getInput() const
{

}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{

}

int GameMechs::getBoardSizeY() const
{

}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here