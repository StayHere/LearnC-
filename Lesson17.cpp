#include <vector>
#include <iostream>
#include <string>
#include "Sales_data.h"
using std::vector;
using std::cin;
using std::cout;
using std::string;

int main() {
    // vector表示对象的集合，其中所有对象的类型都相同
    vector<int> ivec;               // ivec存放int类型的对象
    vector<Sales_data> sales_vec;   // 保存Sales_item类型的对象
    vector<vector<string>> file;    // 该向量的元素是vector对象

    // vector能容纳绝大多数类型的对象作为其元素，但是因为引用不是对象，所以不存在包含引用的vector

    vector<string> svec;            // 默认初始化，avec不含任何元素
    vector<int> ivec2(ivec);        // 把ivec的元素拷贝给ivec2
    vector<int> ivec3 = ivec;       // 把ivec的元素拷贝给ivec3
    vector<string> svec1(ivec2)     // 错误：svec的元素是string对象，不是int

    // 列表初始化vector对象
    // 如果提供的是初始元素值的列表，则只能使用花括号，不能用圆括号
    vector<string> v1{"a", "an", "the"};    // 列表初始化
    vector<string> v2("a", "an", "the");    // 错误

    // 创建指定数量的元素
    vector<int> ivec4(10, -1);       // 10个int类型的元素，每个都被初始化为-1
    vector<string> svec2(10, "hi");  // 10个string类型的元素，每个都被初始化为"hi"

    // 向vector对象中添加元素
    // 利用vector的成员函数push_back向其中添加元素
    // push_back负责将一个值当成vector的尾元素push到vector对象的尾端
    vector<int> v3; // 空vector对象
    for (int i = 0; i != 100; ++i) {
        v3.push_back(i);    // 依次把整数值放到v2尾端
    }
    // 循环结束后v2有100个元素，值从0~99

    // 动态的读入元素
    // 从标准输入中读取单词，将其作为vector对象的元素存储
    string word;
    vector<string> text;    // 空vector对象
    while (cin >> word) {
        text.push_back(word);  // 把word添加到text后面
    }

    // 可以用范围for处理vector中所有的元素
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v) {
        i *= i;             // 求元素值的平方
    }
    for (auto i : v) {
        cout << i << " ";   // 输出该元素
    }
    cout << endl;

    // 要使用vector的size_type，需指定它是由哪种类型定义的
    vector<int>::size_type; // 正确
    vector::size_type;      // 错误

    vector<int> scores (11, 0);
    unsigned grade;
    while (cin >> grade) {          // 读取成绩
        if (grade <= 100) {         // 只处理有效的成绩
            ++scores[grade / 10];   // 将对应分数段的计数值加1
        }
    }

    return 0;
}
