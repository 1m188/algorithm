/**
 * @file L2-025 分而治之.cpp
 * @date 2022-06-12
 */

/*
分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

输入格式：
输入在第一行给出两个正整数 N 和 M（均不超过10 000），分别为敌方城市个数（于是默认城市从 1 到 N 编号）和连接两城市的通路条数。随后 M 行，每行给出一条通路所连接的两个城市的编号，其间以一个空格分隔。在城市信息之后给出参谋部的系列方案，即一个正整数 K （≤ 100）和随后的 K 行方案，每行按以下格式给出：

Np v[1] v[2] ... v[Np]
其中 Np 是该方案中计划攻下的城市数量，后面的系列 v[i] 是计划攻下的城市编号。

输出格式：
对每一套方案，如果可行就输出YES，否则输出NO。

输入样例：
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 10
2 4
5
4 10 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
输出样例：
NO
YES
YES
NO
NO
代码长度限制
16 KB
时间限制
600 ms
内存限制
64 MB
*/

/* 不能用邻接矩阵，遍历每个节点会超时，用map，保存每个节点直接相连的节点，节约时间 */

#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int n = 0, m = 0, k = 0;
unordered_map<int, vector<int>> g; // 图，key是节点编号，其内容是与其直接连接的节点编号
vector<bool> used;

void build_graph() {
    scanf("%d %d", &n, &m);
    used.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void calc() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int np = 0;
        scanf("%d", &np);
        while (np--) {
            int a = 0;
            scanf("%d", &a);
            used[a] = true;
        }

        bool f = true;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            for (const int &x : g[i]) {
                if (!used[x]) { // 如果直接相连的节点有没被占领的
                    f = false;
                    break;
                }
            }
            if (!f) break;
        }

        printf(f ? "YES\n" : "NO\n");
        for (int i = 1; i <= n; i++)
            used[i] = false;
    }
}

int main() {
    build_graph();
    calc();
    return 0;
}