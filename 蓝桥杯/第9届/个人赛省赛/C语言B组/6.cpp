/*

标题：递增三元组

给定三个整数数组
A = [A1, A2, ... AN],
B = [B1, B2, ... BN],
C = [C1, C2, ... CN]，
请你统计有多少个三元组(i, j, k) 满足：
1. 1 <= i, j, k <= N
2. Ai < Bj < Ck

【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, ... AN。
第三行包含N个整数B1, B2, ... BN。
第四行包含N个整数C1, C2, ... CN。

对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000

【输出格式】
一个整数表示答案

【样例输入】
3
1 1 1
2 2 2
3 3 3

【样例输出】
27


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

/*
 * 分析：
 *   对每个 Bj，统计 A 中有多少个数小于 Bj，C 中有多少个数大于 Bj，
 *   两者相乘即为以 Bj 为中心的三元组数量，累加所有 Bj 的结果。
 *   使用排序 + 二分查找，时间复杂度 O(N log N)。
 *   答案可能超过 int 范围，使用 long long。
 */

#include "algorithm"
#include "iostream"

const int MAXN = 100000;

int A[MAXN], B[MAXN], C[MAXN];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    for (int i = 0; i < N; i++)
        std::cin >> B[i];
    for (int i = 0; i < N; i++)
        std::cin >> C[i];

    // 对 A 和 C 排序以便二分查找
    std::sort(A, A + N);
    std::sort(C, C + N);

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int b = B[i];

        // A 中小于 b 的个数：lower_bound 返回第一个 >= b 的位置
        int countA = std::lower_bound(A, A + N, b) - A;

        // C 中大于 b 的个数：upper_bound 返回第一个 > b 的位置
        int countC = C + N - std::upper_bound(C, C + N, b);

        ans += (long long)countA * countC;
    }

    std::cout << ans << std::endl;

    return 0;
}
