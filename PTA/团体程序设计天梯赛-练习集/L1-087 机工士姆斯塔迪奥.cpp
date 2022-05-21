/**
 * @file L1-087 机工士姆斯塔迪奥.cpp
 * @date 2022-05-21
 */

/*
在 MMORPG《最终幻想14》的副本“乐欲之所瓯博讷修道院”里，BOSS 机工士姆斯塔迪奥将会接受玩家的挑战。

你需要处理这个副本其中的一个机制：N×M 大小的地图被拆分为了 N×M 个 1×1 的格子，BOSS 会选择若干行或/及若干列释放技能，玩家不能站在释放技能的方格上，否则就会被击中而失败。

给定 BOSS 所有释放技能的行或列信息，请你计算出最后有多少个格子是安全的。

输入格式:
输入第一行是三个整数 N,M,Q (1≤N×M≤10 
5
 ，0≤Q≤1000)，表示地图为 N 行 M 列大小以及选择的行/列数量。

接下来 Q 行，每行两个数 T 
i
​
 ,C 
i
​
 ，其中 T 
i
​
 =0 表示 BOSS 选择的是一整行，T 
i
​
 =1 表示选择的是一整列，C 
i
​
  为选择的行号/列号。行和列的编号均从 1 开始。

输出格式:
输出一个数，表示安全格子的数量。

输入样例:
5 5 3
0 2
0 4
1 3
输出样例:
12
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {

    int n = 0, m = 0, q = 0;
    scanf("%d %d %d", &n, &m, &q);

    int num = 0;
    unordered_set<int> row, col;

    while (q--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        if (a == 0 && row.find(b) == row.end()) {
            row.insert(b);
            num += m;
        } else if (a == 1 && col.find(b) == col.end()) {
            col.insert(b);
            num += n;
        }
    }

    printf("%zu", n * m - num + row.size() * col.size());

    return 0;
}