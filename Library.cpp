#include <iostream>
#include "Sales_item.h"

int main() {

    Sales_item book;
    // 读入ISBN号，售出的册数以及销售的价格
    std::cin >> book;
    //写入ISBN号、售出的册数、总销售额和平均价格
    std::cout << book << std::endl;

    // 两个Sales_item对象相加
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // 成员函数 item1.isbn()
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
    return 0;
}
