// 定义数据类型

// 类体右侧表示结束的花括号后必须写一个分号，因为类体后面可以紧跟变量名以示对该类型对象的定义
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 花括号后是对该类型对象的定义
struct Sales_data {} accum, trans, *salesptr;

// 与上一条语句等价，但这么写更好一些
struct Sales_data {};
Sales_data accum, trans, *salesptr;
