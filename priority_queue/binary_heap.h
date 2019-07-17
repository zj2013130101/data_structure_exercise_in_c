//
// Created by Joan on 2019/7/12.
//

#ifndef DATA_STRUCTURE_EXERCISE_BINARY_HEAP_H
#define DATA_STRUCTURE_EXERCISE_BINARY_HEAP_H

struct HeapStruct;
typedef int ElementType;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Init(int HeapSize);
void Destroy(PriorityQueue q);
void MakeEmpty(PriorityQueue q);
ElementType DeleteMin(PriorityQueue q);
void Insert(PriorityQueue q, ElementType elem);
ElementType FindMin(PriorityQueue q);
int IsFull(PriorityQueue q);
int IsEmpty(PriorityQueue q);

PriorityQueue BuildHeap(int* elemArr, int elemSize, int HeapSize);
#endif //DATA_STRUCTURE_EXERCISE_BINARY_HEAP_H

/*place in the implementation file*/
/**
 * implementation by array
 */
struct HeapStruct{
    int Capacity;
    int Size;
    ElementType* elem;
};