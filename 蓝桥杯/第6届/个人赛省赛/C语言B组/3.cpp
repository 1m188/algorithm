/*

三羊献瑞

观察下面的加法算式：

      祥 瑞 生 辉
  +   三 羊 献 瑞
-------------------
   三 羊 生 瑞 气

(如果有对齐问题，可以参看【图1.jpg】)

其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字。

请你填写"三羊献瑞"所代表的4位数字（答案唯一），不要填写任何多余内容。

*/

/*
 * 解题思路：
 * 将八个汉字映射为 A~H 共 8 个不同数字（0~9 中取 8 个）。
 * 三 (E) 为和的最高位，必为 1。
 * 通过 std::next_permutation 枚举 0~9 中任选 8 个数字的全排列，
 * 验证竖式加法等式，找到唯一解后输出 E F G B（即"三羊献瑞"）。
 */
#include <algorithm>
#include <iostream>

int main() {
    int d[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        // A=祥 B=瑞 C=生 D=辉 E=三 F=羊 G=献 H=气
        int A = d[0], B = d[1], C = d[2], D = d[3];
        int E = d[4], F = d[5], G = d[6], H = d[7];
        if (E == 0 || A == 0)
            continue; // 最高位不能为 0
        int n1 = A * 1000 + B * 100 + C * 10 + D;
        int n2 = E * 1000 + F * 100 + G * 10 + B;
        int sum = E * 10000 + F * 1000 + C * 100 + B * 10 + H;
        if (n1 + n2 == sum) {
            std::cout << E << F << G << B << std::endl; // 输出"三羊献瑞"
            return 0;
        }
    } while (std::next_permutation(d, d + 10));
    return 0;
}
