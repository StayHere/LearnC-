#include <iostream>

int main() {
    // 对const的引用
    // 对const的引用，引用的类型可以与其所引用对象的类型不一致
    double dval = 3.14;
    const int &r = dval;

    // 为了确保让r绑定一个整数，编译器把上述代码变成了如下形式：
    const int temp = dval;
    const int &r = temp;

    // 对const的引用可能引用一个并非const的对象
    // 引用一个并非const的对象时，不能通过引用来修改对象的值，但是可以通过其他方式来修改const的值
    int i = 42;
    int &r1 = i;    // 引用r1绑定对象i
    const int &r2 = i; // r2也绑定对象i，但是不允许通过r2来修改i的值
    r1 = 0;         // r1并非常数，i的值修改为0
    r2 = 0;         // 错误：r2是一个常量引用，不能用其修改对象的值

    // 指向常量的指针
    // 指向常量的指针，不能改变其所指对象的值
    // 要想存放常量对象的地址，只能使用指向常量的指针
    const double pi = 3.14;
    double *ptr = &pi;         // 错误：ptr是一个普通指针，不能指向常量对象
    const double *cptr = &pi;  // 正确：cptr可以指向一个双精度常量
    *cptr = 42;                // 错误：不能给*cptr赋值

    // 允许令一个指向常量的指针指向一个非常量对象
    double dval = 3.14;
    cptr = &dval;          // 正确：但是不能通过cptr改变dval的值

    // 常量指针
    // 必须初始化，且初始化后，指针的值（存放在指针中的地址）不能改变
    int errNumb = 0;
    int *const curErr = &errNumb; // 常量指针，curErr将一直指向errNumb
    const double pi = 3.14159;
    const double *const pip = &pi; // pip是一个指向常量对象的常量指针

    // 指针本身是一个常量并不意味着不能通过指针修改其所指对象的值，能否这样做完全依赖于所指对象的类型。
    // 如上述语句，pip是一个指向常量的常量指针，则不论是pip所指的对象值还是pip自己存储的那个地址都不能改变。
    // 相反，curErr指向的是一个一般的非常量整数，就可以用curErr去修改errNumb的值。
    *pip = 2.72;  // 错误：pip是一个指向常量的指针
    if (*curErr) {
        *curErr = 0;  // 正确：把curErr所指对象的值置为0
    }

    return 0;
}
