
#include "stdio.h"
//#include "insert_sort.h"

//int main() {
//
//    int a[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
//    InsertSort(a, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", a[i]);
//    }
//
//    printf("\n");
//    int arr[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
//    InsertSort2(arr, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", a[i]);
//    }
//}

//#include "shell_sort.h"
//int main() {
//
//    int a[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
//    shell_sort(a, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", a[i]);
//    }
//}

#include "heap_sort.h"
int main(int argc, char* argv[])
{
    int a[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
    heap_sort(a, 9);
    for(int i=0; i<9; i++)
    {
        printf("%d ,\t ", a[i]);
    }

    printf("\n ");
    int arr[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
    HearSort(arr, 9);
    for(int i=0; i<9; i++)
    {
        printf("%d ,\t ", arr[i]);
    }
}