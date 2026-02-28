#include <iostream>
#include <stack>
#include <chrono>

bool searchInStack(std::stack<int> stack, int target) {
    while (!stack.empty()) {
        if (stack.top() == target) {
            return true;
        }
        stack.pop();
    }
    return false;
}


void evaluateComplexity(std::stack<int> stack, int target) {
    auto start = std::chrono::high_resolution_clock::now();
    bool found = searchInStack(stack, target);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Элемент " << (found ? "найден" : "не найден") << " в стеке." << std::endl;
    std::cout << "Время выполнения: " << elapsed.count() << " секунд." << std::endl;

    size_t memoryUsage = sizeof(stack) + stack.size() * sizeof(int);
    std::cout << "Использование памяти: " << memoryUsage << " байт." << std::endl;
}

int main() {
    std::stack<int> stack;

    
    for (int i = 0; i <10000000; ++i) {
        stack.push(i);
    }

    int target = 1;
    evaluateComplexity(stack, target);

    return 0;

}
