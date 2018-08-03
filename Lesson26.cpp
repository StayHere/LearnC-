for循环

for (init-statement; condition; expression)
    statement

for语句中定义的对象只在for循环体内可见。
init-statement可以定义多个对象，但是只能有一条声明语句。因此，所有变量的基础类型必须相同
for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i) {
    v.push_back(v[i]);
}

for语句能省略掉init-statement、condition和expression中的任何一个（或者全部）；分号必须保留
省略condition的效果等价于在条件部分写了一个true，此时在循环体内必须有语句负责退出循环，否则循环就会无休止地执行下去。
省略expression在循环中就要求条件部分或者循环体必须改变迭代变量的值。

范围for语句

for (declaration: expression)
    statement

这种语句可以遍历容器或其他序列的所有元素。
expression表示的必须是一个序列。
declaration定义一个变量，序列中的每个元素都得能转换成该变量的类型，确保类型相容最简单的办法是使用auto类型说明符。
如果需要对序列中的元素执行写操作，循环变量必须声明成引用类型。
每次迭代都会重新定义循环控制变量，并将其初始化成序列中的下一个值，之后才会执行statement。

vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 范围变量必须是引用类型，这样才能对元素执行写操作
for (auto &r : v)
    r *= 2;

// 范围for语句的定义来源于与之等价的传统for语句
for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
    auto &r = *beg;
    r *= 2;
}

do while 语句
do {
    statement
} while(condition);

do while 语句先执行循环体后检查条件，不管条件的值如何，都至少执行了一次循环。
do while 语句应该在括号包围起来的条件后面用一个分号表示语句结束。
condition不能为空，condition使用的变量必须定义在循环体之外。

// 不断提示用户输入一对数，然后求其和
string rsp; // 作为循环的条件，不能定义在do的内部
do {
    cout << "please enter two values: ";
    int val1 = 0, val2 = 0;
    cin >> val1 >> val2;
    cout << "The sum of " << val1 << " and " << val2
         << " = " << val1 + val2 << "\n\n"
         << "More? Enter yes or no: ";
    cin >> rsp;
} while (!rsp.empty() && rsp[0] != 'n');

因为对于do while 来说先执行语句或者块，后判断条件，所以不允许在条件部分定义变量。
do {
    mumble(foo);
} while (int foo = get_foo());  // 错误：将变量声明放在了do的条件部分
