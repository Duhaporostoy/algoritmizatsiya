// test_bubble.cpp
#include "bubble_sort.h"
#include "test_utils.h"
#include <iostream>
#include <vector>
#include <cassert>

void testBubbleSort() {
    std::cout << "\n🧪 Тесты для Bubble Sort:\n";

    // Тест 1: обычный массив
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr1);
    assert(isSorted(arr1));
    std::cout << "✅ Тест 1: обычный массив — OK\n";

    // Тест 2: отсортированный
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    bubbleSort(arr2);
    assert(isSorted(arr2));
    std::cout << "✅ Тест 2: отсортированный — OK\n";

    // Тест 3: обратный
    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    bubbleSort(arr3);
    assert(isSorted(arr3));
    std::cout << "✅ Тест 3: обратный — OK\n";

    // Тест 4: один элемент
    std::vector<int> arr4 = {7};
    bubbleSort(arr4);
    assert(isSorted(arr4));
    std::cout << "✅ Тест 4: один элемент — OK\n";

    // Тест 5: пустой
    std::vector<int> arr5 = {};
    bubbleSort(arr5);
    assert(arr5.empty());
    std::cout << "✅ Тест 5: пустой массив — OK\n";

    std::cout << "🎉 Все тесты Bubble Sort пройдены!\n";
}