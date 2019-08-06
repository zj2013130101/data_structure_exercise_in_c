////
//// Created by joan on 19-8-4.
////
//
//#include "bubble_sort.h"
//
//
///*
// * 冒泡排序:每次冒泡就会将一个大的数往后面冒，从而达到目的。
// *    步骤：
// *     　 (1). 进行 n-1 次排序；
// *        (2). 每次排序从 0 ~ n-1-i (i是次数编号),检查这个序列中两两相邻的数，
// *        如果前面的数大于后面的数就将它们交换，这样使得大的数往后面走；
// *
// *
// */
//
//void swap(int *a, int *b)
//{
//    int tmp;
//    tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//
//void bubble_sort(int arr[], int len)
//{
//
//    int i, j;
//    for(i = 0; i < len; i++)                   //n-1次排序
//    {
//        for(j = 0; j < len-i-1; j++)          //因为下面是：比较j和j+1，所有这里需要减一；不然数组会溢出
//        {
//            if(arr[j] > arr[j+1])
//                swap(&arr[j], &arr[j+1]);
//        }
//    }
//}
//
//
//
///**
// *
// * 优化１：加入bool变量，判断当前子序列是否有序。
// *      (1)如果当前子序列，一次交换都没有发生，则为有序。此时说明整个序列是有序的。
// *
//*/
//
//void bubble_sort2(int arr[], int len)
//{
//    int i, j;
//    int isSorted = 1;
//    for(i = len-1; i > 0; i--)         //n-1次排序
//    {
//        isSorted = 1;
//        for(j=0; j < i; j++)
//        {
//            if(arr[j] > arr[j+1])
//            {
//                swap(&arr[j], &arr[j+1]);
//                isSorted = 0;
//            }
//        }
//        if(isSorted == 1)            //子序列已经是有序的，则整个序列有序，退出循环
//            break;
//    }
//}
//
//
///**
// * 优化2：记录上一次最后交换的那个位置，下一轮交换只需要进行到这个位置即可。
// * 　　　(1)最后一个交换位置后的序列，为以序序列，所以无需再排序。
// *
// */
//
//void bubble_sort3(int arr[], int len)
//{
//    int i, j;
//    for( i = len-1; i > 0; i--)
//    {
//        int border = 0;
//        for(j=0; j < i; j++)
//        {
//            if(arr[j] < arr[j+1])
//            {
//                swap(&arr[j], &arr[j+1]);
//                border = j+1;
//            }
//        }
//        i = border;             //当border为0时，说明当前子序列没有进行过交换，即当前子序列是以序的，所以全部序列以序
//    }
//}
//
