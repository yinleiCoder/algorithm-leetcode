#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

/**
 * 选择排序：
 * 每轮找最小的元素放到前面
 * @param arr
 * @param n
 */
template<typename T>
void selectionSort(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        /// 寻找[i, n) 里的最小值
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

/**
 * 插入排序：
 * 当前元素往前插入，类似扑克牌一样
 * @param arr
 * @param n
 */
template<typename T>
void insertSort(T arr[], int n) {
    for(int i = 1; i < n; i++) {
        /// 寻找当前元素合适的插入位置
        T e = arr[i];
        int j;// 保存元素e应该插入的位置
        for(j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

int main() {
    int n = 10000;
//    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr = SortTestHelper::generatedNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("选择排序", selectionSort, arr, n);
    SortTestHelper::testSort("插入排序", insertSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}
