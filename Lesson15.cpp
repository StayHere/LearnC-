#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    // 定义和初始化string对象
    string s1;          // 默认初始化，s1是一个空字符串
    string s2 = s1;     // s2是s1的副本
    string s3 = "hiya"; // s3是该字符串字面值的副本
    string s4(10, 'c'); // s4的内容是cccccccccc

    // string 初始化的方式
    string s1           // 默认初始化，s1是一个空串
    string s2(s1)       // s2是s1的副本
    string s2 = s1      // 等价于s2(s1)
    string s3("value")  // s3是字面值"value"的副本，除了字面值最后的那个空字符外
    string s3 = "value" // 等价于s3("value")
    string s4(n, 'c')   // 把s4初始化为由连续n个字符c组成的串

    // string对象上的操作
    os << s             // 将s写到输出流os当中，返回os
    is >> s             // 从is中读取字符串赋给s，字符串以空白分隔，返回is

    // 读写string对象
    string s;
    cin >> s;           // 将string对象读入s，遇到空白停止
    cout << s << endl;

    string s1, s2;
    cin >> s1 >> s2;    // 把第一个输入读入到s1中，第二个输入读到s2中
    cout << s1 << s2 << endl;   // 输出s1，s2对象

    // 读取未知数量的string对象
    string word;
    while (cin >> word) {       // 反复读取，直至到达文件末尾
        cout << word << endl;   // 逐个输出单词，每个单词后面紧跟一个换行
    }

    // 读取一整行
    string line;
    // 每次读入一整行，直至到达文件末尾，line中不包含换行符
    while (getline(cin, line)) {
        // empty为string的成员函数，可直接点语法调用，判断字符串是否为空
        // 遇到空行直接跳过
        if (!line.empty()) {
            cout << line << endl;
        }
        // size函数返回string对象的长度(即string对象中字符的个数)
        if (line.size() > 80) {
            cout << "too long" << endl;
        }

        // size函数返回的是一个string::size_type类型的值
        // 它是一个无符号类型的值，可以存放下任何string对象的大小
    }

    // 字符串相加
    // 两个string对象相加
    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;  // s3的内容是hello, world\n
    s1 += s2;             // 等价于s1 = s1 + s2;

    // 字面值和string对象相加
    // 标准库允许把字符字面值和字符串字面值转换成string对象
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\n';

    // 必须确保每个加法运算符（+）的两侧的运算对象至少有一个是string
    string s4 = s1 + ", "; // 正确
    string s5 = "hello" + ", "; // 错误：两个运算对象都不是string
    string s6 = s1 + ", " + "world";    // 正确：每个加法运算符都有一个运算对象是string
    string s7 = "hello" + ", " + s2;    // 错误：不能把字面值直接相加
    // 切记，字符串字面值与string是不同的类型
    return 0;
}
