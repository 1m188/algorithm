/**
 * @file L2-023 图着色问题.cpp
 * @date 2022-06-12
 */

/*
图着色问题是一个著名的NP完全问题。给定无向图G=(V,E)，问可否用K种颜色为V中的每一个顶点分配一种颜色，使得不会有两个相邻顶点具有同一种颜色？

但本题并不是要你解决这个着色问题，而是对给定的一种颜色分配，请你判断这是否是图着色问题的一个解。

输入格式：
输入在第一行给出3个整数V（0<V≤500）、E（≥0）和K（0<K≤V），分别是无向图的顶点数、边数、以及颜色数。顶点和颜色都从1到V编号。随后E行，每行给出一条边的两个端点的编号。在图的信息给出之后，给出了一个正整数N（≤20），是待检查的颜色分配方案的个数。随后N行，每行顺次给出V个顶点的颜色（第i个数字表示第i个顶点的颜色），数字间以空格分隔。题目保证给定的无向图是合法的（即不存在自回路和重边）。

输出格式：
对每种颜色分配方案，如果是图着色问题的一个解则输出Yes，否则输出No，每句占一行。

输入样例：
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
输出样例：
Yes
Yes
No
No
代码长度限制
16 KB
时间限制
300 ms
内存限制
64 MB
*/

/* 遍历每个节点，暴力判断即可，需要注意的是颜色的种类必须要为k */

#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

int v = 0, e = 0, k = 0, n = 0;
vector<vector<bool>> g;
vector<int> color;

bool check() {
    // 颜色种类必须要为k
    // 这里注意因为颜色储存从索引1开始，不要把前面的索引0的默认值也算进去了
    if (unordered_set<int>(color.begin() + 1, color.end()).size() != k) return false;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (g[i][j]) {
                if (color[i] == color[j]) return false;
            }
        }
    }
    return true;
}

int main() {

    scanf("%d %d %d", &v, &e, &k);
    g.resize(v + 1, vector<bool>(v + 1));
    color.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = true;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= v; j++)
            scanf("%d", &color[j]);
        if (check())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}