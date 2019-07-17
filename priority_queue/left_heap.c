//
// Created by Joan on 2019/7/12.
//

#include "left_heap.h"


/**
 * 左式堆实现：链式——支持高效合并
 */
struct TreeNode;
typedef struct TreeNode* PtrNode;
typedef int ElementType;

/*Place in implementation file*/
struct TreeNode
{
    ElementType elem;
    PtrNode left;
    PtrNode right;
    int Npl;
};