/*

立方尾不变

有些数字的立方的末尾正好是该数字本身。
比如：1,4,5,6,9,24,25,....

请你计算一下，在10000以内的数字中（指该数字，并非它立方后的数值），符合这个特征的正整数一共有多少个。

请提交该整数，不要填写任何多余的内容。
*/

/*
 * 解题思路：
 * 对于每个正整数 n < 10000，计算 n^3，
 * 检查 n^3 的末尾是否与 n 相同。
 * 即 n^3 % (10^len(n)) == n，其中 len(n) 为 n 的位数。
 */
#include <iostream>

int main() {
    int cnt = 0;
    for (long long n = 1; n < 10000; n++) {
        // 计算 n 的位数对应的模数（10^位数）
        long long mod = 1;
        for (long long tmp = n; tmp; tmp /= 10)
            mod *= 10;
        if ((n * n * n) % mod == n)
            cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}
