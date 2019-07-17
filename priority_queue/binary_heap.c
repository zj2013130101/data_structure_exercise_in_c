//
// Created by Joan on 2019/7/12.
//
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "binary_heap.h"

/**
 * 二叉堆实现：数组arr  （完全二叉树）
 *      元素从数组arr[1] ... a[HeapSize]
 */

/*place in the implementation file*/
/**
 * implementation by array
 */
struct HeapStruct{
    int Capacity;
    int Size;
    ElementType* elem;
};
#define MinHeapSize 63      //full binary tree have (2^n -1) nodes

PriorityQueue Init(int HeapSize)
{
    if(HeapSize < MinHeapSize)
    {
        printf("HeapSize is two small!\n");
        return NULL;
    }
    PriorityQueue q = (PriorityQueue)malloc(sizeof( struct HeapStruct));
    if( q == NULL)
    {
        printf("Error: out of space!\n");
        return NULL;
    }
    // allocate the array plus one extra for sentine1
    q->elem = (ElementType*)malloc( (HeapSize + 1) * sizeof(ElementType));
    if(q->elem == NULL)
    {
        printf("Error: out of space!\n");
        free(q);
        return NULL;
    }
    q->Capacity = HeapSize;
    q->Size = 0;
    return q;
}

void Destroy(PriorityQueue q)
{
    if(q != NULL)
    {
        free(q->elem);
        free(q);
    }
}

void MakeEmpty(PriorityQueue q)
{
    if(q != NULL)
    {
        q->Size = 0;
    }
}

/**
 * 将最后一个元素赋值到第一个元素，执行下滤操作
 * （第一个元素位置，看做空穴）
 * @param q
 * @return
 */
ElementType DeleteMin(PriorityQueue q)
{
    if(q == NULL)
    {
        printf("Error: Queue is not Exist!\n");
        return -1;
    }else if(IsEmpty(q))
    {
        printf("Error: Queue is Empty!");
        return q->elem[0];
    }

    ElementType MinElem = q->elem[1];
    ElementType LastElem = q->elem[q->Size--];      //q->Size-1

    /*find the position to insert LastElem*/
    int i=1, child;
    for(; i*2 <= q->Size; i = child)                  //类似DFS
    {
        /*find smaller child*/
        child = 2*i;
        if(child != q->Size && q->elem[child] > q->elem[child + 1])
            child++;

        /*precoLate one Level*/
        if( LastElem > q->elem[child])
        {
            q->elem[i] = q->elem[child];             //空穴下移
        }else
            break;
    }
    q->elem[i] = LastElem;
    return MinElem;
}

/**
 *  将元素追加到最后一个元素，执行上滤操作
 *  （最后一个元素位置，看做空穴）
 * @param q
 * @param elem
 */
void Insert(PriorityQueue q, ElementType elem)
{
    if(q == NULL)
    {
        printf("Error: Queue is not Exist!\n");
        return;
    }
    if(IsFull(q))
    {
        printf("Error: Queue is Full!");
        return;
    }
    int i= q->Size++;                           //q->Size+1
    int parent;
    for(; i/2 >=1; i = parent)
    {
        parent = i/2;
        if(q->elem[parent] > elem)
        {
            q->elem[i] = q->elem[parent];       //空穴上移
        }else
            break;
    }
    q->elem[i] = elem;
}

ElementType FindMin(PriorityQueue q)
{
    if(q != NULL && !IsEmpty(q))
    {
        return q->elem[1];
    }else
    {
        printf("Error: Queue is not Exist or Queue is Empty!");
        return -1;
    }
}

int IsFull(PriorityQueue q)
{
    if(q != NULL)
    {
        return q->Size == q->Capacity;
    }else
    {
        printf("Error: Queue is not exist!");
        return 1;
    }
}

int IsEmpty(PriorityQueue q)
{
    if(q != NULL)
    {
        return q->Size == 0;
    }else
    {
        printf("Error: Queue is not exist!");
        return 1;
    }
}

void LocateDown(PriorityQueue q, int pos)
{
    int i= pos, child;
    ElementType tempElem = q->elem[pos];
    for(; i*2 <= q->Size; i = child)
    {
        /*find the smaller child*/
        child = i*2;
        if(child != q->Size && q->elem[child] > q->elem[child + 1])
            child++;
        if( tempElem > q->elem[child])
            q->elem[i] = q->elem[child];
        else
            break;
    }
    q->elem[i] = tempElem;
}

PriorityQueue BuildHeap(int* elemArr, int elemSize, int HeapSize)
{
    if( elemArr == NULL)
    {
        printf("Error: input element array is Empty!\n");
        return NULL;
    }
    PriorityQueue queue = Init(HeapSize);
    if(queue == NULL)
    {
        printf("Error: Create Queue Fail!\n");
        return NULL;
    }
    memcpy(queue->elem + 1, elemArr, elemSize * sizeof(ElementType));
    queue->Size = elemSize;

    for(int i=elemSize/2; i > 0; i--)       //从倒数第二层开始（依次往上），每一个元素做下滤操作
        LocateDown(queue, i);
    return queue;
}