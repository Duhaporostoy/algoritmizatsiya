// bubble_sort.cpp
#include <iostream>
#include <vector>
#include <utility>  // ← Добавь эту строку! Здесь определён std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);  // ← используй std::swap
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void printFirstElements(const std::vector<int>& arr, int count = 20) {
    for (int i = 0; i < count && i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}