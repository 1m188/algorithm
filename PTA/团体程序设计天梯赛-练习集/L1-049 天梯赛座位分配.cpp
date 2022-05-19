/**
 * @file L1-049 天梯赛座位分配.cpp
 * @date 2022-05-19
 */

/*
天梯赛每年有大量参赛队员，要保证同一所学校的所有队员都不能相邻，分配座位就成为一件比较麻烦的事情。
为此我们制定如下策略：假设某赛场有 N 所学校参赛，第 i 所学校有 M[i] 支队伍，每队 10 位参赛选手。
令每校选手排成一列纵队，第 i+1 队的选手排在第 i 队选手之后。从第 1 所学校开始，
各校的第 1 位队员顺次入座，然后是各校的第 2 位队员…… 以此类推。
如果最后只剩下 1 所学校的队伍还没有分配座位，则需要安排他们的队员隔位就坐。
本题就要求你编写程序，自动为各校生成队员的座位号，从 1 开始编号。

输入格式：
输入在一行中给出参赛的高校数 N （不超过100的正整数）；
第二行给出 N 个不超过10的正整数，其中第 i 个数对应第 i 所高校的参赛队伍数，数字间以空格分隔。

输出格式：
从第 1 所高校的第 1 支队伍开始，顺次输出队员的座位号。
每队占一行，座位号间以 1 个空格分隔，行首尾不得有多余空格。
另外，每所高校的第一行按“#X”输出该校的编号X，从 1 开始。

输入样例：
3
3 4 2

输出样例：
#1
1 4 7 10 13 16 19 22 25 28
31 34 37 40 43 46 49 52 55 58
61 63 65 67 69 71 73 75 77 79
#2
2 5 8 11 14 17 20 23 26 29
32 35 38 41 44 47 50 53 56 59
62 64 66 68 70 72 74 76 78 80
82 84 86 88 90 92 94 96 98 100
#3
3 6 9 12 15 18 21 24 27 30
33 36 39 42 45 48 51 54 57 60

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 比较繁琐，注意位置的设置以及输出的格式 */

#include <cstdio>
#include <vector>
using namespace std;

vector<int> team;         // 每个学校的参赛队伍数目
vector<vector<int>> seat; // i学校里每个参赛队员的座位号

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);
    team.resize(n);
    seat.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &team[i]);
}

/**
 * @brief 计算座位号
 */
void calc() {

    // 这里预留出最多人的学校，后面对他们连续的座位要单独安排
    int maxidx = 0;
    for (int i = 0; i < team.size(); i++)
        if (team[i] > team[maxidx])
            maxidx = i;

    int sum = 0;
    for (int &i : team) {
        i *= 10;
        sum += i;
    }

    // 对所有人按序安排座位
    for (int i = 0, seatid = 1; sum; i = (i + 1) % team.size()) {
        if (!team[i])
            continue;

        team[i]--, sum--;
        seat[i].push_back(seatid++);
    }

    // 对连续的座位单独安排
    int idx = 1;
    auto &vec = seat[maxidx];
    while (idx < vec.size() && vec[idx] != vec[idx - 1] + 1)
        idx++;
    while (idx < vec.size()) {
        vec[idx] = vec[idx - 1] + 2;
        idx++;
    }
}

// 格式化输出
void print() {
    int n = team.size();

    for (int i = 1; i <= n; i++) {
        printf("#%d\n", i);
        int idx = 0;
        while (idx < seat[i - 1].size()) {
            printf("%d", seat[i - 1][idx]);
            for (int j = idx + 1; j < idx + 10; j++)
                printf(" %d", seat[i - 1][j]);
            printf("\n");
            idx += 10;
        }
    }
}

int main() {
    input();
    calc();
    print();
    return 0;
}