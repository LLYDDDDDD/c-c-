#include "card_operations.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <new>
#include <exception>
using namespace std;
 
int main() {
    card::title("校园一卡通消费管理系统");
    int n;
    cout << "请输入账户数量：";
    if (!(cin >> n) || n <= 0) { cerr << "账户数量无效\n"; return 1; }
    Card* cards = 0;
    try {
        cards = createCards(n);
        inputCards(cards, n);
        deposit(cards[0], 100.0);
        spend(cards[0], 8.5, "食堂午餐");
        showBalance(cards[0]);
        viewStudentID(&cards[0]);
        cout << fixed << setprecision(2) << "余额（分）：" << toCent(cards[0].balance) << '\n';
        card::printLine('=');
        printReport(cards, n);
        card::printLine('=');
    } catch (const bad_alloc&) {
        cerr << "内存分配失败，程序安全退出。\n";
        delete[] cards;
        return 1;
    } catch (const exception& e) {
        cerr << "操作失败：" << e.what() << '\n';
    }
    destroyCards(cards);
    return 0;
}
