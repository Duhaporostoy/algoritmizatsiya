#include <iostream>
#include <iomanip>
#include <chrono>

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
    int demo[] = { 1, 65, 12, 22, 31, 90, 3, 97 };
    int dn = 8;
    std::cout << " Демонстрация\n";
    std::cout << "Исходный:         ";
    printArr(demo, dn);
    quickSort(demo, 0, dn - 1);
    std::cout << "После сортировки: ";
    printArr(demo, dn);

    // таблица замеров
    int sizes[] = { 100, 1000, 10000, 100000, 500000, 1000000 };
    int numSizes = 6;

    std::cout << "\n Замеры времени \n";
    std::cout << std::setw(12) << "N"
        << std::setw(18) << "Quick (ms)" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (int s = 0; s < numSizes; s++) {
        int sz = sizes[s];
        int* base = new int[sz];
        int* arr = new int[sz];
        fillRandom(base, sz);
        copyArr(base, arr, sz);

        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, sz - 1);
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << std::setw(12) << sz
            << std::setw(18) << std::fixed << std::setprecision(4) << ms << "\n";

        delete[] base;
        delete[] arr;
    }

    // ручной ввод размера
    std::cout << "\n Свой размер массива \n";
    std::cout << "Введите N: ";
    int n;
    std::cin >> n;

    int* base = new int[n];
    int* arr = new int[n];
    fillRandom(base, n);
    copyArr(base, arr, n);

    std::cout << "Исходный : ";
    printArr(arr, n);

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Отсортирован: ";
    printArr(arr, n);
    std::cout << "Время: " << std::fixed << std::setprecision(4) << ms << " ms\n";

    delete[] base;
    delete[] arr;

    system("pause");
    return 0;
}