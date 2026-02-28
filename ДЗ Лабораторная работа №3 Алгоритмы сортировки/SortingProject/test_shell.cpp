// test_shell.cpp
#include "shell_sort.h"
#include "test_utils.h"
#include <iostream>
#include <vector>
#include <cassert>

void testShellSort() {
    std::cout << "\n🧪 Тесты для Shell Sort:\n";

    // Тест 1: обычный случай
    std::vector<int> arr1 = { 64, 34, 25, 12, 22, 11, 90 };
    shellSort(arr1);
    assert(isSorted(arr1));
    std::cout << "✅ Тест 1: обычный массив — OK\n";

    // Тест 2: уже отсортированный
    std::vector<int> arr2 = { 1, 2, 3, 4, 5 };
    shellSort(arr2);
    assert(isSorted(arr2));
    std::cout << "✅ Тест 2: отсортированный массив — OK\n";

    // Тест 3: обратный порядок
    std::vector<int> arr3 = { 5, 4, 3, 2, 1 };
    shellSort(arr3);
    assert(isSorted(arr3));
    std::cout << "✅ Тест 3: обратный порядок — OK\n";

    // Тест 4: один элемент
    std::vector<int> arr4 = { 42 };
    shellSort(arr4);
    assert(isSorted(arr4));
    std::cout << "✅ Тест 4: один элемент — OK\n";

    // Тест 5: пустой массив
    std::vector<int> arr5 = {};
    shellSort(arr5);
    assert(arr5.empty());
    std::cout << "✅ Тест 5: пустой массив — OK\n";

    std::cout << "🎉 Все тесты Shell Sort пройдены!\n";
}