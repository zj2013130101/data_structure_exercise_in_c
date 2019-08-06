//
// Created by Joan on 2019/7/16.
//

#include "quick_sort.h"
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


/**
 * 快排：像归并排序一样，快排也是一种分治的递归算法。
 *
 * 算法步骤如下：
 *         (1). 如果S中元素个数是0或1，则返回；
 *         (2). 取S中任一个元素v，称之为枢纽元(pivot);
 *         (3). 将 s-{v}（S中其余元素）分成两个不相交的集合：S1和 S2；其中S1中的所有元素小于v，S2中的所有元素大于v；
 *         (4). 对S1和S2，重复进行上面三步。
 *
 *  两个主要地方：
 *  　　　　(a)选取枢纽元；——解决每次选择到最小或最大元素，从而导致划分不均匀问题；
 *  　　　　(b)分割策略；——解决重复元素多，从而导致划分不均匀问题；
 */


/**
 * 枢纽元选取策略１：每次都选取第一个元素为枢纽元，进行子问题划分
 */
void quickProcess1(int arr[], int left, int right);
int partition1(int arr[], int left, int right);

void quickSort1(ElementType arr[], int n)
{
    quickProcess1(arr, 0, n-1);

}


void quickProcess1(int arr[], int left, int right)
{
    if(left >= right)   //递归结束条件
        return;
    int p = partition1(arr, left, right);   //枢纽元位于划分子序列S1和S2的分界处
    quickProcess1(arr, left, p-1);
    quickProcess1(arr, p+1, right);
}


/**
 * 对 arr[l->r]部分进行partition操作，返回p。使得arr[L -> p-1] < arr[p]; arr[p+1 -> r] > arr[p]
 * @param arr
 * @param left
 * @param right
 * @return
 */
int partition1(int arr[], int left, int right)
{
    int key = arr[left];         //直接选取 arr[L] 作为枢纽元privot（中心点）
    int pivot = left;
    for(int i= left+1; i <= right; i++)
    {
        if(arr[i] < key)
            swap(&arr[i], &arr[++pivot]);
    }
    swap(&arr[pivot], &arr[left]);    //将arr[left]放到pivot位置(中间)，完全按照arr[left]划分数组的目的
    return pivot;
}


/**
 * 枢纽元选取策略2：每次都随机选取一个元素作为枢纽元。
 */
void quickProcess2(int arr[], int left, int right);

void quickSort2(ElementType arr[], int n)
{
    if(arr == NULL || n <=1)
        return;
    quickProcess2(arr,0, n-1);
}


/**
 * 改进枢纽元选取策略：随机选取
 * @param arr
 * @param left
 * @param right
 */
void quickProcess2(int arr[], int left, int right)
{
    if(left >= right)       //递归结束条件
        return;

    int elemNum = right -left +1;
    int rPos = left + random()%(elemNum);
    swap(&arr[left], &arr[rPos]);               //随机选取一个元素作为枢纽元和Left交换位置，在partition1()中以Left为当前枢纽元
    int p = partition1(arr, left, right);

    quickProcess2(arr, left, p-1);
    quickProcess2(arr, p+1, right);
}



/**
 * 策略3：解决重复元素多，导致划分不均衡问题。运用两个指针
 */
void quickProcess3(int arr[], int left, int right);
int partition3(int arr[], int left, int right);

void quickSort3(ElementType arr[], int n)
{
    if(arr == NULL || n <= 1)
        return;
    quickProcess3(arr, 0, n-1);
}

void quickProcess3(int arr[], int left, int right)
{
    if(left >= right)   //递归结束条件
        return;
    int elemNum = right - left +1;
    int rPos = left + random()%elemNum;
    swap(&arr[left], &arr[rPos]);

    int p = partition3(arr, left, right);       //枢纽元还是采取策略2的随机选取策略
    quickProcess3(arr, left, p-1);
    quickProcess3(arr, p+1, right);
}

/**
 * 改进划分策略：采用双指针，解决重复元素多的问题
 * @param arr
 * @param left
 * @param right
 * @return
 */
int partition3(int arr[], int left, int right)
{
    int key = arr[left];                //枢纽元
    int less = left+1, more = right;    //两个位置指针

    while(1)
    {
        while(less < right && arr[less] < key) less++;
        while(more > left && arr[more] > key) more--;
        if(less >= more)                //指针相等时，退出
            break;
        swap(&arr[less++], &arr[more--]);
    }
    /*将left放到中间*/
    swap(&arr[left], &arr[more]);
    return more;
}


