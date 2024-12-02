#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;       // Snake
        int arrayCapacity;  // Max Snake Size

    public:
        objPosArrayList(); //Default constructor
        objPosArrayList(const objPosArrayList &d); //Copy cunstructor
        objPosArrayList& operator = (const objPosArrayList &d); //Copy assignment operator
        ~objPosArrayList(); //Destructor

        int getSize() const;
        void insertHead(objPos thisPos);    // Inserts New Head to snake
        void insertTail(objPos thisPos);    // Inserts New Tail to snake
        void removeHead();                  // Removes Snake Head
        void removeTail();                  // Removes Snake Tail
        
        objPos getHeadElement() const;      // Returns Head x-y coordinates
        objPos getTailElement() const;      // Return Tail x-Y Coordinates
        objPos getElement(int index) const; // Returns 1 element of the snake
};

#endif