#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        objPos food;

    public:
        GameMechs();                        // Default constructor
        GameMechs(int boardX, int boardY);  // Special Constructor
        ~GameMechs();                       // destructor not needed, no new objects initialized on the heap
        
        bool getExitFlagStatus() const;     // getter: gets exit flag status
        void setExitTrue();                 // setter: sets exit flag status to true
        bool getLoseFlagStatus() const;     // getter: gets lose flag status
        void setLoseFlag();                 // setter: sets lost and exit flag status to true

        char getInput() const;              // getter: gets input
        void setInput(char this_input);     // setter: sets input with input parameter
        void clearInput();                  // setter: clears input

        int getBoardSizeX() const;          // getter: gets int of board x size
        int getBoardSizeY() const;          // getter: gets int of board y size
        
        int getScore() const;               // getter: gets score
        void incrementScore();              // setter: increments score by one
        
        // More methods should be added here
        void collectAsyncInput();           // collects input using MacUILib
};

#endif