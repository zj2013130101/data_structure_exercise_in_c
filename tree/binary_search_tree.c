//
// Created by joan on 19-7-9.
//

#include <stdio.h>
#include <malloc.h>
#include "binary_search_tree.h"

typedef struct TreeNode* PtrNode;

//tree define
//struct TreeNode{
//    ElementType elem;
//    PtrNode fisrtchild;
//    PtrNode nextSibling;
//};


//tree preorder traversal
//static void ListDir(DirectoryOrFile D, int Depth)
//{
//    if( D is a valid entry)
//    {
//        PrintName(D, Depth);
//        if( D is a directory)
//        {
//            for each child, C, of D
//                ListDir(C, Depth+1);
//        }
//    }
//
//}


//tree postorder traversal
//static void SizeDirectory(DirectoryOrFile D)
//{
//    int TotalSize = 0;
//    if( D is a valid entry)
//    {
//        TotalSize += FileSize(D);
//        if(D is a directory)
//        {
//            for each child, C of D
//                TotalSize += SizeDirectory(C);
//        }
//    }
//}


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
    if(T != NULL)
    {
       if (T->elem > x) {
            return Find(T->left, x);
        } else if (T->elem < x) {
            return Find(T->right, x);
        }else
            return T;
    }else
        return NULL;
}

Position FindMin(SearchTree T)
{
    if(T != NULL)
    {
        if(T->left == NULL)         //base condition
        {
            return T;
        }else{
            return FindMin(T->left);
        }
    }else
        return NULL;
}

Position FindMax(SearchTree T)
{
    if(T)
    {
        if(T->right == NULL)    //base condition
            return T;
        else
            return FindMax(T->right);
    }else
        return NULL;

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

    return T;      /*don't forget this line*/
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

    return T;           /*don't forget this line*/
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