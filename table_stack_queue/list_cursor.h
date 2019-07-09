//
// Created by joan on 19-7-3.
//

#ifndef OFFER_EXERCISE_LIST_CURSOR_H
#define OFFER_EXERCISE_LIST_CURSOR_H


/**
 *
 * 链表的游标实现：不支持指针的情况下，用数组实现链表（全局结构体数组，索引字段为数组下标）。
 * 数组下标实现指针索引，freelist空闲数组链表标记资源分配。
 *
 *
 */

typedef int ElementType;
typedef int PtrNode;
typedef PtrNode List;
typedef PtrNode Position;


void InitializeCursorSpace(void);


List makeEmpty(List l);
int isEmpty(const List l);
int isLast(const List l, const Position p);
Position Find(List l, ElementType element);
void Delete(const List l, ElementType element);
Position FindPrevious(List l, ElementType element);
void Insert(const List l, ElementType element, Position p);
void DeleteList(const List l);
Position Header(const List l);
Position First(const List l);
Position Advance(const Position p);
ElementType Retrieve(const Position p);

List CreateList();




#endif //OFFER_EXERCISE_LIST_CURSOR_H
