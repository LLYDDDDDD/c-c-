#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
inline double square(double x) { return x * x; }
double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) result *= base;
    return result;
}
double calc(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw invalid_argument("Error: divide by zero");
        return a / b;
    }
    throw invalid_argument("Error: invalid operator");
}
double calc(int a, int b, char op) { return calc(double(a), double(b), op); }
int main() {
    double a, b; char op;
    if (!(cin >> a >> b >> op)) return 1;
    cout << fixed << setprecision(2);
    cout << "square(" << a << ") = " << square(a) << '\n';
    cout << "power(" << a << ",3) = " << power(a, 3) << '\n';
    try {
        double result = calc(a, b, op);
        cout << a << ' ' << op << ' ' << b << " = " << result << '\n';
    } catch (const exception& e) { cout << e.what() << '\n'; }
}
