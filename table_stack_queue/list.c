////
//// Created by joan on 19-7-3.
////
//
//#include "list.h"
//#include "stdio.h"
//#include "malloc.h"
//
//struct node{
//    ElementType element;
//    Position next;
//};
//
//List MakeEmpty(List l) {
//    while(l->next != NULL)
//    {
//        List temp = l->next;
//        l->next = l->next->next;
//        free(temp);
//    }
//    return l;
//}
//
//int IsEmpty(List l) {
//    return l->next == NULL;
//}
//
//int IsLast(List l, Position p) {
//    return p->next == NULL;
//}
//
//Position Find(List l, ElementType x) {
//    Position pos = l->next;         //remove header
//    for(; pos != NULL; pos = pos->next)
//    {
//        if(pos->element == x)
//            return pos;
//    }
//    return pos;
//}
//
//Position FindPrevious(List l, ElementType x) {
//    Position p;
//    p = l->next;    //remove header
//    while( p->next!=NULL && p->next->element !=x)
//        p = p->next;
//    return p;
//}
//
//void Delete(List l, ElementType x) {
//    Position p = FindPrevious(l, x);
//    Position tmpCell;
//    tmpCell = p->next;
//    p->next = p->next->next;
//    free( tmpCell);
//}
//
//void Insert(List l, ElementType x, Position p) {
//    Position tmpCell = (Position)malloc(sizeof(struct node));
//    if(tmpCell == NULL)
//    {
//        printf("Out of space!\n");
//        return;
//    }
//    tmpCell->element = x;
//    tmpCell->next = p->next;
//    p->next = tmpCell;
//}
//
//void DeleteList(List l) {
//    while( l->next != NULL)
//    {
//        Position tmpCell = l->next;
//        l->next = l->next->next;
//        free( tmpCell);
//    }
//    free(l);
//}
//
//Position Header(List l) {
//    return l;
//}
//
//Position First(List l) {
//    return l->next;
//}
//
//Position Advance(Position p) {
//    return p->next;
//}
//
//ElementType Retrieve(List l, Position p) {
//    if(p!= NULL)
//        return p->element;
//    else
//    {
//        printf("error!\n");
//        return -1;
//    }
//}
//
//List CreateList() {
//    List l = (List)malloc(sizeof(struct node));
//    if(!l)
//    {
//        printf("Out of space!\n");
//        return NULL;
//    }
//    l->next = NULL;
//    return l;
//}
//
//
////int main(int argc, char *argv[])
////{
////    /* single list  */
////    List l = CreateList();  //header
////    int arr[] = {1, 3, 5, 6, 8, 0, 12, 15};
////    for(int i=0; i< sizeof(arr); i++)
////    {
////        Insert(l, arr[i], Header(l));
////    }
////
////    for(Position p= Advance(Header(l)); p != NULL; p = Advance(p))
////    {
////        printf("%d\n", Retrieve(l, p));
////    }
////}
