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
    int demo[] = { 64, 25, 12, 22, 11, 90, 3, 47 };
    int dn = 8;
    std::cout << "=== Демонстрация ===\n";
    std::cout << "Исходный:    ";
    printArr(demo, dn);

    int tmp[8];
    for (int i = 0; i < dn; i++) tmp[i] = demo[i];
    radixSort(tmp, dn);
    std::cout << "Поразрядная: ";
    printArr(tmp, dn);

    for (int i = 0; i < dn; i++) tmp[i] = demo[i];
    shellSort(tmp, dn);
    std::cout << "Шелла:       ";
    printArr(tmp, dn);

    for (int i = 0; i < dn; i++) tmp[i] = demo[i];
    quickSort(tmp, 0, dn - 1);
    std::cout << "Быстрая:     ";
    printArr(tmp, dn);

    // таблица замеров
    int sizes[] = { 100, 1000, 10000, 100000, 500000, 1000000 };
    int numSizes = 6;

    std::cout << "\n=== Замеры времени ===\n";
    std::cout << std::setw(12) << "N"
        << std::setw(16) << "Radix (ms)"
        << std::setw(16) << "Shell (ms)"
        << std::setw(16) << "Quick (ms)" << "\n";
    std::cout << std::string(60, '-') << "\n";

    for (int s = 0; s < numSizes; s++) {
        int sz = sizes[s];
        int* base = new int[sz];
        int* arr = new int[sz];
        fillRandom(base, sz);

        copyArr(base, arr, sz);
        auto t1s = std::chrono::high_resolution_clock::now();
        radixSort(arr, sz);
        auto t1e = std::chrono::high_resolution_clock::now();
        double radixMs = std::chrono::duration<double, std::milli>(t1e - t1s).count();

        copyArr(base, arr, sz);
        auto t2s = std::chrono::high_resolution_clock::now();
        shellSort(arr, sz);
        auto t2e = std::chrono::high_resolution_clock::now();
        double shellMs = std::chrono::duration<double, std::milli>(t2e - t2s).count();

        copyArr(base, arr, sz);
        auto t3s = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, sz - 1);
        auto t3e = std::chrono::high_resolution_clock::now();
        double quickMs = std::chrono::duration<double, std::milli>(t3e - t3s).count();

        std::cout << std::setw(12) << sz
            << std::setw(16) << std::fixed << std::setprecision(4) << radixMs
            << std::setw(16) << shellMs
            << std::setw(16) << quickMs << "\n";

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
    auto t1s = std::chrono::high_resolution_clock::now();
    radixSort(arr, n);
    auto t1e = std::chrono::high_resolution_clock::now();
    std::cout << "Radix время: " << std::fixed << std::setprecision(4)
        << std::chrono::duration<double, std::milli>(t1e - t1s).count() << " ms\n";

    copyArr(base, arr, n);
    auto t2s = std::chrono::high_resolution_clock::now();
    shellSort(arr, n);
    auto t2e = std::chrono::high_resolution_clock::now();
    std::cout << "Shell время: " << std::fixed << std::setprecision(4)
        << std::chrono::duration<double, std::milli>(t2e - t2s).count() << " ms\n";

    copyArr(base, arr, n);
    auto t3s = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto t3e = std::chrono::high_resolution_clock::now();
    std::cout << "Quick время: " << std::fixed << std::setprecision(4)
        << std::chrono::duration<double, std::milli>(t3e - t3s).count() << " ms\n";

    delete[] base;
    delete[] arr;

    system("pause");
    return 0;
}