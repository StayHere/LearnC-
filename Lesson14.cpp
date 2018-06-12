#include <iostream>

using std::cin;

int main() {
    // using声明，可直接访问命名空间中的名字
    int i;
    cin >> i;       // 正确
    cout << i;      // 错误，没有对应的using声明，必须使用完整的名字
    std::cin >> i;  // 正确，显示的从std中使用cin
    std::cout << i; // 正确，显示的从std中使用cout
    return 0;
}
