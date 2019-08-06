//
// Created by Joan on 2019/7/16.
//

#include "shell_sort.h"

/**
 * 希尔排序（增量排序）：通过比较相距一定间隔的元素来工作；
 *                      各趟比较所有的距离随着算法的进行而减小，直到只比较相邻元素的最后一趟排序为止。
 *
 *  每一趟增量排序：h(k)，对于h(k)，h(k+1)，...，N-1中的每一个位置i，把其上的元素放到i，i-h(k)，i-2h(k)...中的正确位置上
 * @param arr
 * @param N
 */
void shell_sort(ElementType arr[], int N)
{
    int i, j, Increment;
    ElementType tmp;
    for( Increment = N/2; Increment > 0; Increment /=2)
    {
        for( i = Increment; i < N; i++)                 //类似于插入排序
        {
            tmp = arr[i];
            for( j=i; j >= Increment; j -= Increment)   //每一趟只排序arr[Increment]，arr[2Increment]，arr[3Increment]
            {
                if(tmp < arr[ j - Increment])
                    arr[j] = arr[j-Increment];
                else
                    break;
            }
            arr[j] = tmp;
        }
    }
}


void shell_sort2(ElementType arr[], int N)
{

}