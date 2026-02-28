// test_quick.cpp
#include "quick_sort.h"
#include "test_utils.h"
#include <iostream>
#include <vector>
#include <cassert>

void testQuickSort3Way() {
    std::cout << "\n🧪 Тесты для Quick Sort (3-way):\n";

    // Тест 1: обычный массив
    std::vector<int> arr1 = { 64, 34, 25, 12, 22, 11, 90 };
    quickSort3Way(arr1, 0, static_cast<int>(arr1.size()) - 1);
    assert(isSorted(arr1));
    std::cout << "✅ Тест 1: обычный массив — OK\n";

    // Тест 2: отсортированный
    std::vector<int> arr2 = { 1, 2, 3, 4, 5 };
    quickSort3Way(arr2, 0, static_cast<int>(arr2.size()) - 1);
    assert(isSorted(arr2));
    std::cout << "✅ Тест 2: отсортированный — OK\n";

    // Тест 3: обратный
    std::vector<int> arr3 = { 5, 4, 3, 2, 1 };
    quickSort3Way(arr3, 0, static_cast<int>(arr3.size()) - 1);
    assert(isSorted(arr3));
    std::cout << "✅ Тест 3: обратный — OK\n";

    // Тест 4: один элемент
    std::vector<int> arr4 = { 42 };
    quickSort3Way(arr4, 0, static_cast<int>(arr4.size()) - 1);
    assert(isSorted(arr4));
    std::cout << "✅ Тест 4: один элемент — OK\n";

    // Тест 5: пустой массив
    std::vector<int> arr5 = {};
    quickSort3Way(arr5, 0, -1);  // диапазон пустой
    assert(arr5.empty());
    std::cout << "✅ Тест 5: пустой массив — OK\n";

    std::cout << "🎉 Все тесты Quick Sort пройдены!\n";
}