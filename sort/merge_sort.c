//
// Created by joan on 19-8-4.
//

#include "merge_sort.h"
#include "malloc.h"


/**
 * 归并排序：先递归到最底层，然后从下往上每次两个序列进行归并合起来。
 * 　　　　　是一个由上往下分开，再由下往上合并的过程，而对于每一次合并操作，对于每一个merge的操作过程如下.
 *
 * Merge步骤：
 *         (1). 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
 *         (2). 设定两个指针，最初位置分别为两个已经排序序列的起始位置；
 *         (3). 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
 *         (4). 重复步骤3直到某一指针到达序列尾部。
 *         (5). 将另一序列剩下的所有元素直接复制到合并序列尾部。
*/

void Merge(ElementType arr[], ElementType tmpArr[], int lPos, int rPos, int rEnd)
{
    int i, leftEnd, numElements, tmpPos;
    leftEnd = rPos -1;
    tmpPos = lPos;
    numElements = rEnd -lPos + 1;

    /*main loop*/
    while(lPos <= leftEnd && rPos <= rEnd)
    {
        if(arr[lPos] <= arr[rPos])
            tmpArr[tmpPos++] = arr[lPos++];
        else
            tmpArr[tmpPos++] = arr[rPos++];
    }

    while(lPos <= leftEnd)      /*copy rest of left half*/
        tmpArr[tmpPos++] = arr[lPos++];

    while(rPos <= rEnd)         /*copy rest of right half*/
        tmpArr[tmpPos++] = arr[rPos++];

    /*copy tmpArr back*/
    for(int i=0; i < numElements; i++, rEnd--)
    {
        arr[rEnd] = tmpArr[rEnd];
    }
}


void mSort(ElementType arr[], ElementType tmpArr[], int left, int right)
{
    int mid = (left+right)/2;
    if(left < right)
    {
        mSort(arr, tmpArr, left, mid);  //左边
        mSort(arr, tmpArr, mid+1, right); //右边
        Merge(arr, tmpArr, left, mid+1, right);
    }
}


void merge_sort(ElementType arr[], int n)
{
    ElementType *tmpArr;
    tmpArr = (ElementType*)malloc( n * sizeof(ElementType));

    if(tmpArr != NULL)
    {
        mSort(arr, tmpArr, 0, n-1);
        free(tmpArr);
    }else
        printf("Error: out of space!");
}



/**
 *
 * 第二种优化写法：
 *
*/

void merge2(int arr[], int left, int mid, int rightEnd);
void mergeProcess(int arr[], int left, int right);

void merge_sort2(int arr[], int n)
{
    if(arr == NULL || n <= 1)
        return;
    mergeProcess(arr, 0, n-1);
}


void mergeProcess(int arr[], int left, int right)
{
    if(left >= right)    //递归结束条件判断
        return;
//    int mid = (left + right)/2;
    int mid = (left+right) >> 1;

    //left half
    mergeProcess(arr, left, mid);
    //right half
    mergeProcess(arr, mid+1, right);

    //merge
    if(arr[mid] > arr[mid+1])
        merge2(arr, left, mid, right);
}


void merge2(int arr[], int left, int mid, int rightEnd)
{
    int leftEnd = mid;
    int rightBegin = mid+1;
    int numElem = rightEnd - left +1;

    ElementType *tmpArr = (ElementType *)malloc( numElem * sizeof(ElementType) );
    int tmpPos=0;
    if(tmpArr == NULL)
    {
        printf("Error: out of space!");
        return;
    }

    /**/
    while(left <= leftEnd && rightBegin <= rightEnd)
    {
        if(arr[left] < arr[rightBegin])
            tmpArr[tmpPos++] = arr[left++];
        else
            tmpArr[tmpPos++] = arr[rightBegin++];
    }

    /*the rest of left half*/
    while(left <= leftEnd)
        tmpArr[tmpPos++] = arr[left++];

    /*the rest of right half*/
    while( rightBegin <= rightEnd)
        tmpArr[tmpPos++] = arr[rightBegin++];

    /*copy back to arr*/
    for(numElem-=1; numElem>=0; numElem--, rightEnd--)      //注意数组下标
    {
        arr[rightEnd] = tmpArr[numElem];
    }

    free(tmpArr);
}



