//
// Created by joan on 19-7-9.
//
#include <stdio.h>
#include <malloc.h>
#include "hashTbl_detect.h"
#include "hash_function.h"

#define MinTableSize 7

/*place in the implementation file*/
enum KindOfEntry{ valid, Empty, Deleted};

struct HashEntry{
    ElementType elem;
    enum KindOfEntry info;
};

typedef struct HashEntry Cell;
struct HashTbl{
    int TableSize;
    Cell *TheCells;
};

HashTable InitHashTable(int TableSize)
{
    if(TableSize < MinTableSize)
    {
        printf("TableSize is too small!\n");
        return NULL;
    }
    HashTable h = (HashTable) malloc( sizeof(struct HashTbl) );
    if( h == NULL)
    {
        printf("out of space !\n");
        return NULL;
    }
    h->TableSize = NextPrime(TableSize);
    h->TheCells = (Cell*) malloc( sizeof(struct HashEntry) * h->TableSize);
    if(h->TheCells == NULL)
    {
        printf("out of space !\n");
        free(h);
        return NULL;
    }
    for(int i=0; i< h->TableSize; i++)
    {
        h->TheCells[i].info = Empty;
    }
    return h;
}

void DestroyTable(HashTable h)
{
    if(h == NULL)
        return;
    free(h->TheCells);
    free(h);
}

/*使用平方探测法的散列*/
Position Find(HashTable h, ElementType elem)
{
    Position currPos = Hash4(elem, h->TableSize);
    int collisionNum = 0;
    while(h->TheCells[currPos].info != Empty
            && h->TheCells[currPos].elem != elem)      //probably need strcmp!
    {
        currPos += 2*(++collisionNum) - 1;             //F(i) = F(i-1) + 2*i -1
        if(currPos >= h->TableSize)
        {
            currPos -= h->TableSize;                   //table size must be very big, else will currPos > 2*h->TableSize
        }
    }
    return currPos;
}

void Insert(HashTable h, ElementType elem)
{
    Position currPos = Find(h, elem);
    if(h->TheCells[currPos].info != valid)
    {
        /*ok to insert here*/
        h->TheCells[currPos].elem = elem;       /*probably need strcpy*/
        h->TheCells[currPos].info = valid;
    }
}

ElementType Retrieve(HashTable h, Position p)
{
    if(h == NULL)
    {
        printf("h is empty!");
        return -1;
    }
    if(h->TheCells[p].info == valid)
        return h->TheCells[p].elem;
    else
    {
        printf("position is not valid\n");
        return -1;
    }
}

HashTable Rehash(HashTable h)
{
    int oldSize = h->TableSize;
    int newSize = oldSize * 2;
    Cell* newCells = (Cell*) malloc( newSize * sizeof(struct HashEntry));
    Cell* oldCells = h->TheCells;
    h->TheCells = newCells;
    h->TableSize = 2*oldSize;
    for(int i=0; i< oldSize; i++)
    {
        if(oldCells[i].info == valid)
            Insert(h, oldCells[i].elem);
    }
    free(oldCells);
    return h;
}