#include "pch.h"
#include "CppUnitTest.h"
#include "..//Расчет площади фигуры/Расчет площади фигуры.cpp"  // Укажи путь к своему файлу с кодом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMonteCarlo
{
    // Эмпирическое ожидаемое значение площади (приблизительно)
    const double expected_area = 2.0;

    TEST_CLASS(MonteCarloAreaTests)
    {
    public:

        // Чтобы получить повторяемые результаты, фиксируем сид
        void SeedRand()
        {
            srand(42);
        }

        TEST_METHOD(MonteCarlo_N_1000)
        {
            SeedRand();
            double result = monte_carlo_area_between_functions(4.0, 6.0, -1.5, 1.0, 1000);
            Assert::AreEqual(expected_area, result, 0.3, L"Area should be close to expected for N=1000");
        }

        TEST_METHOD(MonteCarlo_N_10000)
        {
            SeedRand();
            double result = monte_carlo_area_between_functions(4.0, 6.0, -1.5, 1.0, 10000);
            Assert::AreEqual(expected_area, result, 0.15, L"Area should be close to expected for N=10000");
        }

        TEST_METHOD(MonteCarlo_N_100000)
        {
            SeedRand();
            double result = monte_carlo_area_between_functions(4.0, 6.0, -1.5, 1.0, 100000);
            Assert::AreEqual(expected_area, result, 0.1, L"Area should be close to expected for N=100000");
        }

        TEST_METHOD(MonteCarlo_N_1000000)
        {
            SeedRand();
            double result = monte_carlo_area_between_functions(4.0, 6.0, -1.5, 1.0, 1000000);
            Assert::AreEqual(expected_area, result, 0.05, L"Area should be close to expected for N=1000000");
        }
    };
}
