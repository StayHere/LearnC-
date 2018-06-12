#include <iostream>
#include <string>

using std::string;

int main() {
    // 通过取地址符获取指向数组中某元素的指针
    string nums[] = {"one", "two", "three"};    // 数组的元素是string对象
    string *p = &nums[0];                       // p指向nums的第一个元素

    // 数组的特性：在很多用到数组名字的地方，编译器都会自动将其替换成一个指向数组首元素的指针
    string *p2 = nums;  // 等价于p2 = &nums[0]

    // 当使用数组作为一个auto变量的初始值时，推断得到的类型是指针而非数组
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // ia是一个含有10个整数的数组
    auto ia2(ia);       // ia2 是一个整型指针，指向ia的第一个元素
    ia2 = 42;           // 错误：ia2是一个指针，不能用int值给指针赋值

    // 当使用ia作为初始值时，编译器实际执行的初始化过程类似于下面的形式
    auto ia2(&ia[0]);   // 显然ia2的类型是int *

    // 当使用decltype关键字时上述转换不会发生，decltype(ia)返回的类型是10个整数组成的数组
    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ia3 = p;    // 错误，不能把整型指针给数组赋值
    ia3[4] = i; // 正确，把i的值赋给ia3的一个元素

    // vector和string的迭代器支持的运算，指向数组的指针全支持
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = arr;   // p指向arr的第一个元素
    ++p;            // p指向arr的第二个元素 arr[1]

    // 数组的特性：可以获取数组尾元素之后的那个并不存在的元素的地址
    int *e = &arr[10];  // 指向arr尾元素的下一位置的指针

    // 不存在的元素位移的用处就是提供其地址用于初始化e，就像尾后迭代器一样，尾后指针也不指向具体的元素
    // 因此，不能对尾后指针执行解引用或递增的操作
    // 利用上面的指针能重写之前的循环，令其输出arr的全部元素
    for (int *b = arr; b != e; ++b) {
        cout << *b << endl;     // 输出arr的元素
    }
    return 0;
}
