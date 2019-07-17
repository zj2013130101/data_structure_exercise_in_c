
#include "stdio.h"
//#include "hashTbl_list.h"
#include "hashTbl_detect.h"


//int main() {
//    HashTable h = InitTable(21);
//    for(int i=0; i< 100; i++)
//    {
//        Insert(h, i*2+1);
//    }
//    Position  p = Find(h, 1);
//    if(p != NULL)
//    {
//        printf("Find: %d\n", Retrieve(p));
//    }else
//        printf("not found: 1!\n");
//
//    p = Find(h, 21);
//    if(p != NULL)
//    {
//        printf("Find: %d\n", Retrieve(p));
//    }else
//        printf("not found: 21!\n");
//
//    p = Find(h, 101);
//    if(p != NULL)
//    {
//        printf("Find: %d", Retrieve(p));
//    }else
//        printf("not found: 101!\n");
//
//    DestryTable(h);
//}

int main()
{
    HashTable h = InitHashTable(31);
    for(int i=0; i< 10; i++)
    {
        Insert(h, i*2+1);
    }

    Position  p = Find(h, 1);
    ElementType elem = Retrieve(h, p);
    if(elem != -1)
        printf("Find: 1!\n");
    else
        printf("not found: 1!\n");

    p = Find(h, 5);
    elem = Retrieve(h, p);
    if(elem != -1)
        printf("Find : 5!\n");
    else
        printf("not found: 5!\n");

    p = Find(h, 8);
    elem = Retrieve(h, p);
    if(elem != -1)
        printf("Find: 8!\n");
    else
        printf("not found: 8!\n");

    DestroyTable(h);
}