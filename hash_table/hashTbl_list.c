////
//// Created by joan on 19-7-9.
////
//#include "malloc.h"
//#include "stdio.h"
//#include "hashTbl_list.h"
//#include "hash_function.h"
//
///*hash table with solving conflict using list*/
//
//#define MinTableSize 7
//typedef Position List;
//
//struct ListNode{
//    ElementType key;
//    Position next;
//};
//
//struct HashTbl{
//    int TableSize;
//    List *TheLists;     //list array (pointer array)
//};
//
//
///**
// * my hashtable init implement
// *
// * */
//HashTable InitTable(int TableSize)
//{
//    HashTable h = NULL;
//    int i=0;
//
//    if(TableSize < MinTableSize)
//    {
//        printf("TableSize is too Small!");
//        return NULL;
//    }
//
//    h = (HashTable) malloc( sizeof( struct HashTbl));
//    if(h != NULL)
//    {
//        h->TableSize = NextPrime(TableSize);
//        h->TheLists = (List*) malloc( h->TableSize * sizeof(List));
//        if(h->TheLists != NULL)
//        {
//            for(i=0; i< h->TableSize; i++)
//            {
//                h->TheLists[i] = (List)malloc(sizeof(struct ListNode));
//                if(h->TheLists[i] == NULL)
//                {
//                    printf("Error: out of space!\n");
//                    while(--i>=0)
//                    {
//                        free(h->TheLists[i]);
//                    }
//                    free(h);
//                    return NULL;
//                }else
//                    h->TheLists[i]->next = NULL;
//            }
//            return h;
//        }else{
//            printf("Error: out of space!\n");
//            free(h);
//            return NULL;
//        }
//
//    }else{
//        printf("Error: out of space!\n");
//        return NULL;
//    }
//
//}
//
//HashTable InitTable2(int TableSize)
//{
//    HashTable h;
//    int i=0;
//
//    if(TableSize < MinTableSize)
//    {
//        printf("Table size is too small!\n");
//        return NULL;
//    }
//
//    /*Allocate table*/
//    h = (HashTable) malloc( sizeof(struct HashTbl));
//    if(h == NULL)
//    {
//        printf("Error : out of space!");
//        return NULL;
//    }
//
//    h->TableSize = NextPrime(TableSize);
//
//
//    /*allocate list pointer array*/
//    h->TheLists = (List*) malloc( h->TableSize * sizeof(List));
//    if( h->TheLists == NULL)
//    {
//        printf("Error : out of space!");
//        free(h);
//        return NULL;
//    }
//
//    for(; i< h->TableSize; i++)
//    {
//        h->TheLists[i] = (List)malloc( sizeof(struct ListNode));
//        if( h->TheLists[i] == NULL)
//        {
//            printf("Error : out of space!");
//            while(--i>=0)
//                free(h->TheLists[i]);
//            free(h);
//            return NULL;
//        }else{
//            h->TheLists[i]->next = NULL;
//        }
//    }
//    return h;
//}
//
//
//void DestryTable(HashTable h)
//{
//    if(h != NULL)
//    {
//        /*free every list*/
//        for(int i=0; i< h->TableSize; i++)
//        {
//            Position head= h->TheLists[i];
//            Position temp;
//            while( head!= NULL)
//            {
//                temp = head->next;
//                free(head);
//                head = temp;
//            }
//        }
//        /*free list pointer array*/
//        free(h->TheLists);
//        /*free hash table struct*/
//        free(h);
//    }
//
//}
//
//Position Find(HashTable h, ElementType key)
//{
//    Position p;
//    List l;
//
//    l = h->TheLists[ Hash4(key, h->TableSize)];
//
//    p = l->next;    //assume list have head
//    while(p!= NULL && p->key != key)           //Probably need strcmp!(if key is string)
//        p = p->next;
//    return p;
//}
//
//
//void Insert(HashTable h, ElementType key)
//{
//    Position p;
//    List l;
//
//    p = Find(h, key);
//    if(p == NULL)           // key is not found
//    {
//
//        l = h->TheLists[ Hash4(key, h->TableSize)];
//
//        p = (List)malloc(sizeof(struct ListNode));
//        if(p != NULL)
//        {
//            p->next = l->next;
//            l->next = p;
//            p->key = key;               // probably need strcpy! ( if key is string)
//        }else
//        {
//            printf("Error: out of space!\n");
//        }
//    }
//}
//
//ElementType Retrieve(Position p)
//{
//    if(p != NULL)
//        return p->key;
//}
//
//
