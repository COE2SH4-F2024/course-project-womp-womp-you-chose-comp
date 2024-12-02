#include "objPos.h"

objPos::objPos()    // Default Constructor
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0;
}

objPos::objPos(int xPos, int yPos, char sym)    // Special Constructor with specified coordinates and symbol
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos::~objPos()   // Destructor
{
    delete pos;
}

objPos::objPos(const objPos &d)     // Copy Constructor
{
    // Deep Copy: make coordinates and symbol of new object equal to that of parameter object
    pos = new Pos;
    pos->x = d.pos->x;
    pos->y = d.pos->y;
    symbol = d.symbol;
}

objPos& objPos::operator=(const objPos &d)  // Copy Assignment Operator
{
    if(this != &d)      // Copy arguments only if the objects are different objects
    {
        delete pos;     // delete original coordinate struct

        // Deep Copy: make coordinates and symbol of this object equal to that of parameter object
        pos = new Pos;
        this->pos->x = d.pos->x; 
        this->pos->y = d.pos->y;
        this->symbol = d.symbol;
    }

    return *this;
    
}



void objPos::setObjPos(objPos o)    // Setter: Set coordinates and symbol to the same as given object     
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)    // Setter: Set coordinates and symbol to those given
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

void objPos::setObjPos(int xPos, int yPos)  // Setter: Set coordinates to those given
{
    pos->x = xPos;
    pos->y = yPos;
}

objPos objPos::getObjPos() const    // Getter: Gets coordinates object
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const  // Getter: Gets symbol
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const     // Returns bool of whether two objects have same position    
{
    return ((refPos->pos->x == pos->x) && (refPos->pos->y == pos->y));
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const    // Getter: returns symbol of object if position is equal to another object's position
{
    // Check if the position/coordinates are equal, if yes, return symbol
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
