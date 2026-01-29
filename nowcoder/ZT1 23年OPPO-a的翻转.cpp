/**
 * @file ZT1 23年OPPO-a的翻转.cpp
 * @date 2024-12-02
 */

/*
描述
数字
a
a翻转数位得到数字
b
b，计算
a
+
b
a+b。
输入描述：
一个正整数
a
  
(
1
⩽
a
⩽
1
0
9
)
a(1⩽a⩽10
9
 )。保证
a
a在十进制下每一位都非
0
0。
输出描述：
一个正整数表示答案。
示例1
输入：
12
复制
输出：
33
复制
说明：
正整数
a
=
12
a=12，翻转得到
b
=
21
b=21，
a
+
b
=
33
a+b=33。
示例2
输入：
23
复制
输出：
55
*/

#include <iostream>
using namespace std;

int main() {

    uint64_t a = 0;
    cin >> a;

    uint64_t b = 0, t = a;
    while (t) {
        b = b * 10 + t % 10;
        t /= 10;
    }

    cout << a + b;

    return 0;
}
