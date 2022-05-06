/*
借助堆栈以非递归（循环）方式求解汉诺塔的问题（n, a, b, c），
即将N个盘子从起始柱（标记为“a”）通过借助柱（标记为“b”）移动到目标柱（标记为“c”），
并保证每个移动符合汉诺塔问题的要求。

输入格式:
输入为一个正整数N，即起始柱上的盘数。

输出格式:
每个操作（移动）占一行，按柱1 -> 柱2的格式输出。

输入样例:
3

输出样例:
a -> c
a -> b
c -> b
a -> c
b -> a
b -> c
a -> c

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/*   https://zhuanlan.zhihu.com/p/36085324

1. 将三根柱子按顺序排成品字型，若 N 为偶数，按顺时针方向依次摆放A、B、C；
   若 N 为奇数，按顺时针方向依次摆放A、C、B。

2. 把圆盘1从现在的柱子移动到顺时针方向的下一根柱。

3. 接着，把另外两根柱上可以移动的圆盘移动到新的柱上（事实上只有唯一的选择）。

4. 如果没有达到目标要求，则返回步骤2。

*/

#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Hannuo_norec(int n) {

    vector<stack<int>> pl(3);
    for (int i = n; i > 0; i--)
        pl[0].push(i); // 这里为了能够比较两个柱子上面不同的盘子的大小
    char name[3]{0};
    int end = 0;

    if (!(n % 2)) {
        name[0] = 'a';
        name[1] = 'b';
        name[2] = 'c';
        end = 2;
    } else {
        name[0] = 'a';
        name[1] = 'c';
        name[2] = 'b';
        end = 1;
    }

    int one = 0;

    auto next = [](int x) { return (x + 1) % 3; };

    while (pl[end].size() < n) {
        pl[next(one)].push(pl[one].top());
        pl[one].pop();
        cout << name[one] << " -> " << name[next(one)] << '\n';
        one = next(one);

        if (pl[end].size() >= n)
            break;

        int x = next(one), y = next(x);
        int xx = pl[x].empty() ? INT_MAX : pl[x].top();
        int yy = pl[y].empty() ? INT_MAX : pl[y].top();
        if (xx > yy) {
            pl[x].push(pl[y].top());
            pl[y].pop();
            cout << name[y] << " -> " << name[x] << '\n';
        } else {
            pl[y].push(pl[x].top());
            pl[x].pop();
            cout << name[x] << " -> " << name[y] << '\n';
        }
    }
}

int main() {
    int N = 0;
    cin >> N;
    Hannuo_norec(N);
    return 0;
}