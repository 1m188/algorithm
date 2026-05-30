/*

标题：三体攻击

【题目描述】
三体人将对地球发起攻击。为了抵御攻击，地球人派出了 A × B × C 艘战舰，在太空中排成一个 A 层 B 行 C 列的立方体。其中，第 i 层第 j 行第 k 列的战舰（记为战舰 (i, j, k)）的生命值为 d(i, j, k)。

三体人将会对地球发起 m 轮"立方体攻击"，每次攻击会对一个小立方体中的所有战舰都造成相同的伤害。具体地，第 t 轮攻击用 7 个参数 lat, rat, lbt, rbt, lct, rct, ht 描述；
所有满足 i ∈ [lat, rat],j ∈ [lbt, rbt],k ∈ [lct, rct] 的战舰 (i, j, k) 会受到 ht 的伤害。如果一个战舰累计受到的总伤害超过其防御力，那么这个战舰会爆炸。

地球指挥官希望你能告诉他，第一艘爆炸的战舰是在哪一轮攻击后爆炸的。

【输入格式】
从标准输入读入数据。

第一行包括 4 个正整数 A, B, C, m；
第二行包含 A × B × C 个整数，其中第 ((i − 1)×B + (j − 1)) × C + (k − 1)+1 个数为 d(i, j, k)；
第 3 到第 m + 2 行中，第 (t − 2) 行包含 7 个正整数 lat, rat, lbt, rbt, lct, rct, ht。

【输出格式】
输出到标准输出。

输出第一个爆炸的战舰是在哪一轮攻击后爆炸的。保证一定存在这样的战舰。

【样例输入】
2 2 2 3
1 1 1 1 1 1 1 1
1 2 1 2 1 1 1
1 1 1 2 1 2 1
1 1 1 1 1 1 2

【样例输出】
2

【样例解释】
在第 2 轮攻击后，战舰 (1,1,1) 总共受到了 2 点伤害，超出其防御力导致爆炸。

【数据约定】
对于 10% 的数据，B = C = 1；
对于 20% 的数据，C = 1；
对于 40% 的数据，A × B × C, m ≤ 10, 000；
对于 70% 的数据，A, B, C ≤ 200；
对于所有数据，A × B × C ≤ 10^6, m ≤ 10^6, 0 ≤ d(i, j, k), ht ≤ 10^9。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


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
 * 分析：二分答案 + 三维差分
 *   二分攻击轮数 mid，用三维差分模拟前 mid 轮累计伤害。
 *   若存在战舰累计伤害 > 初始生命值，则答案 ≤ mid；否则答案 > mid。
 *
 *   三维差分（0-indexed，对立方体 [l1,r1]×[l2,r2]×[l3,r3] 加 h）：
 *     diff[l1][l2][l3]         += h
 *     diff[r1+1][l2][l3]       -= h   (若 r1+1 < A)
 *     diff[l1][r2+1][l3]       -= h   (若 r2+1 < B)
 *     diff[l1][l2][r3+1]       -= h   (若 r3+1 < C)
 *     diff[r1+1][r2+1][l3]     += h   (若均在界内)
 *     diff[r1+1][l2][r3+1]     += h
 *     diff[l1][r2+1][r3+1]     += h
 *     diff[r1+1][r2+1][r3+1]   -= h   (若均在界内)
 *
 *   三维前缀和（就地累加）完成后，检查 diff[pos] > life[pos]。
 *   复杂度 O(log m × (mid + A×B×C))，满足 10^6 量级要求。
 */

#include <cctype>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 1000005;

int A, B, C, m;
int life[MAXN];         // 初始生命值（int 足够，≤10^9）
ll diff[MAXN];          // 差分 / 前缀和数组（可能累积到 10^15）
int la[MAXN], ra[MAXN]; // 攻击范围：层
int lb[MAXN], rb[MAXN]; // 攻击范围：行
int lc[MAXN], rc[MAXN]; // 攻击范围：列
int ht[MAXN];           // 攻击伤害值

// 将 0-indexed 坐标 (i, j, k) 映射到扁平数组下标
inline int idx(int i, int j, int k) {
    return (i * B + j) * C + k;
}

// 检查前 mid 轮攻击后是否有战舰爆炸
bool check(int mid) {
    int total = A * B * C;
    std::memset(diff, 0, sizeof(ll) * total);

    int BxC = B * C;

    // 应用前 mid 轮攻击的三维差分
    for (int t = 0; t < mid; t++) {
        int l1 = la[t], r1 = ra[t];
        int l2 = lb[t], r2 = rb[t];
        int l3 = lc[t], r3 = rc[t];
        int h = ht[t];

        int base = idx(l1, l2, l3);
        int dr = (r1 + 1 - l1) * BxC; // 层方向偏移
        int dc = (r2 + 1 - l2) * C;   // 行方向偏移
        int dk = (r3 + 1 - l3);       // 列方向偏移

        diff[base] += h;
        if (r1 + 1 < A) diff[base + dr] -= h;
        if (r2 + 1 < B) diff[base + dc] -= h;
        if (r3 + 1 < C) diff[base + dk] -= h;
        if (r1 + 1 < A && r2 + 1 < B) diff[base + dr + dc] += h;
        if (r1 + 1 < A && r3 + 1 < C) diff[base + dr + dk] += h;
        if (r2 + 1 < B && r3 + 1 < C) diff[base + dc + dk] += h;
        if (r1 + 1 < A && r2 + 1 < B && r3 + 1 < C) diff[base + dr + dc + dk] -= h;
    }

    // 三维前缀和（就地累加）并检查
    for (int i = 0; i < A; i++) {
        int iBase = i * BxC;
        for (int j = 0; j < B; j++) {
            int pos = iBase + j * C;
            for (int k = 0; k < C; k++, pos++) {
                if (i > 0) diff[pos] += diff[pos - BxC];
                if (j > 0) diff[pos] += diff[pos - C];
                if (k > 0) diff[pos] += diff[pos - 1];
                if (i > 0 && j > 0) diff[pos] -= diff[pos - BxC - C];
                if (i > 0 && k > 0) diff[pos] -= diff[pos - BxC - 1];
                if (j > 0 && k > 0) diff[pos] -= diff[pos - C - 1];
                if (i > 0 && j > 0 && k > 0) diff[pos] += diff[pos - BxC - C - 1];

                if (diff[pos] > life[pos]) return true;
            }
        }
    }
    return false;
}

// 快速读入整数
inline int readInt() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main() {
    A = readInt();
    B = readInt();
    C = readInt();
    m = readInt();

    int total = A * B * C;
    for (int i = 0; i < total; i++) {
        life[i] = readInt();
    }

    for (int t = 0; t < m; t++) {
        la[t] = readInt() - 1;
        ra[t] = readInt() - 1;
        lb[t] = readInt() - 1;
        rb[t] = readInt() - 1;
        lc[t] = readInt() - 1;
        rc[t] = readInt() - 1;
        ht[t] = readInt();
    }

    // 二分答案
    int lo = 1, hi = m, ans = m;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
