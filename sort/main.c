
//#include "stdio.h"
//#include "insert_sort.h"
//
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
//    int arr[] = {10, 14, 70, 35, 39, 12, 24, 46, 25};
//    InsertSort2(arr, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", arr[i]);
//    }
//
//
//    printf("\n");
//    int arr2[] = {10, 4, 7, 28, 39, 7, 24, 46, 25};
//    insert_sort3(arr2, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", arr2[i]);
//    }
//
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

//#include "heap_sort.h"
//int main(int argc, char* argv[])
//{
//    int a[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
//    heap_sort(a, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", a[i]);
//    }
//
//    printf("\n ");
//    int arr[] = {10, 4, 7, 28, 39, 1, 24, 46, 25};
//    HearSort(arr, 9);
//    for(int i=0; i<9; i++)
//    {
//        printf("%d ,\t ", arr[i]);
//    }
//}


//#include "bubble_sort.h"
//int main(int argc, char* argv[])
//{
//
//    int arr1[] = {100, 378, 9, 367, 12, 8, 52, 0, 1, 9};
//
//    bubble_sort(arr1, 10);
//    for(int i=0; i<10; i++)
//    {
//        printf("%d ,\t ", arr1[i]);
//    }
//
//
//    printf("\n ");
//    int arr2[] = {10, 4, 7, 28, 39, 1, 24, 46, 25, 1};
//    bubble_sort2(arr2, 10);
//    for(int i=0; i < 10; i++)
//    {
//        printf("%d ,\t ", arr2[i]);
//    }
//
//
//    printf("\n ");
//    int arr3[] = {10, 4, 7, 28, 39, 1, 24, 46, 25, 4};
//    bubble_sort2(arr3, 10);
//    for(int i=0; i< 10; i++)
//    {
//        printf("%d ,\t ", arr3[i]);
//    }
//
//    return 0;
//}


//#include "select_sort.h"
//
//int main(int argc, char* argv[])
//{
//    int arr1[] = {100, 378, 9, 367, 12, 8, 52, 0, 1, 9};
//
//    select_sort(arr1, 10);
//    for(int i=0; i<10; i++)
//    {
//        printf("%d ,\t ", arr1[i]);
//    }
//
//
//    printf("\n ");
//    int arr2[] = {10, 4, 7, 28, 39, 1, 24, 46, 25, 1};
//    select_sort2(arr2, 10);
//    for(int i=0; i < 10; i++)
//    {
//        printf("%d ,\t ", arr2[i]);
//    }
//
//    return 0;
//}



//#include "merge_sort.h"
//#include <stdio.h>
//
//int main(int argc, char* argv[])
//{
//    int arr1[] = {100, 378, 9, 367, 12, 8, 52, 12, 1, 9};
//
//    merge_sort(arr1, 10);
//    for(int i=0; i<10; i++)
//    {
//        printf("%d ,\t ", arr1[i]);
//    }
//
//    printf("\n ");
//    int arr2[] = {100, 378, 9, 367, 12, 8, 52, 12, 1, 9};
//    merge_sort2(arr2, 10);
//    for(int i=0; i<10; i++)
//    {
//        printf("%d ,\t ", arr2[i]);
//    }
//}



#include "quick_sort.h"
#include "stdio.h"

int main(int argc, char* argv[])
{

    int arr1[] = {100, 378, 9, 367, 12, 8, 52, 12, 1, 9};

    quickSort1(arr1, 10);
    for(int i=0; i<10; i++)
    {
        printf("%d ,\t ", arr1[i]);
    }


    printf("\n ");
    int arr2[] = {100, 378, 9, 367, 12, 8, 52, 0, 1, 9};
    quickSort2(arr2, 10);
    for(int i=0; i<10; i++)
    {
        printf("%d ,\t ", arr2[i]);
    }


    printf("\n ");
    int arr3[] = {100, 378, 9, 367, 12, 8, 52, 0, 1, 9};
    quickSort2(arr3, 10);
    for(int i=0; i<10; i++)
    {
        printf("%d ,\t ", arr3[i]);
    }

    return 0;
}