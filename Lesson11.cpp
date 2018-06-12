#include <iostream>

int main() {
    // typedef 定义类型别名
    typedef double wages;   // wages是double的同义词
    typedef wages base, *p; // base是double的同义词，p是double *的同义词

    // 新标准使用别名声明定义类型的别名
    using SI = Sale_item;   // SI是Sales_item的同义词

    // 类型别名和类型的名字等价，只要是类型的名字能出现的地方，就能使用类型别名：
    wages hourly, weekly;   // 等价于double hourly, weekly;
    SI item;                // 等价于Sales_item item;

    // 指代复合类型或常量的类型别名
    typedef char *pstring;
    const pstring cstr = 0; // cstr是指向char的常量指针
    const pstring *ps;      // ps是一个指针，它的对象是指向char的常量指针

    // auto 类型说明符
    // auto让编译器通过初始值来推算变量的类型
    // 因此，auto定义的变量必须有初始值
    auto item = val1 + val2;    // item初始化为val1和val2相加的结果

    auto i = 0, *p = &i;    // 正确：i是整数、p是整型指针
    auto sz = 0, pi = 3.14; // 错误：sz和pi的类型不一致

    // 编译器以引用对象的类型作为auto的类型：
    int i = 0, &r = i;
    auto a = r;         // a是一个整数（r是i的别名，而i是一个整数）

    // auto一般会忽略顶层const，同时底层const则会被保留下来
    const int ci = i, &cr = ci;
    auto b = ci;    // b是一个整数
    auto c = cr;    // c是一个整数
    auto d = &i;    // d是一个整型指针
    auto e = &ci;   // e是一个指向整数常量的指针

    // 如果希望推断出的auto类型是一个顶层const，需要明确指出：
    const auto f = ci;  // ci的推演类型是int，f是const int

    // 还可以将引用的类型设为auto，此时原来的初始化规则仍然适用
    // 设置一个类型为auto的引用时，初始值中的顶层常量属性依然保留
    auto &g = ci;       // g是一个整形常量引用，绑定到ci
    auto &h = 42;       // 错误，不能为非常量引用绑定字面值
    const auto &j = 42; // 正确，可以为常量引用绑定字面值
}
