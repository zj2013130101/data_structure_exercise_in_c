//
// Created by joan on 19-7-3.
//

#include <stdio.h>
#include <malloc.h>
#include "queue.h"

#define MIN_QUEUE_SIZE 5

struct queue{
    ElementType* elem;
    int front;
    int rear;
    int size;
    int capacity;
};

int isEmpty(Queue q)
{
    if(q)
    {
        return q->size == 0;
    }else
    {
        return 1;
    }

}

int isFull(Queue q)
{
    if(q)
    {
        return q->size == q->capacity;
    }else
        return 1;

}

Queue createQueue(int MaxElements)
{
    if(MaxElements < MIN_QUEUE_SIZE)
    {
        printf("elements size is too small\n");
        return NULL;
    }
    Queue q = (Queue)malloc(sizeof(struct queue));
    if(q != NULL)
    {
        q->elem = (ElementType*)malloc( MaxElements * sizeof(ElementType));
        if(q->elem)
        {
            q->front = 1;
            q->rear = 0;
            q->size = 0;
            q->capacity = MaxElements;
            return q;
        }else{
            printf("out of space\n");
            free(q);
            return NULL;
        }

    }else
    {
        printf("out of space\n");
        return NULL;
    }
}

void disposeQueue(Queue q)
{
    if(q)
    {
        free(q->elem);
        free(q);
    }
}

void makeEmpty(Queue q)
{
    if(q)
    {
        q->size = 0;
        q->front = 1;
        q->rear = 0;
    }
}

void enqueue(Queue q, ElementType elem)
{
    if(!isFull(q))
    {
        q->size++;
        q->rear = (q->rear + 1)%q->capacity;    //注意运算符优先级（注意前缀自增和后缀自增的区别）
        q->elem[q->rear] = elem;
    }else
    {
        printf("Queue is Full!\n");
    }
}

void dequeue(Queue q)
{
    if(!isEmpty(q))
    {
        q->size--;
        q->front = (q->front + 1)%q->capacity;
    }
}

ElementType front(Queue q)
{
    if(!isEmpty(q))
        return q->elem[q->front];
    else
    {
        printf("Queue is Empty!\n");
        return -1;
    }
}

ElementType frontAndDequeue(Queue q)
{
    if(!isEmpty(q))
    {
        q->size--;
        ElementType temp = q->elem[q->front];
        q->front = (q->front + 1)%q->capacity;
        return temp;
    }
    else{
        printf("Queue is Empty!\n");
        return -1;
    }
}


























