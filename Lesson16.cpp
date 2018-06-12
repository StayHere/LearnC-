#include <string>
using std::string;

int main() {
    // 范围for（类似于for in）
    for (declaration : expression)
        statement

    string str("some string");
    // 每行输出str中的一个字符
    for (auto c : str) {    // 对于str中的每个字符
        std::cout << c << endl; // 输出当前字符，后面紧跟一个换行符
    }

    // 使用ispunct函数统计string对象中标点符号的个数
    string s("Hello World!!!");
    // punct_cnt的类型和s.size的返回类型一样
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s) {
        if (ispunct(c)) {
            ++ punct_cnt;
        }
    }
    cout << punct_cnt << "punctuation characters in " << s << endl;

    // 使用范围for改变字符串中的字符
    // 如果想要改变string对象中字符的值，必须把循环变量定义成引用类型

    // 将字符串改写成大写字母的形式
    string s("Hello World!!!");
    // 转换成大写形式
    for (auto &c : s) {
        c = toupper(c); // c是一个引用，因此赋值语句将改变s中字符的值
    }
    cout << s << endl;

    // 使用下标运算符[]访问string对象中的单个字符
    // 下标运算符输入参数是string::size_type类型，返回值是该位置上字符的引用
    // 使用下标运算符输出string对象中的第一个字符
    if (!s.empty()) {
        cout << s[0] << endl;
    }

    // 只要字符串不是常量，就能为下标运算符返回的字符赋新值
    string s("some string");
    if (!s.empty()) {
        s[0] = toupper(s[0]);   // 为s的第一个字符赋一个新值
    }

    // 把s的第一个词改成大写形式
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
        s[index] = toupper(s[index]);
    }
}
