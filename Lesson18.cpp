#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    // 迭代器
    // begin函数获取指向第一个元素的迭代器，end获取指向尾元素的下一位置的迭代器

    // 将字符串的第一个字符改为大写
    string s("some string");
    if (s.begin() != s.end()) { // 确保s非空
        auto it = s.begin();    // it表示s的第一个字符
        *it = toupper(*it);     // 将当前字符改成大写
    }

    // 将字符串的第一个单词改为大写
    for (auto it = s.begin(); it != s.end(), !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    cout << s << endl;

    // iterator和const_iterator表示迭代器的类型
    vector<int>::iterator it;   // it能读写vector<int>的元素
    string::iterator it2;       // it2能读写string对象中的字符

    vector<int>::const_iterator it3;    // it3只能读元素，不能写元素
    string::const_iterator it4;         // it4只能读字符，不能写字符

    // begin和end函数返回的类型由对象是否是常量决定
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();   // it1的类型是vector<int>::iterator
    auto it2 = cv.begin();  // it2的类型是vector<int>::const_iterator

    // 为了便于专门得到const_iterator类型的返回值，引入了两个新函数cbegin和cend
    auto it3 = v.cbegin();  // it3的类型是vector<int>::const_iterator

    // 解引用迭代器可获得迭代器所指的对象
    (*it).empty()       // 解引用it，然后调用结果对象的empty成员
    *it.empty()         // 错误：试图访问it的名为empty的成员，但it是个迭代器，没有empty成员

    // 为了简化操作，定义了箭头运算符（->）
    // it->men 等价于 (*it).mem

    string text;
    // 依次输出text的每一行直至遇见第一个空白行为止
    for (auto it = text.cbegin(); it != text.cend(), !it->empty(); ++it) {
        cout << *it << endl;
    }

    // 迭代器的算术运算
    auto mid = vi.begin() + vi.size() / 2;  // 计算得到最接近v1中间元素的一个迭代器

    // 二分搜索
    // text是有序的
    string text;
    auto sought;
    auto begin = text.begin(), end = text.end();    // begin和end代表搜索的范围
    auto mid = begin + (end - begin) / 2;           // 中间点,迭代器相减的结果是两个迭代器的距离

    while (mid != end && *mid != sought) {
        if (*mid < sought) {    // 要找的元素是否在后半部分
            begin = ++mid;      // 如果是，调整搜索范围在mid之后寻找
        } else {
            sought = *mid;      // 要找的元素在前半部分，调整搜索范围，忽略掉后半部分
        }
        mid = begin + (end - begin) / 2;    // 新的中间点
    }
    cout << sought << endl;

    return 0;
}
