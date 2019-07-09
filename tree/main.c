
#include "stdio.h"
#include "binary_search_tree.h"


int main() {
    SearchTree tree = NULL;                //一定要赋初值

    tree = Insert(tree, 10);
    tree = Insert(tree, 1);
    tree = Insert(tree, 4);
    tree = Insert(tree, 50);
    tree = Insert(tree, 7);
    tree = Insert(tree, 21);
    tree = Insert(tree, 8);

    printf("Before :\n");
    printTree(tree);

    Position p = FindMin(tree);
    printf("Min : %d\n", Retrieve(p));

    p = FindMax(tree);
    printf("Max : %d\n", Retrieve(p));

    p = NULL;
    p = Find(tree, 3);
    if(p)
    {
        printf("Find elem 3!\n");
    }

    p = NULL;
    p = Find(tree, 4);
    if(p)
    {
        printf("Find elem 4!\n");
    }


    printf("After :\n");
    Delete(tree, 7);
    Delete(tree, 10);
    Delete(tree, 50);

    printTree(tree);

    p = FindMin(tree);
    printf("Min : %d\n", Retrieve(p));
    p = FindMax(tree);
    printf("Max : %d\n", Retrieve(p));

    MakeEmpty(tree);
}