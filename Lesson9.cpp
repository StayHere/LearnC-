#include <iostream>

int main() {
    // 指针
    int i = 0;
    int *p = nullptr;
    p = &i;
    *p = 3;
    std::cout << "i = " << i << "\n*p = " << *p << "\np = " << p << std::endl;

    int j = 42;
    int *p1 = &j;
    *p1 = *p1 * *p1;
    std::cout << "j = " << j <<"\n*p1 = " << *p1 << std::endl;

    // 指向指针的指针
    int ival = 1024;
    int *pi = &ival;    // pi指向一个int型的数
    int **ppi = &pi;    // pii指向一个int型的指针

    std::cout << "The value of ival\n"
              << "direct value: " << ival << "\n"
              << "indirect value: " << *pi << "\n"
              << "doubly indirect value: " << **ppi << std::endl;


    // 指向指针的引用
    int x = 42;
    int *ptr = nullptr;  // ptr是一个int型的指针
    int *&r = ptr;       // r是一个对指针ptr的引用

    r = &x;              // r引用了一个指针，因此给r赋值&x就是令ptr指向x
    *r = 0;              // 解引用r得到x，也就是ptr指向的对象，将x的值改成0

    return 0;
}
