#include <iostream>
using std::cin;
using std::cout;

int main() {
	// C风格字符串
	// C++程序中最好不要使用
	// C标准库String函数，在cstring头文件中，
	// 传入此类函数的指针必须指向以字符串作为结束的数组

	char ca[] = {'C', '+', '+'};
	cout << strlen(ca) << endl;	// 严重错误：ca没有以空字符结束

	// 要想比较两个C风格字符串，不能用运算符，需要调用strcmp函数
	if (strcmp(ca1, ca2) < 0) { // 和两个string对象的比较效果一样
		
	}

	// 与string的互相转换
	string s("Hello World"); s的内容是Hello World
	// 允许使用以空字符结束的字符数组来初始化string对象或为其赋初值

	// 使用string的成员函数c_str初始化指向字符的指针
	char *str = s;	// 错误：不能用string对象初始化char *
	const char *str = s.c_str();	// 正确

	// 使用数组初始化vector对象
	// 只需指明要拷贝区域的首元素地址和尾后地址
	int int_arr[] = {0, 1, 2, 3, 4, 5};
	vector<int> ivec(begin(int_arr), end(int_arr));
	// ivec有6个元素，分别是int_arr中对应元素的副本

	// 用于初始化vector对象的值也可能仅是数组的一部分
	vector<int> subVec(int_arr + 1, int_arr + 4);
}