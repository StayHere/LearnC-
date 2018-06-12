#include <iostream>

int main() {
    // 数组

    // 数组是一种类似于vector的数据结构
    // 与vector不同的是，数组的大小确定不变，不能向数组中增加元素
    // 编译的时候数组的个数应该是已知的，维度必须是一个常量表达式
    unsigned cnt = 42;      // 不是常量表达式
    constexpr unsigned sz = 42; // 常量表达式
    int arr[10];            // 含有10个整数的数组
    int *parr[sz];          // 含有42个整型指针的数组
    string bad[cnt];        // 错误，cnt不是常量表达式
    string strs[get_size()];// 当get_size是constexpr时正确，否则错误

    // 定义数组的时候必须指定数组的类型，不允许用auto
    // 数组的元素应为对象，因此不存在引用的数组

    // 可列表初始化数组，可以忽略数组的维度。
    // 如果指明了维度，初始值总数量不能超过指定的大小，小于指定大小的元素被初始化为默认值
    const unsigned sz = 3;
    int ia1[sz] = {0, 1, 2};        // 含有三个元素的数组
    int a2[] = {0, 1, 2};           // 等价于上一表达式
    int a3[5] = {0, 1, 2};          // 等价于a3[] = {0, 1, 2, 0, 0};
    string a4[3] = {"hi", "bye"};   // 等价于a4[] = {"hi", "bye", ""}
    int a5[2] = {0, 1, 2};          // 错误，初始值过多

    // 字符数组可以用字符串字面值初始化，当使用此方式初始化时，注意字符串字面值的结尾处还有一个空字符
    char a1[] = {'C', '+', '+'};        // 列表初始化，没有空字符
    char a2[] = {'C', '+', '+', '\0'};  // 列表初始化，有空字符
    char a3[] = "C++";                  // 自动添加表示字符串结束的空字符
    const char a4[6] = "Daniel";        // 错误：没有空间存放空字符

    // 不能将数组的内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值
    int a[] = {0, 1, 2};
    int a2 = a;         // 错误，不允许使用一个数组初始化另一个数组
    a2 = a;             // 错误，不能把一个数组直接赋值给另一个数组

    int *ptrs[10];              // ptrs是含有10个整型指针的数组
    int &refs[10] = ?;          // 错误：不存在引用的数组
    int (*Parray)[10] = &arr;   // Parray指向一个含有10个整数的数组
    int (&arrRef)[10] = arr;    // arrRef引用一个含有10个整数的数组

    // 可使用下标来访问数组的元素，从0开始
    // 数组下标通常定义为size_t类型
    // 数组除了大小固定，其他用法与vector基本类似
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }

    // 使用范围for语句遍历数组的所有元素
    for (auto i : scores) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
