/*

奇妙的数字

小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？

请填写该数字，不要填写任何多余的内容。
*/

/*
 * 解题思路：
 * 设该数字为 n，则 n^2 和 n^3 的各位数字合在一起恰好为 0~9 各出现一次。
 * n^2 与 n^3 的总位数必为 10（因 0~9 共 10 个数字，各出现一次）。
 * n < 100（n=100 时总位数已超 10），枚举 1~99 即可。
 */
#include <iostream>
#include <string>

int main() {
    for (int n = 1; n < 100; n++) {
        std::string s = std::to_string(n * n) + std::to_string(n * n * n);
        if (s.length() != 10)
            continue;
        // 检查是否 0~9 各出现一次
        int cnt[10] = {0};
        for (char c : s)
            cnt[c - '0']++;
        bool allOne = true;
        for (int i = 0; i < 10; i++)
            if (cnt[i] != 1) {
                allOne = false;
                break;
            }
        if (allOne) {
            std::cout << n << std::endl;
            return 0;
        }
    }
    return 0;
}
