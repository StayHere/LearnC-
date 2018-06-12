#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item;
    while (std::cin >> item) {
        Sales_item item2;
        int count = 1;
        while (std::cin >> item2) {
            if (item.isbn() == item2.isbn()) {
                count ++;
            } else {
                std::cout << "isbn: " << item.isbn() << " count = " << count << std::endl;
                count = 1;
                item = item2;
            }
        }
        std::cout << "isbn: " << item.isbn() << " count = " << count << std::endl;
    }
    return 0;
}
