// main.cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "shell_sort.h"
#include "bubble_sort.h"
#include "quick_sort.h"

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0));

    cout << "Выберите сортировку:\n";
    cout << "1. Shell Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Quick Sort (3-way)\n";
    cout << "Введите номер: ";

    int choice;
    cin >> choice;

    const int N = 20;
    const int RANGE = 100;
    vector<int> arr;

    // Заполняем случайными числами
    for (int i = 0; i < N; ++i) {
        arr.push_back(rand() % RANGE + 1);
    }

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    switch (choice) {
    case 1: {
        cout << "\nShell Sort\n";
        cout << "Original: ";
        printArray(arr);

        start = high_resolution_clock::now();
        shellSort(arr);
        end = high_resolution_clock::now();

        cout << "Sorted: ";
        printArray(arr);
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms\n";
        break;
    }

    case 2: {
        cout << "\nBubble Sort\n";
        cout << "Original (first 20): ";
        printFirstElements(arr);

        start = high_resolution_clock::now();
        bubbleSort(arr);
        end = high_resolution_clock::now();

        cout << "Sorted (first 20): ";
        printFirstElements(arr);
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms\n";
        break;
    }

    case 3: {
        cout << "\nQuick Sort (3-way)\n";
        cout << "Original: ";
        printQuickArray(arr);

        start = high_resolution_clock::now();
        quickSort3Way(arr, 0, arr.size() - 1);
        end = high_resolution_clock::now();

        cout << "Sorted: ";
        printQuickArray(arr);
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms\n";
        break;
    }

    default:
        cout << "Неверный выбор!\n";
    }

    // Пауза, чтобы окно не закрылось
    cout << "\nНажмите Enter для выхода...";
    cin.get();
    cin.get();

    return 0;
}