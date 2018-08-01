#include <iostream>

int main() {
	// 多维数组
	// 当一个数组的元素仍然是数组时，通常使用两个维度来定义它，一个维度表示数组本身大小，另一个维度表示其元素大小
	int ia[3][4];			// 大小为3的数组，每个元素是含有4个整数的数组
	int arr[10][20][30];	// 大小为10的数组，每个元素都是大小为20的数组，这些数组是含有30个整数的数组

	// 初始化
	int ia[3][4] = {	// 3个元素，每个元素都是大小为4的数组
		{0, 1, 2, 3},	// 第1行初始化
		{4, 5, 6, 7},	// 第2行初始化
		{8, 9, 10, 11}	// 第3行初始化
	};

	int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};	// 没有标识每行的花括号，与之前的初始化语句等价

	int ia[3][4] = {{0}, {4}, {8}};	// 显式的初始化每行的首元素，其他未列出的元素执行默认值初始化

	// 下标运用
	ia[2][3] = arr[0][0][0];	// 用arr的首元素为ia最后一行的最后一个元素赋值
	int (&row)[4] = ia[1];		// 将row绑定到ia的第二行4元素数组上

	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];	// 12个未初始化的元素
	// 对于每一行
	for (int i = 0; i != rowCnt; ++i) {
		// 对于每一列
		for (int j = 0; j != colCnt; ++j) {
				// 将元素的位置索引作为它的值
				ia[i][j] = i * colCnt + j;
			}	
	}

	// 范围for语句处理多维数组
	// 与前一双层循环等价
	size_t cnt = 0;
	for (auto &row : ia) {
		for (auto &col : row) {
			col = cnt;
			++cnt;
		}
	}

	// 指针和多维数组
	// 由多维数组名转换得来的指针实际上是指向第一个内层数组的指针
	int ia[3][4];
	int (*p)[4] = ia;	// p指向含有4个整数的数组
	p = &ia[2];			// p指向ia的尾元素

	// 通过使用auto或者decltype尽可能地避免在数组前面加上一个指针类型
	// 输出ia中每个元素的值
	// p指向含有4个整数的数组
	for (auto p = ia; p != ia + 3; ++p) {
		// q指向4个整数数组的首元素，也就是说，q指向一个整数
		for (auto q = *p; q != *p + 4; ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}

	// 使用库函数begin和end也能实现同样的功能，而且看起来更简洁
	for (auto p = begin(ia); p != end(ia); ++p) {
		for (auto q = begin(*p); q != end(*p); ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}

	// 类型别名简化多维数组的指针
	using int_array = int[4];	// 新标准下类型别名的声明
	typedef int int_array[4];	// 等价的typedef声明

	// 输出ia中每个元素的值，每个内层数组各占一行
	for (int_array *p = ia; p != ia + 3; ++p) {
		for (int *q = *p; q != *p + 4; ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}
}