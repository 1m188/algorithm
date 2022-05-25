/**
 * @file L2-013 红色警报.cpp
 * @date 2022-05-25
 */

/*
战争中保持各个城市间的连通性非常重要。本题要求你编写一个报警程序，当失去一个城市导致国家被分裂为多个无法连通的区域时，就发出红色警报。注意：若该国本来就不完全连通，是分裂的k个区域，而失去一个城市并不改变其他城市之间的连通性，则不要发出警报。

输入格式：
输入在第一行给出两个整数N（0 < N ≤ 500）和M（≤ 5000），分别为城市个数（于是默认城市从0到N-1编号）和连接两城市的通路条数。随后M行，每行给出一条通路所连接的两个城市的编号，其间以1个空格分隔。在城市信息之后给出被攻占的信息，即一个正整数K和随后的K个被攻占的城市的编号。

注意：输入保证给出的被攻占的城市编号都是合法的且无重复，但并不保证给出的通路没有重复。

输出格式：
对每个被攻占的城市，如果它会改变整个国家的连通性，则输出Red Alert: City k is lost!，其中k是该城市的编号；否则只输出City k is lost.即可。如果该国失去了最后一个城市，则增加一行输出Game Over.。

输入样例：
5 4
0 1
1 3
3 0
0 4
5
1 2 0 4 3
输出样例：
City 1 is lost.
City 2 is lost.
Red Alert: City 0 is lost!
City 4 is lost.
City 3 is lost.
Game Over.
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 计算图里某些部分的连通性，当连通性数目不变或者变小的时候不发出警报，当连通性
数目变大的时候发出警报 */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<bool>> graph; // 邻接矩阵图
vector<bool> city;          // 有哪些城市未被占领（true）

/**
 * @brief 输入
 */
void input() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    graph.resize(n, vector<bool>(n));
    city.resize(n, true);

    while (m--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = true;
    }
}

/**
 * @brief bfs求连通性数目
 * @return int 连通块的数目
 */
int bfs() {
    int n = graph.size();

    vector<bool> flags(n);
    queue<int> que;
    int num = 0; // 连通块数目

    for (int i = 0; i < n; i++) {

        if (!flags[i] && city[i]) {

            flags[i] = true;
            que.push(i);
            num++;

            while (!que.empty()) {
                int x = que.front();
                que.pop();
                for (int j = 0; j < n; j++) {
                    if (!flags[j] && city[j] && graph[x][j]) {
                        flags[j] = true;
                        que.push(j);
                    }
                }
            }
        }
    }

    return num;
}

/**
 * @brief 计算并输出
 */
void calc() {

    int init = bfs(); // 当前连通块数目

    int k = 0;
    scanf("%d", &k);

    int num = city.size();

    while (k--) {
        int x = 0;
        scanf("%d", &x);

        city[x] = false;
        num--;

        int t = bfs();
        if (t <= init) { // 连通块数目变小或不变不发出警报
            printf("City %d is lost.\n", x);
        } else { // 变大发出警报
            printf("Red Alert: City %d is lost!\n", x);
        }
        init = t; // 更新当前连通块数目
    }

    // 城市被占领完了
    if (num == 0) {
        printf("Game Over.");
    }
}

int main() {
    input();
    calc();
    return 0;
}