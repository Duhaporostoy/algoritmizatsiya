#include "pch.h"
#include <stack>
#include <chrono>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(StackSearchTest)
    {
    public:
        
        bool searchInStack(std::stack<int> stack, int target) {
            while (!stack.empty()) {
                if (stack.top() == target) {
                    return true;
                }
                stack.pop();
            }
            return false;
        }

        
        TEST_METHOD(ElementFound)
        {
            std::stack<int> stack;
            for (int i = 0; i < 10; ++i) {
                stack.push(i);
            }
            int target = 5;
            bool result = searchInStack(stack, target);
            Assert::IsTrue(result); 
        }

        
        TEST_METHOD(ElementNotFound)
        {
            std::stack<int> stack;
            for (int i = 0; i < 10; ++i) {
                stack.push(i);
            }
            int target = 15;
            bool result = searchInStack(stack, target);
            Assert::IsFalse(result); 
        }

        
        TEST_METHOD(EvaluateComplexity)
        {
            std::stack<int> stack;
            for (int i = 0; i < 1000000; ++i) {
                stack.push(i);
            }
            int target = 999999;
            auto start = std::chrono::high_resolution_clock::now();
            bool found = searchInStack(stack, target);
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = end - start;
            Logger::WriteMessage(("Элемент " + std::string(found ? "найден" : "не найден") + " в стеке.").c_str());
            Logger::WriteMessage(("Время выполнения: " + std::to_string(elapsed.count()) + " секунд.").c_str());

           
            size_t memoryUsage = sizeof(stack) + stack.size() * sizeof(int);
            Logger::WriteMessage(("Использование памяти: " + std::to_string(memoryUsage) + " байт.").c_str());

            Assert::IsTrue(found); 
        }
    };
}
