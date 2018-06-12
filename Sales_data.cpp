#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1, data2;
    // 读入data1和data2的代码
    // 检查data1和data2的ISBN是否相同的代码
    // 如果相同，求data1和data2的总和

    double price = 0;

    // 读入第一笔交易
    std::cin >> data1.bookNo >> data1.units_sold >> price;

    // 计算销售收入
    data1.revenue = data1.units_sold * price;

    // 读入第二笔交易
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCount = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " ";
        if (totalCount != 0) {
            std::cout << totalRevenue / totalCount << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl;
        }
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}
