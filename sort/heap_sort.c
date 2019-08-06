////
//// Created by Joan on 2019/7/16.
////
//
//#include "heap_sort.h"
//#include <malloc.h>
//#include <memory.h>
//#include <stdio.h>
//
//void locateDown(ElementType arr[], int N , int pos);
//void buildHeap(ElementType arr[], int N);
//void printArr(ElementType arr[], int N);
//
///**
// * (二叉)堆排序： 二叉堆（完全二叉树-数组存放）
// *              (1)升序排序：建立最小堆(BuildHeap-O(N))，不断删除最小元素(DeleteMin-O(NlogN))；
// *              (2)降序排序：建立最大堆(BuildHeap-O(N))，不断删除最大元素(DeleteMax-O(NlogN))；
// * @param arr
// * @param N
// */
//void heap_sort(ElementType arr[], int N)
//{
//    ElementType* tmp = (ElementType*)malloc((N+1) * sizeof(ElementType));
//    memcpy(tmp+1, arr, N * sizeof(ElementType));    //数组tmp的位置0，空出来不用
//    buildHeap(tmp, N);
//    printArr(tmp, N+1);
//    for(int i=0; i < N; i++)
//    {
//        arr[i] = tmp[1];
//        tmp[1] = tmp[N-i];          //删除堆顶元素（将最后一个元素交换到第一个元素，进行下滤操作）
//        locateDown(tmp, N-i-1, 1);  //将第一个元素进行下滤，注意剩下的堆数组长度
//    }
//    free(tmp);
//}
//
///**
// * 构建堆（完全二叉树）：从倒数第二层开始（依次往上进行到根节点），对每一个节点进行下滤操作。
// *      下滤操作：依次找到儿子节点中的较小者(类似递归)，进行交换，直到该节点放入正确的位置（满足堆序）。
// * @param arr：数组位置0，空出来
// * @param N
// */
//void buildHeap(ElementType arr[], int N)
//{
//    for(int i = N/2; i > 0 ; i--)                       //完全二叉树倒数第二层为：N/2
//        locateDown(arr, N, i);
//}
//
//void locateDown(ElementType arr[], int N , int pos)
//{
//    ElementType tmp = arr[pos];
//    int child;
//    for(; pos*2 <= N; pos = child)
//    {
//        /*find the smaller child*/
//        child = pos*2;                                   //左节点
//        if( child <= N && arr[child] > arr[child+1])    //有些节点的子节点可能只有一个，所以需要判断：child <= N
//            child++;
//        if( tmp > arr[child])                           //最小堆
//            arr[pos] = arr[child];
//        else
//            break;
//    }
//    arr[pos] = tmp;                                       //放入正确位置
//}
//
//void printArr(ElementType arr[], int N)
//{
//    printf("Current Arr: \n");
//    for(int i=0; i< N; i++)
//    {
//        printf("%d, \t", arr[i]);
//    }
//    printf("\n");
//}
//
///**
// * (二叉)堆排序： 在原始数组位置上排序
// */
//#define LeftChild(i) (2*(i) + 1)
//
//void swap(ElementType* val1, ElementType* val2)
//{
//    ElementType temp=0;
//    temp = *val1;
//    *val1 = *val2;
//    *val2 = temp;
//}
//
///**
// *  下滤操作：依次找到儿子节点中的较大者(类似递归)，进行交换，直到该节点放入正确的位置（满足堆序）。
// *  （最大堆）
// * @param arr：堆数组
// * @param pos：下滤元素位置
// * @param N：堆数组长度
// */
//void PerDown(ElementType arr[], int pos, int N)
//{
//    ElementType tmp = arr[pos];
//    int child;
//    for(; LeftChild(pos) <= N-1; pos = child)
//    {
//        /*find the bigger child*/
//        child = LeftChild(pos);
//        if( (child != N-1) && arr[child + 1] > arr[child])
//            child++;
//        if( tmp < arr[child])               //最大堆元素下滤
//            arr[pos] = arr[child];
//        else
//            break;
//    }
//    arr[pos] = tmp;
//}
//
//void HearSort(ElementType arr[], int N)
//{
//    int i=0;
//    for(i = N/2; i >=0; i--)  /*BuildHeap*/
//    {
//        PerDown(arr, i, N);
//    }
//
//    for(i = N-1; i > 0; i--)
//    {
//        swap(&arr[0], &arr[i]);  //使用原始数组存放排序结果
//        PerDown(arr, 0, i);      //不断删除最大堆第一个元素，放到数组最后
//    }
//}