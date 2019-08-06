//#include "stdio.h"
//
///**
// *
// * 已排序的数组(降序排列)，给定输入元素，二分查找该元素下标
// *
// * 输入：
// *      arr int[] ,
// *      element int,
// *      N: arr length
// *
// * 输出：
// *      int：element position
// * */
//
//#define Notfound -1
//
//int BinarySearch(int arr[], int element, int N)
//{
//    int low, mid, high;
//    low = 0;
//    high = N-1;
//    while(low <= high)
//    {
//        mid = (low + high)/2;
//        if(element > arr[mid] )
//        {
//            high  = mid -1;             //降序排列
//        }else if(element < arr[mid])
//        {
//            low = mid + 1;
//        }
//        else if(element == arr[mid])
//            return mid;
//    }
//    return Notfound;
//}
//
///**
// *
// * 欧几里得算法求两个整数的最大公因数（同时整除两数的的最大整数）
// *
// * input: m, n (m > n)
// *　
// * @return unsigned int
// */
//unsigned int gcd(unsigned int m, unsigned int n)
//{
//    unsigned int rem;
//    while(n > 0)
//    {
//      rem = m % n;      //求余数
//      m = n;
//      n = rem;
//    }
//    return m;
//}
//
///**
// *
// * 使用递归实现取幂运算，假设机器能够存储乘法结果的大整数
// *
// * x的n次方
// *
// *
// * @return
// */
//long int pow(int x, int n)
//{
//    if(n==0)
//        return 1;
//    if(n==1)
//        return x;
//    if(IsEven(n))               // n 为偶数
//        return pow(x*x, n/2);
//    else                        // n 为奇数
//        return pow(x*x, n/2)*x;
//}
//
//
//int main() {
//
////    int input[8] = {100, 89, 56, 39, 26, 12, 5, 1};
////
////    cout << BinarySearch(input, 56, 8) << endl;
//
////    cout << gcd(120, 16) << endl;
//
//}


#include "stdio.h"
#include <stdalign.h>

typedef struct _nums1{
    char a;
    short b;
    int c;
    double d;
} nums1;


typedef struct _nums2{
    int c;          //8
    double d;       //8
    char a;         //2
    short b;        //2
                    //4
} nums2;


typedef struct _test{
    char a;
    short b;
    int c;
    double d;
    char arr[13];
} test;


typedef struct _parent{
    int a;
    char b;
    short c;
}parent;


typedef struct _child{

    char a;
    int b;
    parent p;
    long c;
}child;


int main(void)
{
    printf("nums1 size: %lu\n", sizeof(nums1));
    printf("nums2 size: %lu\n", sizeof(nums2));
    printf("test size : %lu\n", sizeof(test));
    printf("child size : %lu\n", sizeof(child));


    printf("alignof(nums1) size: %lu\n", alignof(nums1));
    printf("alignof(nums2) size: %lu\n", alignof(nums2));
    printf("alignof(test) size : %lu\n", alignof(test));
    printf("alignof(child) size : %lu\n", alignof(child));

    return 0;
}