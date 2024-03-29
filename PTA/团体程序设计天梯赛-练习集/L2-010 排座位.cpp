/**
 * @file L2-010 排座位.cpp
 * @date 2022-05-24
 */

/*
布置宴席最微妙的事情，就是给前来参宴的各位宾客安排座位。无论如何，总不能把两个死对头排到同一张宴会桌旁！这个艰巨任务现在就交给你，对任何一对客人，请编写程序告诉主人他们是否能被安排同席。

输入格式：
输入第一行给出3个正整数：N（≤100），即前来参宴的宾客总人数，则这些人从1到N编号；M为已知两两宾客之间的关系数；K为查询的条数。随后M行，每行给出一对宾客之间的关系，格式为：宾客1 宾客2 关系，其中关系为1表示是朋友，-1表示是死对头。注意两个人不可能既是朋友又是敌人。最后K行，每行给出一对需要查询的宾客编号。

这里假设朋友的朋友也是朋友。但敌人的敌人并不一定就是朋友，朋友的敌人也不一定是敌人。只有单纯直接的敌对关系才是绝对不能同席的。

输出格式：
对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出No problem；如果他们之间并不是朋友，但也不敌对，则输出OK；如果他们之间有敌对，然而也有共同的朋友，则输出OK but...；如果他们之间只有敌对关系，则输出No way。

输入样例：
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
输出样例：
No problem
OK
OK but...
No way
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
*/

/* 朋友的朋友也是朋友，这里用了一个map记录一个人到他的朋友圈的映射，用bfs遍历图里的每一个连通块，
记录映射，另外看到网上有一种方法是并查集做的，应该也可以。 */

#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> circle; // 朋友圈，记录 编号-朋友圈 映射
vector<vector<int>> graph;      // 邻接矩阵图

/**
 * @brief bfs遍历图里所有连通块，找出每个人的朋友圈并记录
 */
void bfs() {
    const int n = graph.size() - 1;
    vector<bool> flags(n + 1);

    int num = 1;

    for (int i = 1; i <= n; i++) {
        if (!flags[i]) {
            queue<int> que({i});
            flags[i] = true;
            circle[i] = num;
            while (!que.empty()) {
                int x = que.front();
                que.pop();
                for (int j = 1; j <= n; j++) {
                    if (!flags[j] && graph[x][j] == 1) {
                        flags[j] = true;
                        que.push(j);
                        circle[j] = num;
                    }
                }
            }
            num++;
        }
    }
}

int main() {

    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);

    graph.resize(n + 1, vector<int>(n + 1));

    while (m--) {
        int a = 0, b = 0, c = 0;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = graph[b][a] = c;
    }

    bfs();

    while (k--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (circle[a] == circle[b] && graph[a][b] != -1)
            printf("No problem\n");
        else if (circle[a] != circle[b] && graph[a][b] != -1)
            printf("OK\n");
        else if (circle[a] == circle[b] && graph[a][b] == -1)
            printf("OK but...\n");
        else if (circle[a] != circle[b] && graph[a][b] == -1)
            printf("No way\n");
    }

    return 0;
}