/**
 * @file HJ62 查找输入整数二进制中1的个数.cpp
 * @date 2024-11-15
 */

/*
描述
输入一个正整数，计算它在二进制下的1的个数。
注意多组输入输出！！！！！！

数据范围：
1
≤
n
≤
2
31
−
1

1≤n≤2
31
 −1
输入描述：
输入一个整数

输出描述：
计算整数二进制中1的个数

示例1
输入：
5
复制
输出：
2
复制
说明：
5的二进制表示是101，有2个1
示例2
输入：
0
复制
输出：
0
*/

#include <iostream>
using namespace std;

int main() {
    uint32_t n = 0;

    while (cin >> n) {
        int cnt = 0;
        while (n) {
            cnt += n & 0x1;
            n >>= 1;
        }
        cout << cnt << '\n';
    }

    return 0;
}
