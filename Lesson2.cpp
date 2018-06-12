#include <iostream>

 // 计算1~10之间所有数字的和
int main(int argc, char const *argv[]) {

     int sum = 0, val = 1;

     /**
      *  while循环语句
      *  while (condition) {
      *      statement
      *  }
      *  执行过程：
      *  1.检查condition
      *  2.执行statement
      *  3.重复执行1和2，直到condition为假
      */

     // 只要val的值小于或等于10，while循环就会持续执行
     while (val <= 10) {
         sum += val;
         ++ val;
     }
     std::cout << "sum of 1 to 10 inclusive is " << sum << std::endl;

     /**
      *  for循环语句
      *  for (init-statement; condition; expression) {
      *      statement
      *  }
      *  执行过程：
      *  1.init-statement
      *  2.检查condition
      *  3.执行循环体中的statement
      *  4.执行循环头中的expression
      *  5.重复执行2和4，直到condition为假
      */

      sum = 0;
      for (int val = 1; val <= 10; ++ val) {
          sum += val;
      }
      std::cout << "sum of 1 to 10 inclusive is " << sum <<std::endl;

      /**
       * if 语句，条件语句
       * if (condition) {
       *      statement
       * }
       * 执行过程
       * 当condition为真时执行，否则不执行
       */

       // 在上面的for循环中添加一个if语句
       sum = 0;
       for (int val = 1; val <= 10; ++ val) {
           if (val <= 5) {
               sum += val;
           }
       }
       // 虽然for循环仍会遍历1~10的所有数字，但只会对小于等于5的那部分执行求和。
       std::cout << "sum of 1 to 10 inclusive is " << sum <<std::endl;


       // 实例1：读取数量不定的输入
       // 不断读取用户输入直到没有新的输入为止，输出所有数据的和。
       sum = 0;
       int value = 0;
       while (std::cin >> value) {
           sum += value;
       }
       // while循环使用std::cin >> value作为条件，我们知道std::cin >> value的返回值为std::cin，
       // 使用一个istream对象作为条件时，其效果是检测流的状态，当遇到文件结束符或无效输入时，istream对象的状态变为无效，条件为假；否则为真。
       std::cout << "sum is " << sum << std::endl;


       // 实例2：统计值连续出现的次数
       // 读取数量不定的输入，统计输入中每个值连续出现的次数

       int currval = 0; // 我们正在统计的数值
       int inputval = 0; // 新输入的数值
       // 读取第一个数，并确保确实有数据可以处理
       if (std::cin >> currval) {
           int count = 1; // 记录当前数值出现的次数
           // 读取用户输入
           while (std::cin >> inputval) {
               if (inputval == currval) { // 如果值相同，则计数加1
                   ++ count;
               } else { // 否则当前统计结束，打印结果
                   std::cout << currval << "occurs " << count << " times" << std::endl;
                   currval = inputval; // 记住新值
                   count = 1; // 重置计数
               }
           }
           // 打印最后一个数值的个数
           std::cout << currval << " occurs " << count << " times" << std::endl;
       }

     return 0;
}
