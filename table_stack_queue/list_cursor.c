////
//// Created by joan on 19-7-3.
////
//
//#include "list_cursor.h"
//#include <stdio.h>
//
//#define Spacesize 10
//
//struct Node{
//    ElementType element;
//    Position next;
//};
//
////cursorSpace[0]为freelist的表头
//struct Node cursorSpace[Spacesize];
//
//void InitializeCursorSpace(void) {
//    for(int i=0; i < Spacesize; i++)
//    {
//        cursorSpace[i].next = (i+1)%Spacesize;      //初始化freeList表（标记结构体数组分配）
//    }
//}
//
//static Position cursorAlloc(void)
//{
//    Position p;
//    p = cursorSpace[0].next;
//    cursorSpace[0].next = cursorSpace[p].next;
//    return p;
//}
//
//static void cursorFree(Position p)
//{
//    int tmpCell = cursorSpace[0].next;
//    cursorSpace[0].next = p;            //将释放的结构体记录到freeList中(cursorSpace[0]为表头)
//                                        //Cache友好型，下一次分配从该点开始
//    cursorSpace[p].next = tmpCell;
//}
//
///**
// *
// * 空的条件为：cursorSpace[l].next = 0
// *  * l is the list header
// * @param l
// * @return
// */
//List makeEmpty(List l) {
//    Position tmpCell;           //assume l is header
//    while(cursorSpace[l].next != 0)
//    {
//        tmpCell = cursorSpace[l].next;
//        cursorSpace[l].next = cursorSpace[tmpCell].next;
//        cursorFree(tmpCell);
//    }
//    return 0;
//}
//
//int isEmpty(const List l) {
//    return cursorSpace[l].next == 0;
//}
//
//int isLast(const List l, const Position p) {
//    return cursorSpace[p].next == 0;
//}
//
//Position Find(List l, ElementType element) {
//    while(cursorSpace[l].next != 0 && cursorSpace[l].element != element)
//        l = cursorSpace[ cursorSpace[l].next ].next;
//    return l;
//}
//
//Position FindPrevious(List l, ElementType element) {
//    while( cursorSpace[ cursorSpace[l].next].next !=0 && cursorSpace[ cursorSpace[l].next].element != element)
//        l = cursorSpace[ cursorSpace[l].next].next;
//    return l;
//}
//
//void Delete(const List l, ElementType element) {
//    Position p = FindPrevious(l, element);
//    Position tmpCell = cursorSpace[p].next;
//    cursorSpace[p].next = cursorSpace[tmpCell].next;
//    cursorFree(tmpCell);
//}
//
//void Insert(const List l, ElementType element, Position p) {
//    Position tmpCell = cursorAlloc();
//    if(tmpCell==0)
//    {
//        printf( "Out of space!\n");
//        return;
//    }
//    cursorSpace[tmpCell].element = element;
//    cursorSpace[tmpCell].next = cursorSpace[p].next;
//    cursorSpace[p].next = tmpCell;
//}
//
//void DeleteList(const List l) {
//    Position pos;                       //assume l is list header
//    while( cursorSpace[l].next !=0)
//    {
//        pos = cursorSpace[l].next;
//        cursorSpace[l].next = cursorSpace[pos].next;
//        cursorFree(pos);
//    }
//}
//
//Position Header(const List l) {
//    return l;
//}
//
//Position First(const List l) {
//    return cursorSpace[l].next;
//}
//
//Position Advance(const Position p) {
//    return cursorSpace[p].next;
//}
//
//ElementType Retrieve(const Position p) {
//    return cursorSpace[p].element;
//}
//
//List CreateList() {
//    List l = cursorAlloc();
//    if(!l)
//    {
//        printf( "Out of space!\n");
//        return 0;
//    }
//    cursorSpace[l].next = 0;
//    return l;
//}
//
//
////int main(int argc, char * argv[])
////{
////    /* single list use array */
////    InitializeCursorSpace();
////    List l = CreateList();  //header
////    vector<int> arr = {1, 3, 5, 6, 8, 0, 12, 15};
////    for(auto element : arr)
////    {
////        cout << element << endl;
////        Insert(l, element, Header(l));
////    }
////
////    Delete(l, 0);
////    Delete(l, 5);
////    Insert(l, 33, Header(l));
////    Delete(l, 6);
////    Insert(l, 7, Header(l));
////
////
////    for(Position p = Advance(Header(l)); p != 0; p = Advance(p))
////    {
////        cout << Retrieve(p) << endl;
////    }
////}