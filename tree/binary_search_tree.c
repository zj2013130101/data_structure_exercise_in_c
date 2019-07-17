//
// Created by joan on 19-7-9.
//

#include <stdio.h>
#include <malloc.h>
#include "binary_search_tree.h"

typedef struct TreeNode* PtrNode;

// binary tree define
struct TreeNode{
    ElementType elem;
    PtrNode left;
    PtrNode right;
};


SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);                //postorder traversal
    }
    return NULL;
}

Position Find(SearchTree T, ElementType x)
{
    if(T == NULL)       //base condition
        return NULL;

   if (T->elem > x) {
        return Find(T->left, x);
    } else if (T->elem < x) {
        return Find(T->right, x);
    }else
        return T;
}

Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;

    if(T->left == NULL)         //base condition
    {
        return T;
    }else{
        return FindMin(T->left);
    }
}

Position FindMax(SearchTree T)
{
    if(T == NULL)
        return NULL;

    if(T->right == NULL)    //base condition
        return T;
    else
        return FindMax(T->right);
}

/*FindMax的非递归实现*/
//Position FindMax(SearchTree T)
//{
//    if(T != NULL)
//    {
//        while(T->right != NULL)
//            T = T->right;
//    }
//    return T;
//}


SearchTree Insert(SearchTree T, ElementType elem)
{
    if(T == NULL)
    {
        /*Create and return a one-node tree*/
        T = (SearchTree)malloc( sizeof(struct TreeNode));
        if(T != NULL)
        {
            T->elem = elem;
            T->left = T->right = NULL;
        }else
        {
            printf("Error: out of space!");
            return NULL;
        }
    }
    else if(T->elem > elem)
        T->left = Insert(T->left, elem);
    else if(T->elem < elem)
        T->right = Insert(T->right, elem);

    /*else x is in the tree already; we'll do nothing*/

    return T;      /*don't forget this line*/ //构建父子链接关系
}


/*
 * 二叉搜索树删除节点有三种情况：
 *      (1). 节点是一片树叶；
 *      (2). 节点只有一个儿子；
 *      (3). 节点有两个儿子；
 *
 * */
SearchTree Delete(SearchTree T, ElementType elem)
{
    if( T != NULL)
    {
        if(T->elem == elem)
        {
            Position temp;
            if(T->left==NULL && T->right==NULL )            //leaf node
            {
                free(T);
                T = NULL;
            }else if(T->left== NULL && T->right != NULL)    //node with just right child
            {
                temp = T->right;
                free(T);
                T = temp;
            }else if(T->left!= NULL && T->right == NULL)    //node with just left child
            {
                temp = T->left;
                free(T);
                T = temp;
            }else if(T->left != NULL && T->right != NULL)   //node with two child
            {
                /* replace with smallest in right subtree*/
                temp = FindMin(T->right);
                T->elem = temp->elem;
                T->right = Delete(T->right, T->elem);
            }
        }else if(T->elem > elem)
            T->left = Delete(T->left, elem);
        else if(T->elem < elem)
            T->right = Delete(T->right, elem);
    }

    return T;           /*don't forget this line*/     //构建父子链接关系
}


SearchTree Delete2(SearchTree t, ElementType x)
{
    Position tmpCell;

    if(t == NULL)
        printf("Error: Element not Found!");
    else if( x < t->elem)   /*go left*/
    {
        t->left = Delete(t->left, x);
    }else if( x > t->elem)  /*go right*/
    {
        t->right = Delete(t->right, x);
    }else                   /*found element to be deleted*/
    {
        if( t->left && t->right)    /*two children*/
        {
            /*replace with smallest in right subtree*/
            tmpCell = FindMin(t->right);
            t->elem = tmpCell->elem;
            t->right = Delete(t->right, t->elem);
        }else                       /*One or zero childer*/
        {
            tmpCell = t;
            if(t->left == NULL)     //also handles 0 children
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            free(tmpCell);
        }
    }
    return t;       /*don't forget this line*/     //构建父子链接关系
}

ElementType Retrieve(Position p)
{
    if(p)
        return p->elem;
    else{
        printf("error: p is NULL");
        return -1;
    }
}


void printTree(SearchTree t)
{
    if(t != NULL)
    {
        printTree(t->left);
        printf("%d, ", t->elem);
        printTree(t->right);
    }
}