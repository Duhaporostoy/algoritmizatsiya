#include <iostream>
#include <cmath>
#include <string>
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

int passed = 0, failed = 0;

void assertAlmostEqual(double a, double b, double tol, const std::string& name) {
    if (fabs(a - b) <= tol) {
        std::cout << "[PASS] " << name << "\n";
        passed++;
    } else {
        std::cout << "[FAIL] " << name << "  got=" << a << "  expected~" << b << "  diff=" << fabs(a - b) << "\n";
        failed++;
    }
}

int main() {
    double ref = simpson(integrand, A, B, 100000);

    std::cout << "Запуск тестов...\n\n";

    assertAlmostEqual(simpson(integrand, A, B, 100),   ref, 1e-3, "Simpson N=100   (tol=1e-3)");
    assertAlmostEqual(simpson(integrand, A, B, 1000),  ref, 1e-5, "Simpson N=1000  (tol=1e-5)");
    assertAlmostEqual(simpson(integrand, A, B, 10000), ref, 1e-7, "Simpson N=10000 (tol=1e-7)");
    assertAlmostEqual(monte_carlo(A, B, 500000), ref, ref * 0.01, "MonteCarlo N=500000 (tol=1%)");

    std::cout << "\nРезультат: " << passed << " passed, " << failed << " failed\n";

    system("pause");
    return 0;
}
