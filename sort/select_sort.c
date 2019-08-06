////
//// Created by joan on 19-8-4.
////
//
//#include "select_sort.h"
//#include <stdio.h>
//
///**
// *　选择排序:
// *        (1). 在序列中找到最小元素，放到序列的起始位置作为已排序序列；
// *        (2). 再从剩余未排序元素中继续寻找最小(最大)元素，放到已排序序列的末尾
// */
//
//
///**
// * 该函数不能使用在，同一个地址上：否则会导致得到的数为恒０
// * @param a
// * @param b
// */
//void swap(int *a, int *b)
//{
//    *a = *a ^ *b;           //抑或操作，无需辅助空间
//    *b = *a ^ *b;
//    *a = *a ^ *b;
//}
//
//
//void swap2(int *a, int *b)
//{
//    int tmp;
//    tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//void select_sort(int arr[], int len)
//{
//    int i, j;
//    for(i = 0; i < len; i++)
//    {
//        for(j=i+1; j < len; j++)
//        {
//            if(arr[i] > arr[j])
//            {
//                swap(&arr[i], &arr[j]);
//            }
//        }
//    }
//}
//
//
///**
// * 写法(2)
// */
//
//void select_sort2(int arr[], int len)
//{
//
//    int i, j;
//    for(i = 0; i < len; i++) {
//        int minIdx = i;                         //记录子序列最小值的元素下标
//        for (j = i + 1; j < len; j++)
//        {
//            minIdx = arr[j] < arr[minIdx] ? j : minIdx;
//        }
////        printf("i : %d, minIdx : %d, val: %d\n", i, minIdx, arr[minIdx]);
//        swap2(&arr[i], &arr[minIdx]);
//    }
//}
