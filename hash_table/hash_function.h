//
// Created by joan on 19-7-9.
//

#ifndef DATA_STRUCTURE_EXERCISE_HASH_FUNCTION_H
#define DATA_STRUCTURE_EXERCISE_HASH_FUNCTION_H

typedef unsigned int Index;
Index Hash(const char *key, int TableSize);
Index Hash2(const char* key, int TableSize);
Index Hash3(const char *key, int TableSize);
Index Hash4(int key, int TableSize);

int NextPrime(int TableSize);

#endif //DATA_STRUCTURE_EXERCISE_HASH_FUNCTION_H
