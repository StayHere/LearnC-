int main() {
    // decltype类型指示符
    // decltype 选择并返回操作数的数据类型
    // decltype使用的表达式是一个变量时，decltype返回该变量的类型（包括顶层const和引用在内）

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;     // x的类型是const int
    decltype(cj) y = x;     // y的类型是const int&, y绑定到变量x
    decltype(cj) z;         // 错误，z是一个引用，必须初始化

    // 如果表达式的内容是解引用操作，则decltype将得到引用类型
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;      // 正确，加法的结果是int，因此b是一个（未初始化的）int
    decltype(*p) c;         // 错误，c是int &，必须初始化

    // decltype的表达式如果是加上了括号的变量，结果将是引用
    decltype((i)) d;        // 错误，d是int &，必须初始化
    decltype(i) e;          // 正确，e是一个（未初始化的）int

    // !!! decltype((variable))的结果永远是引用，而decltype(variable)的结果只有当variable本身就是一个引用时才是引用

    return 0;
}
