#include <iostream>
#include <iomanip>
#include <chrono>

void radixSort(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int* output = new int[n];
        int count[10] = { 0 };

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        delete[] output;
    }
}

void printArr(int* arr, int n) {
    int show = n < 20 ? n : 20;
    for (int i = 0; i < show; i++)
        std::cout << arr[i] << " ";
    if (n > 20) std::cout << "... (ещё " << n - 20 << " эл.)";
    std::cout << "\n";
}

void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000000;
}

void copyArr(int* src, int* dst, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

int main() {
    srand((unsigned)time(0));

    // демонстрация на маленьком массиве
    int demo[] = { 1, 34, 11, 64, 42, 3, 7, 99 };
    int dn = 8;
    std::cout << "=== Демонстрация ===\n";
    std::cout << "Исходный:         ";
    printArr(demo, dn);
    radixSort(demo, dn);
    std::cout << "После сортировки: ";
    printArr(demo, dn);

    // таблица замеров
    int sizes[] = { 100, 1000, 10000, 100000, 500000, 1000000 };
    int numSizes = 6;

    std::cout << "\n=== Замеры времени ===\n";
    std::cout << std::setw(12) << "N"
        << std::setw(18) << "Radix (ms)" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (int s = 0; s < numSizes; s++) {
        int sz = sizes[s];
        int* base = new int[sz];
        int* arr = new int[sz];
        fillRandom(base, sz);
        copyArr(base, arr, sz);

        auto start = std::chrono::high_resolution_clock::now();
        radixSort(arr, sz);
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << std::setw(12) << sz
            << std::setw(18) << std::fixed << std::setprecision(4) << ms << "\n";

        delete[] base;
        delete[] arr;
    }

    // ручной ввод размера
    std::cout << "\n=== Свой размер массива ===\n";
    std::cout << "Введите N: ";
    int n;
    std::cin >> n;

    int* base = new int[n];
    int* arr = new int[n];
    fillRandom(base, n);
    copyArr(base, arr, n);

    std::cout << "Исходный (первые эл.): ";
    printArr(arr, n);

    auto start = std::chrono::high_resolution_clock::now();
    radixSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Отсортирован (первые эл.): ";
    printArr(arr, n);
    std::cout << "Время: " << std::fixed << std::setprecision(4) << ms << " ms\n";

    delete[] base;
    delete[] arr;

    system("pause");
    return 0;
}