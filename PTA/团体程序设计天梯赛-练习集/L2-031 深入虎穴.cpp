/**
 * @file L2-031 深入虎穴.cpp
 * @date 2022-06-14
 */

/*
著名的王牌间谍 007 需要执行一次任务，获取敌方的机密情报。已知情报藏在一个地下迷宫里，迷宫只有一个入口，里面有很多条通路，每条路通向一扇门。每一扇门背后或者是一个房间，或者又有很多条路，同样是每条路通向一扇门…… 他的手里有一张表格，是其他间谍帮他收集到的情报，他们记下了每扇门的编号，以及这扇门背后的每一条通路所到达的门的编号。007 发现不存在两条路通向同一扇门。

内线告诉他，情报就藏在迷宫的最深处。但是这个迷宫太大了，他需要你的帮助 —— 请编程帮他找出距离入口最远的那扇门。

输入格式：
输入首先在一行中给出正整数 N（<10 
5
 ），是门的数量。最后 N 行，第 i 行（1≤i≤N）按以下格式描述编号为 i 的那扇门背后能通向的门：

K D[1] D[2] ... D[K]
其中 K 是通道的数量，其后是每扇门的编号。

输出格式：
在一行中输出距离入口最远的那扇门的编号。题目保证这样的结果是唯一的。

输入样例：
13
3 2 3 4
2 5 6
1 7
1 8
1 9
0
2 11 10
1 13
0
0
1 12
0
0
输出样例：
12
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* dfs求最深路径 */

#include <cstdio>
#include <vector>
using namespace std;

int n = 0;
vector<vector<int>> g; // 邻接表存储图，邻接矩阵会超内存
vector<bool> in,       // 通过入度判断哪个是入口
    flags;             // dfs访问标志
int depth = 0,         // 最深深度
    ans = 0;           // 最深深度遍历到的门
int entry = 0;         // 入口

void dfs(int x = entry, int dep = 0) {
    for (const auto &i : g[x]) {
        if (!flags[i]) {
            flags[i] = true;
            dfs(i, dep + 1);
        }
    }

    if (dep > depth) {
        depth = dep;
        ans = x;
    }
}

int main() {

    scanf("%d", &n);
    g.resize(n + 1);
    in.resize(n + 1, true);
    flags.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int k = 0;
        scanf("%d", &k);
        while (k--) {
            int a = 0;
            scanf("%d", &a);
            g[i].push_back(a);
            in[a] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in[i]) {
            entry = i;
            break;
        }
    }

    flags[entry] = true;
    ans = entry; // 注意只有一个节点即初始入口的情况
    dfs();

    printf("%d", ans);

    return 0;
}