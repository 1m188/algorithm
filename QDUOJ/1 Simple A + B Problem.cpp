/**
 * @file 1 Simple A + B Problem.cpp
 * @date 2022-05-15
 */

/*
Description

请计算两个整数的和并输出结果。

注意不要有不必要的输出，比如"请输入 a 和 b 的值: "，示例代码见隐藏部分。


Input
两个用空格分开的整数.


Output
两数之和


Sample Input 1 

1 1
Sample Output 1

2
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 0, b = 0;
    cin >> a >> b;
    cout << a + b;
    return 0;
}