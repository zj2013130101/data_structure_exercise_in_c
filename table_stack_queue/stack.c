////
//// Created by joan on 19-7-3.
////
//
#include "stack.h"
#include "malloc.h"
#include <stdio.h>

/*stack implement by array */

#define MinStackSize 100
typedef int Position;

struct stack{
    int capacity;
    int top_pos;
    ElementType* elemArr;
};

void push(Stack s, ElementType element) {
    if( s->top_pos < s->capacity)
    {
        s->top_pos +=1;
        s->elemArr[s->top_pos] = element;
    }else
    {
        printf("Error: Stack is Full!");
    }
}

ElementType pop(Stack s) {
    if(s->top_pos > -1 )
        return s->elemArr[s->top_pos--];
    else{
        printf("stack is empty!\n");
        return 0;
    }
}

Stack createStack(int MaxElements) {
    Stack s = NULL;
    if(MaxElements < MinStackSize)
    {
        printf("Stack size is too small!");
    }
    s = (Stack) malloc( sizeof(struct stack));
    if(!s)
    {
        printf("out of space!\n");
        return NULL;
    }
    s->elemArr = (ElementType*) malloc( MaxElements * sizeof(ElementType));
    if(s->elemArr == NULL)
    {
        printf("Error: out of space!");
        free(s);
        return NULL;
    }
    s->top_pos = -1;
    s->capacity = MaxElements;
    return s;
}


int stackEmpty(Stack s)
{
    return s->top_pos == -1;
}



///*stack implement by list */
//typedef struct node* Position;
//struct node
//{
//    ElementType elem;
//    Position next;
//};
//
//
//struct stack{
//    struct node head;
//};
//
//
//void push(Stack s, ElementType elem)
//{
//    if(s)
//    {
//        Position pos = (Position)malloc(sizeof(struct node));
//        if(!pos)
//        {
//            printf("out of space!\n");
//            return;
//        }
//        pos->elem = elem;
//        pos->next = s->head.next;
//        s->head.next = pos;
//    }else
//        printf("stack is empty!\n");
//}
//
//ElementType pop(Stack s)
//{
//    if(!isEmpty(s))
//    {
//        Position pos = s->head.next;
//        s->head.next = pos->next;
//        ElementType elem = pos->elem;
//        free(pos);
//        return elem;
//    }else
//    {
//        printf("stack is empty!");
//        return 0;
//    }
//}
//
//int isEmpty(Stack s)
//{
//    if(s)
//        return s->head.next == NULL;
//    else
//        return 1;
//}
//
//ElementType top(Stack s)
//{
//    if(!isEmpty(s))
//    {
//        return s->head.next->elem;
//    }
//    else
//    {
//        printf("stack is empty!");
//        return 0;
//    }
//
//}
//
//Stack createStack()
//{
//    Stack s = (Stack) malloc(sizeof(struct stack));
//    if(s)
//    {
//        s->head.next = NULL;
//        return s;
//    }else{
//        printf("out of space!");
//        return NULL;
//    }
//
//}
//
//void makeEmpty(Stack s)
//{
//    if(s)
//    {
//        Position temp;
//        Position pos = s->head.next;
//        while(pos!=NULL)
//        {
//            temp = pos->next;
//            free(pos);
//            pos = temp;
//        }
//    }
//}
//
//
//
//void destroyStack(Stack s)
//{
//    if(s)
//    {
//        Position temp;
//        Position pos = s->head.next;
//        while(pos!=NULL)
//        {
//            temp = pos->next;
//            free(pos);
//            pos = temp;
//        }
//        free(s);
//    }
//}







