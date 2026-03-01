#include <iostream>
#include <chrono>

// ======= копии сортировок =======

void radixSort(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int* output = new int[n];
        int count[10] = { 0 };
        for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) arr[i] = output[i];
        delete[] output;
    }
}

void shellSort(int* arr, int n) {
    int step = n / 2;
    while (step > 0) {
        for (int i = step; i < n; i++) {
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

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ================================

int testsRun = 0;
int testsPassed = 0;

bool isSorted(int* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

void assertEqual(bool condition, const char* name) {
    testsRun++;
    if (condition) {
        testsPassed++;
        std::cout << "[PASS] " << name << "\n";
    }
    else {
        std::cout << "[FAIL] " << name << "\n";
    }
}

void testRadix() {
    int a1[] = { 5, 3, 8, 1, 9, 2 };
    radixSort(a1, 6);
    assertEqual(isSorted(a1, 6), "Radix: обычный массив");

    int a2[] = { 1 };
    radixSort(a2, 1);
    assertEqual(isSorted(a2, 1), "Radix: один элемент");

    int a3[] = { 1, 2, 3, 4, 5 };
    radixSort(a3, 5);
    assertEqual(isSorted(a3, 5), "Radix: уже отсортирован");

    int a4[] = { 5, 4, 3, 2, 1 };
    radixSort(a4, 5);
    assertEqual(isSorted(a4, 5), "Radix: обратный порядок");

    int a5[] = { 3, 3, 3, 3 };
    radixSort(a5, 4);
    assertEqual(isSorted(a5, 4), "Radix: все одинаковые");

    int a6[] = { 1000, 1, 500, 23, 9999 };
    radixSort(a6, 5);
    assertEqual(isSorted(a6, 5), "Radix: разные разряды");
}

void testShell() {
    int a1[] = { 5, 3, 8, 1, 9, 2 };
    shellSort(a1, 6);
    assertEqual(isSorted(a1, 6), "Shell: обычный массив");

    int a2[] = { 42 };
    shellSort(a2, 1);
    assertEqual(isSorted(a2, 1), "Shell: один элемент");

    int a3[] = { 1, 2, 3, 4, 5 };
    shellSort(a3, 5);
    assertEqual(isSorted(a3, 5), "Shell: уже отсортирован");

    int a4[] = { 9, 7, 5, 3, 1 };
    shellSort(a4, 5);
    assertEqual(isSorted(a4, 5), "Shell: обратный порядок");

    int a5[] = { 7, 7, 7 };
    shellSort(a5, 3);
    assertEqual(isSorted(a5, 3), "Shell: все одинаковые");
}

void testQuick() {
    int a1[] = { 5, 3, 8, 1, 9, 2 };
    quickSort(a1, 0, 5);
    assertEqual(isSorted(a1, 6), "Quick: обычный массив");

    int a2[] = { 99 };
    quickSort(a2, 0, 0);
    assertEqual(isSorted(a2, 1), "Quick: один элемент");

    int a3[] = { 1, 2, 3, 4, 5 };
    quickSort(a3, 0, 4);
    assertEqual(isSorted(a3, 5), "Quick: уже отсортирован");

    int a4[] = { 10, 8, 6, 4, 2 };
    quickSort(a4, 0, 4);
    assertEqual(isSorted(a4, 5), "Quick: обратный порядок");

    int a5[] = { 2, 2, 2, 2 };
    quickSort(a5, 0, 3);
    assertEqual(isSorted(a5, 4), "Quick: все одинаковые");

    int a6[] = { 3, 1 };
    quickSort(a6, 0, 1);
    assertEqual(isSorted(a6, 2), "Quick: два элемента");
}

int main() {
    std::cout << "=== Тесты: Поразрядная сортировка ===\n";
    testRadix();

    std::cout << "\n=== Тесты: Сортировка Шелла ===\n";
    testShell();

    std::cout << "\n=== Тесты: Быстрая сортировка ===\n";
    testQuick();

    std::cout << "\nПройдено: " << testsPassed << " / " << testsRun << "\n";

    system("pause");
    return 0;
}