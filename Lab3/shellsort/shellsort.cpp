#include <iostream>
#include <vector>
#include <random>
#include <chrono>

// Функция сортировки Шелла
void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    const int n = 2000; // ←←← ЗАДАЙТЕ ЖЕЛАЕМОЕ КОЛИЧЕСТВО ЭЛЕМЕНТОВ ЗДЕСЬ

    if (n <= 0) {
        std::cerr << "Количество элементов должно быть положительным.\n";
        return 1;
    }

    // Генератор случайных чисел
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(1, 1000);

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }

    std::cout << "Исходный массив:\n";
    
        printArray(arr);
    

    shellSort(arr);

    std::cout << "Отсортированный массив:\n";
        printArray(arr);
    

    return 0;
}