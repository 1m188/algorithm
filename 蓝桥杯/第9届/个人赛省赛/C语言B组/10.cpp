/*

标题：乘积最大

给定N个整数A1, A2, ... AN。请你从中选出K个数，使其乘积最大。

请你求出最大的乘积，由于乘积可能超出整型范围，你只需输出乘积除以1000000009的余数。

注意，如果X<0， 我们定义X除以1000000009的余数是负(-X)除以1000000009的余数。
即：0-((0-x) % 1000000009)

【输入格式】
第一行包含两个整数N和K。
以下N行每行一个整数Ai。

对于40%的数据，1 <= K <= N <= 100
对于60%的数据，1 <= K <= 1000
对于100%的数据，1 <= K <= N <= 100000  -100000 <= Ai <= 100000

【输出格式】
一个整数，表示答案。


【输入样例】
5 3
-100000
-10000
2
100000
10000

【输出样例】
999100009

再例如：
【输入样例】
5 3
-100000
-100000
-2
-100000
-100000

【输出样例】
-999999829


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。


*/

#include <algorithm>
#include <cmath>
#include <cstdio>

const int MOD = 1000000009;
const int N = 100005;
long long a[N];

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 1;
    for (int i = 0; i < n; ++i)
        if (scanf("%lld", a + i) != 1) return 1;

    std::sort(a, a + n);

    long long mag = 1; // magnitude modulo MOD, always >= 0
    int sign = 1;      // sign of the final product
    int l = 0, r = n - 1;

    // odd K: pick the rightmost element first to make remaining K even
    if (k & 1) {
        mag = mag * std::llabs(a[r]) % MOD;
        if (a[r] < 0) sign = -sign;
        --r;
        --k;
    }

    while (k) {
        long long left = a[l] * a[l + 1];
        long long right = a[r] * a[r - 1];

        // Compare actual contribution: sign*left vs sign*right
        if (left * sign > right * sign) {
            long long m = left % MOD;
            if (m < 0) m += MOD;
            mag = mag * m % MOD;
            if (left < 0) sign = -sign;
            l += 2;
        } else {
            long long m = right % MOD;
            if (m < 0) m += MOD;
            mag = mag * m % MOD;
            if (right < 0) sign = -sign;
            r -= 2;
        }
        k -= 2;
    }

    if (sign < 0) mag = -mag;
    printf("%lld\n", mag);
    return 0;
}
