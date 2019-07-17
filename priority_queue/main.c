
#include "stdio.h"
#include "binary_heap.h"

int main() {

    int arr[] = {10, 17, 41, 50, 16, 7, 87, 45, 40, 3, 1, 56, 344};
    PriorityQueue queue = BuildHeap(arr, 13, 127);

    printf("Min: %d\n", FindMin(queue));
    DeleteMin(queue);
    printf("Min: %d\n", FindMin(queue));
    DeleteMin(queue);
    printf("Min: %d\n", FindMin(queue));
    DeleteMin(queue);
    printf("Min: %d\n", FindMin(queue));
    DeleteMin(queue);

    Insert(queue, 11);
    printf("Min: %d\n", FindMin(queue));
    DeleteMin(queue);
    Insert(queue, 1);
    printf("Min: %d\n", FindMin(queue));
    Insert(queue, 2);
    printf("Min: %d\n", FindMin(queue));

    Destroy(queue);
}