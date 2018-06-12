// 基本数据类型

#include <iostream>

int main() {
    // 无符号型，有符号型变量
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    // 分多行书写的字符串字面值
    std::cout << "a really, really long string literal "
                 "that spans two lines" << std::endl;

    // 转义序列
    // 可以使用泛化的转义序列，\x后紧跟1个或多个十六进制数字，或\后紧跟1个、2个或3个八进制数字
    // 其中数字部分表示的是字符对应的数值

    // 如果反斜线\后面跟着的八进制数字超过3个，只有前3个数字与\构成转义序列
    std::cout << "Hi \x4dO\115!\n"; // 输出Hi MOM!，转到新一行

    int month = 07; // 八进制
    std::cout << month << std::endl;
    return 0;
}
