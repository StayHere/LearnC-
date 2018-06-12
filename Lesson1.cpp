// 使用iostream库
#include <iostream>

int main(int argc, char const *argv[]) {
  /**
   * << 输出运算符，接受两个运算对象，左侧是一个ostream对象，右侧是需要打印的值
   * std::endl是一个操纵符，换行，并将缓冲区中的内容刷新到屏幕
   */
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    // >> 是输入运算符，左侧是一个istream对象，右侧是用于接受用户输入的对象，返回值是左侧的istream对象
    std::cin >> v1 >> v2;
    // 在使用cin和cout时都使用了std::作限制，std是一个命名空间（namespace），::是作用域运算符，std::cin表示使用std命名空间中的cin
    std::cout << "The sum of " << v1 << " and " << v2 << " is:" << v1 + v2 << std::endl;
    return 0;
}
