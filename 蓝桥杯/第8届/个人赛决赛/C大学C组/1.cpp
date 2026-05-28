/*

标题：哥德巴赫分解

哥德巴赫猜想认为：不小于4的偶数都可以表示为两个素数的和。

你不需要去证明这个定理，但可以通过计算机对有限数量的偶数进行分解，验证是否可行。

实际上，一般一个偶数会有多种不同的分解方案，我们关心包含较小素数的那个方案。
对于给定数值范围，我们想知道这些包含较小素数方案中最大的素数是多少。

比如，100以内，这个数是19，它由98的分解贡献。

你需要求的是10000以内，这个数是多少？

注意，需要提交的是一个整数，不要填写任何多余的内容（比如，说明性的文字）

*/

#include <iostream>

using namespace std;

const int N = 10000;

int main() {
    // 筛法求素数
    bool is_prime[N + 1];
    for (int i = 2; i <= N; i++)
        is_prime[i] = true;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int ans = 0;
    for (int n = 4; n <= N; n += 2) {
        // 找最小的素数 p 使得 n-p 也是素数
        for (int p = 2; p <= n / 2; p++) {
            if (is_prime[p] && is_prime[n - p]) {
                if (p > ans) ans = p;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
