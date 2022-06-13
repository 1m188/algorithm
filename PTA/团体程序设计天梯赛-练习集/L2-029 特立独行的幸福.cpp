/**
 * @file L2-029 特立独行的幸福.cpp
 * @date 2022-06-13
 */

/*
对一个十进制数的各位数字做一次平方和，称作一次迭代。如果一个十进制数能通过若干次迭代得到 1，就称该数为幸福数。1 是一个幸福数。此外，例如 19 经过 1 次迭代得到 82，2 次迭代后得到 68，3 次迭代后得到 100，最后得到 1。则 19 就是幸福数。显然，在一个幸福数迭代到 1 的过程中经过的数字都是幸福数，它们的幸福是依附于初始数字的。例如 82、68、100 的幸福是依附于 19 的。而一个特立独行的幸福数，是在一个有限的区间内不依附于任何其它数字的；其独立性就是依附于它的的幸福数的个数。如果这个数还是个素数，则其独立性加倍。例如 19 在区间[1, 100] 内就是一个特立独行的幸福数，其独立性为 2×4=8。

另一方面，如果一个大于1的数字经过数次迭代后进入了死循环，那这个数就不幸福。例如 29 迭代得到 85、89、145、42、20、4、16、37、58、89、…… 可见 89 到 58 形成了死循环，所以 29 就不幸福。

本题就要求你编写程序，列出给定区间内的所有特立独行的幸福数和它的独立性。

输入格式：
输入在第一行给出闭区间的两个端点：1<A<B≤10 
4
 。

输出格式：
按递增顺序列出给定闭区间 [A,B] 内的所有特立独行的幸福数和它的独立性。每对数字占一行，数字间以 1 个空格分隔。

如果区间内没有幸福数，则在一行中输出 SAD。

输入样例 1：
10 40
输出样例 1：
19 8
23 6
28 3
31 4
32 3
注意：样例中，10、13 也都是幸福数，但它们分别依附于其他数字（如 23、31 等等），所以不输出。其它数字虽然其实也依附于其它幸福数，但因为那些数字不在给定区间 [10, 40] 内，所以它们在给定区间内是特立独行的幸福数。

输入样例 2：
110 120
输出样例 2：
SAD
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 注意细节，挨个计算是否是幸福数，并且计数其特立独行的次数，中间的幸福数都不是特立独行，
中间的层数不需要临时储存，因为有些中间数会到区间以外 */

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
    bool f = true; // 是否是特立独行的幸福数
    int hap = 0;   // 幸福程度
};

vector<Node> vec;
int a = 0, b = 0;

/**
 * @brief 判断质数
 * @param x 
 * @return true 
 * @return false 
 */
bool is_prime(int x) {
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    double a = sqrt(x);
    for (int i = 3; i <= a; i += 2)
        if (x % i == 0) return false;
    return true;
}

/**
 * @brief 求取各位平方和
 * @param x 
 * @return int 
 */
int bpsum(int x) {
    int ans = 0;
    while (x) {
        ans += pow(x % 10, 2);
        x /= 10;
    }
    return ans;
}

/**
 * @brief 求某个数的幸福程度，并将中间幸福数置为false，如果不是幸福数则返回负数
 * @param x 
 * @return int 
 */
int calc(int x) {
    unordered_set<int> uset;
    int num = 0;
    int tmp = x;
    while (tmp != 1) {
        if (uset.find(tmp) != uset.end()) return -1;
        uset.insert(tmp);
        tmp = bpsum(tmp);
        num++;
        if (tmp >= a && tmp <= b) vec[tmp - a].f = false;
    }

    return is_prime(x) ? 2 * num : num;
}

int main() {

    scanf("%d %d", &a, &b);
    vec.resize(b - a + 1);

    for (int i = 0; i < vec.size(); i++) {
        if (!vec[i].f) continue;
        int num = calc(i + a);
        if (num < 0)
            vec[i].f = false;
        else
            vec[i].hap = num;
    }

    bool f = false;
    for (int i = 0; i < vec.size(); i++) {
        if (!vec[i].f) continue;
        printf("%d %d\n", i + a, vec[i].hap);
        f = true;
    }
    if (!f) printf("SAD");

    return 0;
}