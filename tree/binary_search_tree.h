//
// Created by joan on 19-7-9.
//

#ifndef DATA_STRUCTURE_EXERCISE_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURE_EXERCISE_BINARY_SEARCH_TREE_H

struct TreeNode;

typedef int ElementType;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(SearchTree T, ElementType x);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(SearchTree T, ElementType elem);
SearchTree Delete(SearchTree t, ElementType elem);
ElementType Retrieve(Position p);

#endif //DATA_STRUCTURE_EXERCISE_BINARY_SEARCH_TREE_H
