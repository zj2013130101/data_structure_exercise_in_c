//
// Created by joan on 19-7-9.
//

#ifndef DATA_STRUCTURE_EXERCISE_HASHTBL_LIST_H
#define DATA_STRUCTURE_EXERCISE_HASHTBL_LIST_H

/*hash table with solving conflict using list*/
typedef int ElementType;

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitTable(int TableSize);
void DestryTable(HashTable h);
Position Find(HashTable h, ElementType elem);
void Insert(HashTable h, ElementType elem);
ElementType Retrieve(Position p);

/*Delete and MakeEmpty routines are omitted*/


#endif //DATA_STRUCTURE_EXERCISE_HASHTBL_LIST_H