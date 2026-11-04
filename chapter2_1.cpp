#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
using namespace std;
 
struct Student { string name; double score[3]; };
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
int countVowels(const char* p) {
    int count = 0;
    while (*p) {
        char c = *p++;
        if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a');
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++count;
    }
    return count;
}
void swap(int& x, int& y) { int t = x; x = y; y = t; }
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
 
int main() {
    cout << fixed << setprecision(2);
    int task;
    cout << "Select task (1-4): ";
    if (!(cin >> task)) return 1;
    if (task == 1) {
        int n;
        if (!(cin >> n) || n < 0) return 1;
        vector<Student> students(n);
        for (int i = 0; i < n; ++i)
            cin >> students[i].name >> students[i].score[0]
                >> students[i].score[1] >> students[i].score[2];
        cout << left << setw(14) << "Name" << right << setw(10) << "Chinese"
             << setw(10) << "Math" << setw(10) << "English" << setw(10) << "Average" << '\n';
        for (const Student& s : students) {
            double avg = (s.score[0] + s.score[1] + s.score[2]) / 3.0;
            cout << left << setw(14) << s.name << right << setw(10) << s.score[0]
                 << setw(10) << s.score[1] << setw(10) << s.score[2] << setw(10) << avg;
            if (avg >= 90) cout << "  Excellent";
            cout << '\n';
        }
    } else if (task == 2) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string line;
        getline(cin, line);
        cout << "Number of vowels: " << countVowels(line.c_str()) << '\n';
    } else if (task == 3) {
        double a, b; char op;
        if (!(cin >> a >> b >> op)) return 1;
        cout << "square(" << a << ") = " << square(a) << '\n';
        cout << "power(" << a << ") = " << power(a) << '\n';
        cout << "power(" << a << ",3) = " << power(a, 3) << '\n';
        try { cout << a << ' ' << op << ' ' << b << " = " << calc(a, b, op) << '\n'; }
        catch (const exception& e) { cout << e.what() << '\n'; }
    } else if (task == 4) {
        int x, y;
        if (!(cin >> x >> y)) return 1;
        cout << "Before swap: x=" << x << ", y=" << y << '\n';
        swap(&x, &y);
        cout << "After  swap: x=" << x << ", y=" << y << '\n';
    } else return 1;
    return 0;
}
