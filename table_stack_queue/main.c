#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
//#include "list.h"
//#include "list_cursor.h"
//#include "stack.h"
#include "queue.h"

//int main(int argc, char **argv)
//{
//    /* stack implement in array*/
//    Stack s = createStack();
//
//    for(int i=0; i < 5; i++)
//    {
//        push(s, i);
//    }
//
//    pop(s);
//    pop(s);
//    push(s, 100);
//    push(s, 21);
//
//    for(int i=0; i< 10; i++)
//    {
//        if(!stackEmpty(s))
//            printf("element: %d\n", pop(s));
//    }
//
//    free(s);
//}



//int main() {
//
//    /* stack implement in list*/
//    Stack s = createStack();
//
//    for(int i=0; i < 5; i++)
//    {
//        push(s, i+3);
//    }
//
//    pop(s);
//    pop(s);
//    push(s, 100);
//    push(s, 21);
//    pop(s);
//    push(s, 15);
//
//    for(int i=0; i< 10; i++)
//    {
//        if(!isEmpty(s))
//            printf("element: %d\n", pop(s));
//    }
//
//}


int main()
{
    /*queue implement in loop array*/
    Queue q = createQueue(6);

    makeEmpty(q);

    for(int i=0; i< 6; i++)
    {
        enqueue(q, i);
    }

    printf("before: \n");
    for(int i=0; i< 4; i++)
    {
        printf("elem : %d\n", frontAndDequeue(q));
    }

    enqueue(q, 13);
    enqueue(q, 50);
    enqueue(q, 20);
    enqueue(q, 27);

    printf("after: \n");
    for(int i=0; i< 6; i++)
    {
        printf("elem : %d\n", frontAndDequeue(q));
    }


    printf("elem : %d\n", frontAndDequeue(q));

    disposeQueue(q);
}














