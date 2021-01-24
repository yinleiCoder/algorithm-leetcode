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

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("选择排序", selectionSort, arr, n);

    delete[] arr;


    return 0;
}
