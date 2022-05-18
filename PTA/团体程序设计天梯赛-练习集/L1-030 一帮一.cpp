/**
 * @file L1-030 一帮一.cpp
 * @date 2022-05-18
 */

/*
“一帮一学习小组”是中小学中常见的学习组织方式，老师把学习成绩靠前的学生跟学习成绩靠后的学生排在一组。
本题就请你编写程序帮助老师自动完成这个分配工作，即在得到全班学生的排名后，在当前尚未分组的学生中，
将名次最靠前的学生与名次最靠后的异性学生分为一组。

输入格式：
输入第一行给出正偶数N（≤50），即全班学生的人数。此后N行，按照名次从高到低的顺序给出每个学生的性别
（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），其间以1个空格分隔。
这里保证本班男女比例是1:1，并且没有并列名次。

输出格式：
每行输出一组两个学生的姓名，其间以1个空格分隔。名次高的学生在前，名次低的学生在后。
小组的输出顺序按照前面学生的名次从高到低排列。

输入样例：
8
0 Amy
1 Tom
1 Bill
0 Cindy
0 Maya
1 John
1 Jack
0 Linda

输出样例：
Amy Jack
Tom Linda
Bill Maya
Cindy John

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 前后匹配，简单题 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, string>> stus;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    stus.resize(n);

    for (int i = 0; i < n; i++)
        cin >> stus[i].first >> stus[i].second;
}

void calc() {

    for (int i = 0; i < stus.size(); i++) {
        cout << stus[i].second << ' ';
        auto it = stus.end() - 1;
        while (it->first != !stus[i].first)
            it--;
        cout << it->second << '\n';
        stus.erase(it);
    }
}

int main() {
    input();
    calc();
    return 0;
}