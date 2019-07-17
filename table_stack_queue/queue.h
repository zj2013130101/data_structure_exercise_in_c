//
// Created by joan on 19-7-3.
//

#ifndef OFFER_EXERCISE_QUEUE_H
#define OFFER_EXERCISE_QUEUE_H

/*queue implement in array (loop array)*/
typedef int ElementType;


struct queue;
typedef struct queue* Queue;

int isEmpty(Queue q);
int isFull(Queue q);
Queue createQueue(int MaxElements);
void disposeQueue(Queue q);
void makeEmpty(Queue q);
void enqueue(Queue q, ElementType elem);
void dequeue(Queue q);
ElementType front(Queue q);
ElementType frontAndDequeue(Queue q);


#endif //OFFER_EXERCISE_QUEUE_H

