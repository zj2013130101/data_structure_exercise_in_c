//
// Created by joan on 19-7-9.
//
#ifndef DATA_STRUCTURE_EXERCISE_HASHTBL_DETECT_H
#define DATA_STRUCTURE_EXERCISE_HASHTBL_DETECT_H

/**
 *  hash table with solving conflict using detect way
 * three detect way:
 *      (1). 线性探测
 *      (2). 平方探测
 *      (3). 双散列
 */
typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitHashTable(int TableSize);
void DestroyTable(HashTable h);
Position Find(HashTable h, ElementType elem);
void Insert(HashTable h, ElementType elem);
ElementType Retrieve(HashTable h, Position p);
HashTable Rehash(HashTable h);

/*routines such as Delete and makeEmpty are omitted*/

#endif //DATA_STRUCTURE_EXERCISE_HASHTBL_DETECT_H