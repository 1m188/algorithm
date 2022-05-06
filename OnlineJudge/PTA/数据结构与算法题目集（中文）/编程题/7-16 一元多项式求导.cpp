/*
设计函数求一元多项式的导数。

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。

输入样例:
3 4 -5 2 6 1 -2 0

输出样例:
12 3 -10 1 6 0

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 这题也太坑了，明明题目里说的是“输出导数多项式非零项的系数和指数”，非零项啊非零项，结果
输入数据为常数多项式或者0多项式的时候还需要输出“0 0”。此外最后一个测试点零多项式，按照题目内容
只会输入多项式非零项系数和指数，那这里的零多项式应该是求导后的内容喽？并不是，至少在我这里
他还是作为一个输入数据来做的。这题还是......多注意注意吧，最后还是从网上找了人家的代码才发现这里的。 */

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;

// 处理输入
// 将输入的一行内容作为string加到stringstream里，
// 之后再当作输出处理，比分割空格要简单一些
void input() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    int x = 0;
    while (ss >> x) {
        int y = 0;
        ss >> y;
        vec.push_back({x, y});
    }
}

void print() {
    int xishu = vec[0].first, zhishu = vec[0].second;
    if (zhishu) {
        cout << xishu * zhishu << ' ' << zhishu - 1;
    } else {
        cout << 0 << ' ' << 0;
        return;
    }

    for (int i = 1; i < vec.size(); i++) {
        xishu = vec[i].first, zhishu = vec[i].second;
        if (zhishu) {
            cout << ' ' << xishu * zhishu << ' ' << zhishu - 1;
        }
    }
}

int main() {
    input();
    print();
    return 0;
}