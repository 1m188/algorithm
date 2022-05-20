/**
 * @file 7-7 新式六合彩.cpp
 * @date 2022-05-20
 */

/*
新式六合彩跟传统六合彩其实没有半点关系，只是姥姥为了出题杜撰出来的一种玩法——每位玩家可以下注一个六位数，如果跟开出来的幸运六位数最接近就可以获奖（所谓最接近，是指该数字与幸运数之差的绝对值最小）。

但规则如果这么简单就没什么可玩的了…… 我们把规则搞复杂一点：首先创建一个有 n×m 个格子的矩阵，保证格子总数不小于玩家总数，可以把所有玩家下注的数字随机放进格子里，每个格子最多放一个。然后我们随机生成一个幸运行号 r （1≤r≤n）和幸运列号 c （1≤c≤m），再随机生成一个幸运六位数。中奖者是第 r 行和第 c 列的所有六位数中与幸运数最接近的那个数字的主人。

本题就请你写个程序实现这个抽奖功能。

输入格式：
输入第一行给出 2 个正整数 n 和 m（1≤n,m≤1000），随后 n 行，每行给出 m 个数字，对应该位置格子里玩家下注的数字。如果这个格子是空的，就用 −1 表示。最后一行给出幸运行号 r、幸运列号 c 和幸运六位数。同行数字间以空格分隔。

注意：行号从上向下递增，列号从左向右递增，均从 1 开始计数。

输出格式：
按照 (行号:列号) 的格式输出中奖者的位置。如果中奖者不唯一，则按照首先在幸运行中从左到右，然后在幸运列中从上到下的顺序输出，每行输出一位中奖者的位置。注意同一个位置只能输出一次。题目保证至少存在一位中奖者。

输入样例：
4 5
233333 000001 -1 888888 666666
001010 369624 777888 -1 999999
480735 100000 591846 369623 123123
456456 591846 000000 501000 233333
2 3 480735
输出样例：
(2:2)
(3:3)
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

// 1  2  测试点错误

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    int r = 0, c = 0, target = 0;
    scanf("%d %d %d", &r, &c, &target);

    vector<pair<int, int>> ans;
    int diff = 1e7;

    for (int i = 0; i < m; i++) {

        /* 针对测试点1，2错误的修复（题目集已关闭未验证） */
        // 和六合彩数目比较的数字必须是有人下注的地方
        if (matrix[r - 1][i] == -1)
            continue;
        /**************************************************/

        int tdiff = abs(matrix[r - 1][i] - target);
        if (tdiff < diff) {
            ans.clear();
            diff = tdiff;
            ans.push_back({r, i + 1});
        } else if (tdiff == diff)
            ans.push_back({r, i + 1});
    }

    for (int i = 0; i < n; i++) {
        if (i == r - 1)
            continue;

        /* 针对测试点1，2错误的修复（题目集已关闭未验证） */
        // 和六合彩数目比较的数字必须是有人下注的地方
        if (matrix[i][c - 1] == -1)
            continue;
        /**************************************************/

        int tdiff = abs(matrix[i][c - 1] - target);
        if (tdiff < diff) {
            ans.clear();
            diff = tdiff;
            ans.push_back({i + 1, c});
        } else if (tdiff == diff)
            ans.push_back({i + 1, c});
    }

    for (const auto &e : ans)
        printf("(%d:%d)\n", e.first, e.second);

    return 0;
}