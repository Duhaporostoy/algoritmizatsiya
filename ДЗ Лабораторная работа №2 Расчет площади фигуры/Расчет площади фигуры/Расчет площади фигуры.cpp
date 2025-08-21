#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

double f1(double x) {
    return std::sin(x);
}

double f2(double x) {
    return std::sin(0.5 * x) - 0.5;
}

double monte_carlo_area_between_functions(double x_min, double x_max, double y_min, double y_max, int num_points) {
    int inside_points = 0;

    for (int i = 0; i < num_points; ++i) {
        double x = ((double)rand() / RAND_MAX) * (x_max - x_min) + x_min;
        double y = ((double)rand() / RAND_MAX) * (y_max - y_min) + y_min;

        double top = f1(x);
        double bottom = f2(x);
        if (top < bottom) std::swap(top, bottom);

        if (y >= bottom && y <= top) {
            inside_points++;
        }
    }

    double rectangle_area = (x_max - x_min) * (y_max - y_min);
    double estimated_area = (inside_points / (double)num_points) * rectangle_area;
    return estimated_area;
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    double x_min = 4.0;
    double x_max = 6.0;
    double y_min = -1.5;
    double y_max = 1.0;
    int num_points = 100000;
    double estimated_area = monte_carlo_area_between_functions(x_min, x_max, y_min, y_max, num_points);
    std::cout << " площадь ровна===== " << estimated_area << std::endl;

    return 0;
}
