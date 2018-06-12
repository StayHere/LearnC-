#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

	// 标准库函数begin和end
	// 与容器中的两个同名成员函数类似
	int ia[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];	// ia是一个含有10个整数的数组
	int *beg = begin(ia);	// 指向ia首元素的指针
	int *last = end(ia);	// 指向ia尾元素的下一位置的指针

	// 使用begin和end函数写出一个循环
	// pbeg指向arr的首元素，pend指向arr尾元素的下一位置
	int arr[] = [3, 5, 7, 2, 8, 2, -4, 2, -6, -1];
	int *pbeg = begin(arr), pend = end(arr);
	// 寻找第一个负值元素，如果已经检查完全部元素则结束循环
	while (pbeg != pend && *pbeg >=0) {
		++pbeg;
	}
	if (pbeg != pend) {
		cout << *pbeg << endl;
	}

	// 指针运算
	// 指针加上（减去）某整数值，结果仍是指针。新指针比原指针前进（后退）了整数值个位置
	constexpr size_t sz = 5;
	int arr[sz] = [1, 2, 3, 4, 5];
	int *ip = arr;			// 等价于int *ip = &arr[0];
	int *ip2 = arr + 4;		// ip2指向arr的尾元素arr[4]

	int *p = arr + sz;		// 正确，p指向arr尾元素的下一位置
	int *p2 = arr + 10;		// 错误，arr只有五个元素，p2的值未定义

	// 两个指针相减的结果是他们之间的距离
	auto n = end(arr) - begin(arr);		// n的值是5，也就是arr中元素的数量
	// 两指针相减的结果是一种名为ptrdiff_t的类型

	// 如果两个指针指向同一个数组的元素，则可以比较
	int *b = arr, *e = arr + sz;
	while (b < e) {
		// 使用 *b
		++b;
	}

	// 如果两个指针分别指向不相关的对象，则不能比较他们
	int i = 0, sz = 42;
	int *p = &i, *e = &sz;
	// 未定义的：p和e无关，因此比较毫无意义
	while (p < e)

	return 0;
}