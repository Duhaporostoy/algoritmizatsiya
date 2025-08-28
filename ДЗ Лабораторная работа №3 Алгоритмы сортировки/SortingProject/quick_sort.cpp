// quick_sort.cpp
#include <iostream>
#include <vector>

void quickSort3Way(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int randomIndex = low + rand() % (high - low + 1);
    int pivot = arr[randomIndex];
    std::swap(arr[randomIndex], arr[low]);

    int lt = low;
    int gt = high;
    int i = low + 1;

    while (i <= gt) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[lt]);
            i++;
            lt++;
        }
        else if (arr[i] > pivot) {
            std::swap(arr[i], arr[gt]);
            gt--;
        }
        else {
            i++;
        }
    }

    quickSort3Way(arr, low, lt - 1);
    quickSort3Way(arr, gt + 1, high);
}

void printQuickArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}