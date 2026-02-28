#include <iostream>
#include <cmath>
#include <iomanip>

const double A = 4.0;
const double B = 6.0;
double f1(double x) { return sin(x); }
double f2(double x) { return cos(x); }
double f3(double x) { return sin(0.5 * x) - 0.5; }

double upper(double x) { return fmin(f2(x), f3(x)); }
double lower(double x) { return f1(x); }

double integrand(double x) { return upper(x) - lower(x); }

double simpson(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++;
    double h = (b - a) / n;
    double s = f(a) + f(b);
    for (int i = 1; i < n; i += 2) s += 4 * f(a + i * h);
    for (int i = 2; i < n - 1; i += 2) s += 2 * f(a + i * h);
    return (h / 3) * s;
}

double monte_carlo(double a, double b, int n) {
    srand(42);
    double y_min = -1.0, y_max = 0.5;
    double rect = (b - a) * (y_max - y_min);
    int hits = 0;
    for (int i = 0; i < n; i++) {
        double x = a + (double)rand() / RAND_MAX * (b - a);
        double y = y_min + (double)rand() / RAND_MAX * (y_max - y_min);
        if (y >= lower(x) && y <= upper(x)) hits++;
    }
    return rect * hits / n;
}

int main() {
    std::cout << "Simpson's rule\n";
    for (int n : {2, 10, 50, 100, 500, 1000, 10000}) {
        double area = simpson(integrand, A, B, n);
        std::cout << std::setprecision(19) << "N=" << n << "  Approximately area of the shape: " << area << "\n";
    }

    std::cout << "\n Monte Carlo\n";
    for (int n : {100, 1000, 5000, 10000, 50000, 100000, 500000}) {
        double area = monte_carlo(A, B, n);
        std::cout << std::setprecision(19) << "N=" << n << "  Approximately area of the shape: " << area << "\n";
    }

    system("pause");
    return 0;
}
