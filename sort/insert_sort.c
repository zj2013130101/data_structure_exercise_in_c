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


/**
 *  改进：二分插入排序
 *       (1). 在前面已排好序的序列中找当前需要插入的元素的时候，采用二分查找的方式去找那个插入的位置(大于key的位置)
 *       (2). 找到那个位置之后，再进行元素的移动，以及把那个元素插入到找到的那个位置
*/


int binary_serach(int arr[], int left, int right)
{

}


void insert_sort3(int arr[], int len)
{
    int i, j;
    for(i = 1; i < len ; i++)
    {
        int key = arr[i];
        int left = 0;
        int right = i-1;
        int mid = 0;
        while( left <= right)
        {
            mid = (left + right)/2;
            if(arr[mid] < key)
            {
                left = mid + 1;
            }else if(arr[mid] > key)
            {
                right = mid - 1;
            }else
            {
                break;
            }
        }
        //二分结束之后　L= 刚好大于Key(不是等于)的那个位置
//        for(j = i -1; j > mid ; j--)
//            arr[j+1] = arr[j];
//        arr[mid + 1] = key;
        for(j= i-1; j >= left; j--)
            arr[j+1] = arr[j];
        arr[left] = key;
    }
}

















