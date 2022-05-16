/**
 * @file 7-47 打印选课学生名单.cpp
 * @date 2022-05-16
 */

/*
假设全校有最多40000名学生和最多2500门课程。现给出每个学生的选课清单，要求输出每门课的选课学生名单。

输入格式:
输入的第一行是两个正整数：N（≤40000），为全校学生总数；K（≤2500），为总课程数。
此后N行，每行包括一个学生姓名（3个大写英文字母+1位数字）、一个正整数C（≤20）代表该生所选的课程门数、
随后是C个课程编号。简单起见，课程从1到K编号。

输出格式:
顺序输出课程1到K的选课学生名单。格式为：
对每一门课，首先在一行中输出课程编号和选课学生总数（之间用空格分隔），
之后在第二行按字典序输出学生名单，每个学生名字占一行。

输入样例:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

输出样例:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1

代码长度限制
16 KB

时间限制
1000 ms

内存限制
64 MB
*/

/* 对于没门课程，储存其选了的学生名字，关键在于最后要按字典序输出学生名字，最开始用的是
set，想着自动排序，但后来超时了，改成vector再sort就没有，估计是set自动判重也要花时间，
在这种数据量大并且不需要判重的问题里还是尽量用vector和sort */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N = 0,                      // 学生数目
    K = 0;                      // 课程数目
vector<vector<string>> lessons; // 存储每个课程下选了的学生名字

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    lessons.resize(K + 1);

    for (int i = 0; i < N; i++) {
        string name;
        int c = 0;
        cin >> name >> c;

        while (c--) {
            int x = 0;
            cin >> x;
            lessons[x].push_back(name);
        }
    }
}

/**
 * @brief 输出
 */
void print() {
    for (int i = 1; i <= K; i++) {
        cout << i << ' ' << lessons[i].size() << '\n';
        sort(lessons[i].begin(), lessons[i].end()); // 字典序输出，先排序
        for (const string &s : lessons[i])
            cout << s << '\n';
    }
}

int main() {
    input();
    print();
    return 0;
}