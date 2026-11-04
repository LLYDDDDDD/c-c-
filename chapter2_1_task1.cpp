#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
struct Student { string name; double score[3]; };
int main() {
    int n;
    if (!(cin >> n) || n < 0) return 1;
    vector<Student> students(n);
    for (int i = 0; i < n; ++i)
        cin >> students[i].name >> students[i].score[0]
            >> students[i].score[1] >> students[i].score[2];
    cout << fixed << setprecision(2) << left << setw(14) << "Name"
         << right << setw(10) << "Chinese" << setw(10) << "Math"
         << setw(10) << "English" << setw(10) << "Average" << '\n';
    for (const Student& s : students) {
        double avg = (s.score[0] + s.score[1] + s.score[2]) / 3.0;
        cout << left << setw(14) << s.name << right << setw(10) << s.score[0]
             << setw(10) << s.score[1] << setw(10) << s.score[2]
             << setw(10) << avg;
        if (avg >= 90) cout << "  Excellent";
        cout << '\n';
    }
}
