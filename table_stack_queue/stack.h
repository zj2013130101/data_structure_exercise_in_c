//
// Created by joan on 19-7-3.
//

#ifndef OFFER_EXERCISE_STACK_H
#define OFFER_EXERCISE_STACK_H

/*stack implement by array */
typedef int ElementType;
typedef struct stack* Stack;

void push(Stack s, ElementType element);
ElementType pop(Stack s);
int stackEmpty(Stack s);

Stack createStack(int MaxElements);


struct stack{
    int capacity;
    int top_pos;
    ElementType* elemArr;
};

///*stack implement by list */
//typedef struct stack* Stack;
//typedef int ElementType;
//
//void push(Stack s, ElementType elem);
//ElementType pop(Stack s);
//int isEmpty(Stack s);
//ElementType top(Stack s);
//void makeEmpty(Stack s);
//
//Stack createStack();
//void destroyStack(Stack s);


#endif //OFFER_EXERCISE_STACK_H

