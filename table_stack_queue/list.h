//
// Created by joan on 19-7-3.
//

#ifndef OFFER_EXERCISE_LIST_H
#define OFFER_EXERCISE_LIST_H


struct node;
typedef struct node* PtrNode;
typedef PtrNode List;
typedef PtrNode Position;
typedef int ElementType;

List CreateList();
List MakeEmpty(List l);
int IsEmpty(List l);
int IsLast(List l, Position p);
Position Find(List l, ElementType x);
Position FindPrevious(List l, ElementType x);
void Delete(List l, ElementType x);
void Insert(List l, ElementType x, Position p);
void DeleteList(List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
ElementType Retrieve(List l, Position p);

#endif //OFFER_EXERCISE_LIST_H