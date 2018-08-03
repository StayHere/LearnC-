跳转语句

C++提供4中跳转语句：break、continue、goto和return。

break 语句负责终止离它最近的while、do while、for或switch语句，并从这些语句之后的第一条语句开始继续执行。
continue 语句终止最近的循环中的当前迭代并立即开始下一次迭代，continue语句只能出现在for、while和do while循环内部。
goto 语句是从goto语句无条件跳转到同一函数内的另一条语句。（不要使用goto语句）。

goto label;
end: return;

label是用于标识一条语句的标识符。带标签语句是一种特殊的语句，在它之前有一个标示符以及一个冒号。
标签标示符独立于变量或其他标示符的名字，因此，标签标示符可以和程序中其他实体的标识符使用同一个名字而不会互相干扰。

异常处理

throw 表达式，异常检测部分使用throw表达式来表示它遇到了无法处理的问题。throw引发了异常。
try 语句块，异常处理部分使用try语句块处理异常。try 语句块以关键字try开始，并以一个或多个catch子句结束。
try语句块中代码抛出的异常通常会被某个catch子句处理，也被称作异常处理代码。
一套异常类，用于在throw表达式和相关的catch子句之间传递异常的具体信息。

throw 表达式

if (item1.isbn() != item2.isbn()) {
    throw runtime_error("Data must refer to same ISBN");
    // 如果程序执行到这里，表示两个ISBN是相同的
}
cout << item1 + item2 << endl;

在这段代码中，如果ISBN不一样就抛出一个异常，该异常是类型runtime_error的对象。
抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。

try 语句块

try {
    program-statements
} catch (exception-declaration) {
    handle-statements
} catch (exception-declaration) {
    handle-statements
} // ...

catch子句包括三部分：关键字catch、括号内一个（可能未命名）对象的声明（称作异常声明）以及一个块。
当选中了某个catch子句处理异常之后，执行与之对应的块。
try语句块中的program-statements组成程序的正常逻辑，try语句块内声明的变量在块外部无法访问，在catch子句内也无法访问。

while (cin >> item1 >> item2) {
    try {
        // 执行添加两个Sales_item对象的代码
        // 如果添加失败，代码抛出一个runtime_error异常
    } catch (runtime_error err) {
        // 提醒用户两个ISBN必须一致，询问是否重新输入
        cout << error.what()
             << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c == 'n') {
            break;  // 跳出while循环
        }
    }
}

寻找处理代码的过程与函数调用链刚好相反。当异常被抛出时，首先搜索抛出该异常的函数。如果没找到匹配的catch子句，终止该函数，并在调用该函数的函数中继续寻找。
如果还是没有找到匹配的catch子句，这个新的函数也被终止，继续搜索调用它的函数。以此类推，沿着程序的执行路径逐层回退，直到找到适当类型的catch子句为止。
如果最终还是没能找到任何匹配的catch子句，程序转到名为terminate的标准库函数。该函数的行为与系统有关，一般情况下，执行该函数将导致程序非正常退出。

标准异常

C++标准库定义了一组类，用于报告标准库函数遇到的问题。

exception 头文件定义了最通用的异常类exceptioin。它只报告异常的发生，不提供任何额外信息。
stdexcept 头文件定义了几种常用的异常类。
new 头文件定义了bad_alloc异常类型。
type_info 头文件定义了bad_cast异常类型。

只能以默认初始化的方式初始化exception、bad_alloc和bad_cast对象，不允许为这些对象提供初始值。
其他异常类型的行为则恰好相反，应该使用string对象或者C风格字符串初始化这些类型的对象，但是不允许使用默认初始化的方式。
当创建此类对象时，必须提供初始值，该初始值含有错误相关的信息。
异常类型只定义了一个名为what的成员函数，该函数没有任何参数，返回值是一个指向C风格字符串的const char *。该字符串是提供关于异常的一些文本信息。
