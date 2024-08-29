/*

标题：方格填数

在2行5列的格子中填入1到10的数字。
要求：
相邻的格子中的数，右边的大于左边的，下边的大于上边的。

如【图1.png】所示的2种，就是合格的填法。
1 2 3 5 8                   1 3 5 6 7
4 6 7 9 10                  2 4 8 9 10

请你计算一共有多少种可能的方案。

请提交该整数，不要填写任何多余的内容（例如：说明性文字）。

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> gezi(2, vector<int>(5, 0));
vector<bool> flags(10 + 1, false);
int res = 0;

void dfs(int x = 0, int y = 0) {
    if (x == 2) {
        res++;
    } else {
        for (int i = 1; i <= 10; i++) {
            if (flags[i]) continue;
            if (x - 1 >= 0 && i < gezi[x - 1][y]) continue;
            if (y - 1 >= 0 && i < gezi[x][y - 1]) continue;
            flags[i] = true;
            gezi[x][y] = i;
            if (y + 1 >= 5)
                dfs(x + 1, 0);
            else
                dfs(x, y + 1);
            gezi[x][y] = 0;
            flags[i] = false;
        }
    }
}

int main() {
    dfs();
    cout << res << '\n';
    return 0;
}