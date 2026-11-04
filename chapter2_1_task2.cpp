#include <iostream>
#include <string>
using namespace std;
int countVowels(const char* p) {
    int count = 0;
    while (*p) {
        char c = *p++;
        if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a');
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++count;
    }
    return count;
}
int main() {
    string line;
    getline(cin, line);
    cout << "Number of vowels: " << countVowels(line.c_str()) << '\n';
}
