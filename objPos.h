#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct  // struct for holding our (x,y) coordinates for an objPos object
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;                                               // Pointer to coordinate/Pos struct        
        char symbol;

        objPos();                                               // Default Constructor
        objPos(int xPos, int yPos, char sym);                   // Special Constructor with specified coordinates and symbol
        
        ~objPos();                                              // Destructor
        objPos(const objPos &d);                                // Copy Constructor
        objPos& operator=(const objPos &d);                     // Copy Assignment Operator

        
        void setObjPos(objPos o);                               // Setter: Set coordinates and symbol to the same as given object     
        void setObjPos(int xPos, int yPos, char sym);           // Setter: Set coordinates and symbol to those given
        void setObjPos(int xPos, int yPos);                     // Setter: Set coordinates to those given

        objPos getObjPos() const;                               // Getter: Gets coordinates object
        char getSymbol() const;                                 // Getter: Gets symbol
        char getSymbolIfPosEqual(const objPos* refPos) const;   // Getter: returns symbol of object if position is equal to another object's position
        
        bool isPosEqual(const objPos* refPos) const;            // Returns bool of whether two objects have same position
};

#endif