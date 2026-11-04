#include <iostream>
using namespace std;
void swap(int& x, int& y) { int t = x; x = y; y = t; }
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int main() {
    int x, y;
    if (!(cin >> x >> y)) return 1;
    cout << "Before swap: x=" << x << ", y=" << y << '\n';
    swap(x, y);
    cout << "After  swap: x=" << x << ", y=" << y << '\n';
    swap(&x, &y); } // invoke the pointer overload
