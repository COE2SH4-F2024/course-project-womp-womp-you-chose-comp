#include "objPosArrayList.h"
#include <iostream>
using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 1;
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

objPosArrayList &objPosArrayList::operator=(const objPosArrayList &d) //Copy assignment operator
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

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= ARRAY_MAX_CAP){ // IF SOMETHING IS BROKERN MAKE THIS ARRAY_MAX_CAP
        throw overflow_error("insertHead Error: List is already full");
    }
    for(int i = listSize; i > 0; i--)
    {
        // cout << "Element to shuffle: " << aList[i-1] << endl;
        aList[i] = aList[i - 1];
    }
    
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity)
    {
        throw overflow_error("insertTail Error: List is already full");
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0){
        throw underflow_error("removeHead Error: List is empty");
    }
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0){
        throw underflow_error("removeTail Error: List is empty");
    }
    
    listSize--;

}

objPos objPosArrayList::getHeadElement() const
{
    if(listSize == 0){
        throw underflow_error("getHeadElement Error: List is empty");
    }
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    if(listSize == 0){
        throw underflow_error("getTailElement Error: List is empty");
    }
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0 || index >= arrayCapacity){
        throw out_of_range("getElement Error: Index is out of range");
    }
    
    return aList[index];

}