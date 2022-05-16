/**
 * @file 7-49 打印学生选课清单.cpp
 * @date 2022-05-16
 */

/*
假设全校有最多40000名学生和最多2500门课程。
现给出每门课的选课学生名单，要求输出每个前来查询的学生的选课清单。

输入格式:
输入的第一行是两个正整数：
N（≤40000），为前来查询课表的学生总数；
K（≤2500），为总课程数。
此后顺序给出课程1到K的选课学生名单。
格式为：对每一门课，首先在一行中输出课程编号（简单起见，课程从1到K编号）和选课学生总数（之间用空格分隔），
之后在第二行给出学生名单，相邻两个学生名字用1个空格分隔。
学生姓名由3个大写英文字母+1位数字组成。
选课信息之后，在一行内给出了N个前来查询课表的学生的名字，相邻两个学生名字用1个空格分隔。

输出格式:
对每位前来查询课表的学生，首先输出其名字，随后在同一行中输出一个正整数C，
代表该生所选的课程门数，随后按递增顺序输出C个课程的编号。
相邻数据用1个空格分隔，注意行末不能输出多余空格。

输入样例:
10 5
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6

输出样例:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 看上去是简单题，但其实题目描述有问题，注意几点：

1. 题目中说会按顺序给出K门课，但事实上不一定会按顺序给出。仔细想想其实挺奇怪，
既然题目中说会按顺序给出课程，那为什么每次给出的时候还要带上课程号呢？但题目里
也没有说，这一点完全是题目自己的问题。

2. 最后会有没选课的学生来查询，这倒是挺好想的。 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int N = 0,                              // 来查询成绩的学生的数目
    K = 0;                              // 总共多少门课
unordered_map<string, vector<int>> ump; // 存储  学生名字-选了的课程  映射

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    string tmp;

    while (K--) {
        int x = 0, y = 0;
        cin >> x >> y; // 因为不按顺序给出课程，所以这里两个给出来的课程号和人数都要保存

        while (y--) {
            cin >> tmp;
            ump[tmp].push_back(x);
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        auto &vec = ump[tmp];
        cout << tmp << ' ' << vec.size();
        sort(vec.begin(), vec.end()); // 不按顺序给出课程，输出之前需要排序
        for (const int &e : vec)
            cout << ' ' << e;
        cout << '\n';
    }
}

int main() {
    input();
    return 0;
}