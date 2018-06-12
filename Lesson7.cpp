#include <iostream>

int main() {

    // 初始化
    // 用花括号来初始化变量的形式称为列表初始化
    int units_sold = 0;
    int units_sold1 = {0};
    int units_sold2{0};
    int units_sold3(0);

    // 当用于内置类型的变量时，如果使用列表初始化且初始值存在丢失信息的风险，则编译器报错
    long double ld = 3.1415926536;
    int a{ld}, b = {ld};    // 错误：转换未执行，因为存在丢失信息的危险
    int c(ld), d = ld;      // 正确：转换执行，且确实丢失了部分值

    std::cin >> int input_value;        // 错误
    double salary = wage = 9999.99;     // 错误

    // 声明一个变量，在变量名前加关键字extern，且不要显式的初始化变量
    extern int i;   // 声明变量i
    int j;          // 声明并定义变量j
    extern double pi = 3.1415; // 定义，在函数体内部，初始化一个extern标记的变量，将引发错误

    return 0;
}
