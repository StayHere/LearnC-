// 预处理命令
// 当且仅当变量未定义时为真
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

#endif
