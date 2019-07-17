//
// Created by Joan on 2019/7/16.
//

#include "insert_sort.h"

/**
 * 插入排序：由N-1趟排序组成。对于P=1到P=N-1趟，保证从位置0到位置P上的元素为已排序状态。
 *          在第P趟，将位置P上的元素向左移动到它前P+1个元素中的正确位置上。
 *          （位置P上的元素存于tmp，而位置P之前的所有更大的元素向右移动一个位置，然后tmp被置于正确位置上。）
 * @param a
 * @param N
 */
void InsertSort(ElementType a[], int N)
{
    int j, p;
    ElementType tmp;
    for(p=1; p<N; p++)
    {
        tmp = a[p];
        for(j=p-1; j>=0;j--)
        {
            if(a[j]>tmp)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = tmp;
    }
}


void InsertSort2(ElementType arr[], int N)
{
    int j, p;
    ElementType tmp;
    for(p=1; p< N; p++)
    {
        tmp = arr[p];
        for( j = p; j>0 && arr[j-1] > tmp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}