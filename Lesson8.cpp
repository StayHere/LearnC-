#include <iostream>

int reused = 42;    // reused拥有全局作用域
int main() {
    int unique = 0; // unique拥有块作用域

    // 使用全局变量reused，输出42 0
    std::cout << reused << " " << unique << std::endl;
    int reused = 0; // 新建局部变量reused，覆盖了全局变量reused

    // 使用局部变量reused，输出0 0
    std::cout << reused << " " << unique << std::endl;

    // 显式的访问全局变量reused，输出42 0
    std::cout << ::reused << " " << unique << std::endl;    // 使用作用域操作符::来覆盖默认的作用域规则

    return 0;
}
