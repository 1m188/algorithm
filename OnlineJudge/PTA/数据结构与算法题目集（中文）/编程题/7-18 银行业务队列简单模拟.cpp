/*
设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍
—— 即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。
给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。
假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。

输入格式:
输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。
编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。

输出格式:
按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。

输入样例:
8 2 1 3 9 4 11 13 15

输出样例:
1 3 2 9 11 4 13 15

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int N = 0;
    cin >> N;

    vector<queue<int>> win(2);

    while (N--) {
        int x = 0;
        cin >> x;

        if (x % 2)
            win[0].push(x);
        else
            win[1].push(x);
    }

    vector<int> ans;

    while (!win[0].empty() && !win[1].empty()) {
        ans.push_back(win[0].front());
        win[0].pop();
        if (!win[0].empty()) {
            ans.push_back(win[0].front());
            win[0].pop();
        }
        ans.push_back(win[1].front());
        win[1].pop();
    }
    while (!win[0].empty()) {
        ans.push_back(win[0].front());
        win[0].pop();
    }
    while (!win[1].empty()) {
        ans.push_back(win[1].front());
        win[1].pop();
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ' ' << ans[i];

    return 0;
}