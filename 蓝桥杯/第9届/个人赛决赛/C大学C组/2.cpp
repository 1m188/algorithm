/*

标题：最大乘积

把 1~9 这9个数字分成两组，中间插入乘号，
有的时候，它们的乘积也只包含1~9这9个数字，而且每个数字只出现1次。

比如：
984672 * 351 = 345619872
98751 * 3462 = 341875962
9 * 87146325 = 784316925
...

符合这种规律的算式还有很多，请你计算在所有这些算式中，乘积最大是多少？

注意，需要提交的是一个整数，表示那个最大的积，不要填写任何多余的内容。
（只提交乘积，不要提交整个算式）

*/

#include <algorithm>
#include <iostream>
using namespace std;

// 检查 n 是否恰好使用数字 1~9 各一次（且没有 0）
bool isPandigital19(long long n) {
    if (n < 123456789 || n > 987654321) return false;
    int mask = 0;
    while (n) {
        int d = n % 10;
        if (d == 0) return false;
        mask |= (1 << d);
        n /= 10;
    }
    return mask == 0x3FE; // 0b1111111110，bit1~bit9 全置位
}

int main() {
    int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long maxProduct = 0;

    do {
        // 尝试 8 种切分位置 (1~8)，左右至少各 1 位
        for (int split = 1; split <= 8; ++split) {
            // 构造左半部分数字
            long long left = 0;
            for (int i = 0; i < split; ++i) {
                left = left * 10 + digits[i];
            }
            // 构造右半部分数字
            long long right = 0;
            for (int i = split; i < 9; ++i) {
                right = right * 10 + digits[i];
            }
            long long product = left * right;
            if (isPandigital19(product) && product > maxProduct) {
                maxProduct = product;
            }
        }
    } while (next_permutation(digits, digits + 9));

    cout << maxProduct << endl;
    return 0;
}
