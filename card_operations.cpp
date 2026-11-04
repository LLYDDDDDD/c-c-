#include "card_operations.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <limits>
using namespace std;
 
namespace card {
void printLine(char c, int len) { for (int i = 0; i < len; ++i) cout << c; cout << '\n'; }
void title(const string& s) { printLine(); cout << s << '\n'; printLine(); }
}
 
Card* createCards(int n) {
    if (n <= 0) throw invalid_argument("账户数量必须大于0");
    return new Card[n];
}
void destroyCards(Card* p) { delete[] p; }
void inputCards(Card* arr, int n) {
    for (int i = 0; i < n; ++i) {
        while (true) {
            cout << "请输入学号、姓名、初始余额：";
            try {
                if (!(cin >> arr[i].id >> arr[i].name >> arr[i].balance))
                    throw invalid_argument("输入格式错误");
                if (arr[i].balance < 0)
                    throw invalid_argument("余额不能为负数");
                arr[i].transactions = 0;
                break;
            } catch (const invalid_argument& e) {
                cout << e.what() << "，请重新输入。\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}
void deposit(Card& c, double amount, double fee) {
    if (amount < 0 || fee < 0 || fee >= 1) throw invalid_argument("充值金额或手续费率无效");
    c.balance += amount * (1.0 - fee);
    ++c.transactions;
}
bool spend(Card& c, double cost) {
    if (cost < 0) throw invalid_argument("消费金额不能为负数");
    if (cost > c.balance) throw runtime_error("余额不足，消费未完成");
    c.balance -= cost;
    ++c.transactions;
    return true;
}
bool spend(Card& c, double cost, const string& item) {
    cout << "消费项目：" << item << '\n';
    return spend(c, cost);
}
void showBalance(const Card& c) {
    cout << fixed << setprecision(2) << c.name << " 余额：" << c.balance << " 元\n";
    if (c.balance < WARNING_BALANCE) cout << "警告：余额低于 " << WARNING_BALANCE << " 元\n";
}
void viewStudentID(const Card* p) {
    if (!p) throw invalid_argument("账户指针为空");
    cout << "学号：" << p->id << '\n';
}
int toCent(double amount) { return static_cast<int>(amount * 100.0 + 0.5); }
void printReport(const Card* arr, int n) {
    cout << left << setw(12) << "ID" << setw(18) << "Name" << right
         << setw(12) << "Balance" << setw(16) << "Transactions" << '\n';
    for (int i = 0; i < n; ++i)
        cout << left << setw(12) << arr[i].id << setw(18) << arr[i].name << right
             << setw(12) << fixed << setprecision(2) << arr[i].balance
             << setw(16) << arr[i].transactions << '\n';
}
