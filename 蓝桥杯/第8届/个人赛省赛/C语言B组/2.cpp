/*
 * 标题：等差素数列
 *
 * 2,3,5,7,11,13,....是素数序列。
 * 类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
 * 上边的数列公差为30，长度为6。
 *
 * 2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
 * 这是数论领域一项惊人的成果！
 *
 * 有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
 *
 * 长度为10的等差素数列，其公差最小值是多少？
 *
 * 注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。
 *
 * 【求解思路】
 *   长度为 10 的等差素数数列，公差必为 2×3×5×7 = 210 的倍数
 *   （否则对某个 ≤7 的素数 p，AP 中会出现 p 的倍数）。
 *   起始素数须 ≥ 11（否则起始值本身会因 k·p 位置产生合数）。
 *   以 210 为步长枚举公差，对每个起始素数检查 10 项是否均为素数，
 *   最先找到的是 d=210，起始素数 199。
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5000000; // 筛法范围足够覆盖搜索空间
vector<bool> is_prime;

// 埃氏筛生成素数表
void sieve() {
    is_prime.assign(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    sieve();

    // 公差必为 210 的倍数，从 210 开始逐倍搜索
    for (int d = 210;; d += 210) {
        // 起始素数须 ≥ 11，且 10 项不能超出 MAX
        for (int p = 11; p + 9LL * d <= MAX; p++) {
            if (!is_prime[p]) continue;
            bool ok = true;
            for (int k = 1; k <= 9; k++) {
                if (!is_prime[p + k * d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << d << endl;
                return 0;
            }
        }
    }
    return 0;
}
