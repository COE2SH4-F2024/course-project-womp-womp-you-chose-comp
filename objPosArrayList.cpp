#include "objPosArrayList.h"

#include "objPosArrayList.h"
#include <iostream>
using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()  //Constructor
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
}


objPosArrayList::objPosArrayList(const objPosArrayList &d) // Copy Constructor
{
    listSize = d.listSize;
    arrayCapacity = d.arrayCapacity;

    aList = new objPos[arrayCapacity];

    for(int i = 0; i < listSize; i++)
    {
        aList[i] = d.aList[i];
    }
}

objPosArrayList &objPosArrayList::operator=(const objPosArrayList &d) // Copy Assignment operator 
{
    if(this != &d)
    {
        delete[] aList;

        listSize = d.listSize;
        arrayCapacity = d.arrayCapacity;
        aList = new objPos[arrayCapacity];

        for(int i = 0; i < listSize; i++)
        {
            aList[i] = d.aList[i];
        }
    }
    return *this;
}

objPosArrayList::~objPosArrayList() // Destructor
{
    delete[] aList;
}

int objPosArrayList::getSize() const // Getter
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)    // Inserts New Head
{
    if(listSize >= ARRAY_MAX_CAP){
        throw overflow_error("insertHead Error: List is already full");
    }
    
    for(int i = listSize-1; i >= 0; i--)            // Shuffeling elements of the snake
    {
        aList[i+1] = aList[i];
    }
    //First element
    aList[0] = thisPos;
    
    //incrementing size of list
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)    // Inserts Tail
{
    if(listSize >= arrayCapacity)
    {
        throw overflow_error("insertTail Error: List is already full");
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()                  // Removes Head of Snake
{
    if(listSize == 0){
        throw underflow_error("removeHead Error: List is empty");
    }
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }
    //decrementing list size
    listSize--;
}

void objPosArrayList::removeTail()                  // Removes tail of Snake
{
    if(listSize == 0){
        throw underflow_error("removeTail Error: List is empty");
    }
    
    listSize--;

}

objPos objPosArrayList::getHeadElement() const      // Returns Head Element
{
    if(listSize == 0){
        throw underflow_error("getHeadElement Error: List is empty");
    }
    return aList[0]; // return first element in list
}

objPos objPosArrayList::getTailElement() const      // Returns Tail Element
{
    if(listSize == 0){
        throw underflow_error("getTailElement Error: List is empty");
    }

    //returning last item in list
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const // Returns Element of Snake
{
    if(index < 0 || index >= arrayCapacity){
        throw out_of_range("getElement Error: Index is out of range");
    }
    
    // return the item at "index"
    return aList[index];

}
