/**
 * @file L2-024 部落.cpp
 * @date 2022-06-12
 */

/*
在一个社区里，每个人都有自己的小圈子，还可能同时属于很多不同的朋友圈。我们认为朋友的朋友都算在一个部落里，于是要请你统计一下，在一个给定社区中，到底有多少个互不相交的部落？并且检查任意两个人是否属于同一个部落。

输入格式：
输入在第一行给出一个正整数N（≤10 
4
 ），是已知小圈子的个数。随后N行，每行按下列格式给出一个小圈子里的人：

K P[1] P[2] ⋯ P[K]

其中K是小圈子里的人数，P[i]（i=1,⋯,K）是小圈子里每个人的编号。这里所有人的编号从1开始连续编号，最大编号不会超过10 
4
 。

之后一行给出一个非负整数Q（≤10 
4
 ），是查询次数。随后Q行，每行给出一对被查询的人的编号。

输出格式：
首先在一行中输出这个社区的总人数、以及互不相交的部落的个数。随后对每一次查询，如果他们属于同一个部落，则在一行中输出Y，否则输出N。

输入样例：
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
输出样例：
10 2
Y
N
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
*/

/* 并查集，一个部落里以其id最小者为根 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> circle;
vector<int> ufset;
int maxid = 0, // 最大id，题目里说从1开始连续编号，最大编号就是整个人数
    num = 0;   // 多少互不相交的部落

/**
 * @brief 并查集-查找某个节点的根
 * @param x 
 * @return int 
 */
int uffind(int x) {
    if (ufset[x] == x) return x;
    return ufset[x] = uffind(ufset[x]); // 路径压缩
}

/**
 * @brief 并查集-合并两个节点所在集合
 * @param x 
 * @param y 
 */
void ufunion(int x, int y) {
    int xx = uffind(x), yy = uffind(y); // 注意这里合并是对两者的根进行合并
    if (xx < yy) ufset[yy] = xx;
    ufset[xx] = yy;
}

void input() {
    int n = 0;
    scanf("%d", &n);
    circle.resize(n);

    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);
        circle[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &circle[i][j]);
        maxid = max(maxid, *max_element(circle[i].begin(), circle[i].end()));
    }
}

void calc() {
    ufset.resize(maxid + 1);
    for (int i = 0; i < ufset.size(); i++)
        ufset[i] = i;

    for (const auto &e : circle) {
        int root = *min_element(e.begin(), e.end());
        for (const auto &n : e) {
            ufunion(n, root);
        }
    }

    for (int i = 1; i < ufset.size(); i++) {
        num += uffind(i) == i; // 计数不相交的部落数，顺便路径压缩
    }

    printf("%d %d\n", maxid, num);
}

void query() {
    int q = 0;
    scanf("%d", &q);
    while (q--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (ufset[a] == ufset[b])
            printf("Y\n");
        else
            printf("N\n");
    }
}

int main() {
    input();
    calc();
    query();
    return 0;
}