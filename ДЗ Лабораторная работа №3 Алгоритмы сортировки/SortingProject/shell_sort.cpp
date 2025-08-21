// shell_sort.cpp
#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    int step = n / 2;

    while (step > 0) {
        for (int i = step; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= step && arr[j - step] > temp) {
                arr[j] = arr[j - step];
                j -= step;
            }

            arr[j] = temp;
        }
        step /= 2;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}