/**
 * @file 7-48 银行排队问题之单窗口“夹塞”版.cpp
 * @date 2022-05-16
 */

/*
排队“夹塞”是引起大家强烈不满的行为，但是这种现象时常存在。
在银行的单窗口排队问题中，假设银行只有1个窗口提供服务，所有顾客按到达时间排成一条长龙。
当窗口空闲时，下一位顾客即去该窗口处理事务。
此时如果已知第i位顾客与排在后面的第j位顾客是好朋友，并且愿意替朋友办理事务的话，
那么第i位顾客的事务处理时间就是自己的事务加朋友的事务所耗时间的总和。
在这种情况下，顾客的等待时间就可能被影响。
假设所有人到达银行时，若没有空窗口，都会请求排在最前面的朋友帮忙（包括正在窗口接受服务的朋友）；
当有不止一位朋友请求某位顾客帮忙时，该顾客会根据自己朋友请求的顺序来依次处理事务。
试编写程序模拟这种现象，并计算顾客的平均等待时间。

输入格式:
输入的第一行是两个整数：1≤N≤10000，为顾客总数；0≤M≤100，为彼此不相交的朋友圈子个数。
若M非0，则此后M行，每行先给出正整数2≤L≤100，代表该圈子里朋友的总数，随后给出该朋友圈里的L位朋友的名字。
名字由3个大写英文字母组成，名字间用1个空格分隔。
最后N行给出N位顾客的姓名、到达时间T和事务处理时间P（以分钟为单位），之间用1个空格分隔。
简单起见，这里假设顾客信息是按照到达时间先后顺序给出的（有并列时间的按照给出顺序排队），
并且假设每个事务最多占用窗口服务60分钟（如果超过则按60分钟计算）。

输出格式:
按顾客接受服务的顺序输出顾客名字，每个名字占1行。最后一行输出所有顾客的平均等待时间，保留到小数点后1位。

输入样例:
6 2
3 ANN BOB JOE
2 JIM ZOE
JIM 0 20
BOB 0 15
ANN 0 30
AMY 0 2
ZOE 1 61
JOE 3 10

输出样例:
JIM
ZOE
BOB
ANN
JOE
AMY
75.2

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 初看很麻烦，上手写起来感觉还行。

注意朋友圈的处理，如何判断两个人是否属于同一个朋友圈，

注意对时间的处理 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief 用户数据
 */
struct Info {
    string name;      // 名字
    int arr_time;     // 到达时间
    int cost_time;    // 花费时间
    int wait_time;    // 等待时间
    bool is_jiasaied; // 是否加塞
};

int N = 0,                       // 待处理业务的人数
    M = 0;                       // 多少个相互独立的朋友圈
unordered_map<string, int> fcle; // 名字-朋友圈编号 映射
vector<Info> info;               // 按到达顺序存储用户数据

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int x = 0;
        cin >> x;
        if (x <= 1)
            continue;
        while (x--) {
            string s;
            cin >> s;
            fcle[s] = i;
        }
    }

    info.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> info[i].name >> info[i].arr_time >> info[i].cost_time;
        if (info[i].cost_time > 60) // 输入时候最大业务时间都是60分钟
            info[i].cost_time = 60;
    }
}

/**
 * @brief 计算每个用户的时间
 */
void calc() {

    for (int i = 0; i < info.size(); i++) {

        // 判断是否已经加塞完了
        if (info[i].is_jiasaied)
            continue;

        // 没有加塞，要处理业务
        cout << info[i].name << '\n';

        // 否则没有加塞，判定其等待时间
        // 为前面第一个没加塞的人的到达时间+等待时间+处理时间和自己
        // 的到达时间的比较
        if (i != 0) {
            int idx = i - 1;
            while (info[idx].is_jiasaied)
                idx--;
            info[i].wait_time = info[idx].arr_time + info[idx].wait_time + info[idx].cost_time - info[i].arr_time;
            if (info[i].wait_time < 0) // 考虑是否来的比较晚
                info[i].wait_time = 0;
        }

        // 找朋友
        if (!fcle[info[i].name])
            continue;
        for (int j = i + 1; j < info.size(); j++) {

            // 处理完业务了，后面来的人无论如何也加不到这个人的塞了
            if (info[j].arr_time > info[i].arr_time + info[i].wait_time + info[i].cost_time)
                break;

            // 不是朋友当然不能让你加塞
            if (fcle[info[j].name] != fcle[info[i].name])
                continue;

            // 加塞
            info[j].is_jiasaied = true;
            cout << info[j].name << '\n';
            info[j].wait_time = info[i].arr_time + info[i].wait_time + info[i].cost_time - info[j].arr_time;
            info[i].cost_time += info[j].cost_time;
        }
    }

    // 每个人等待时间总和
    int total_time = 0;
    for_each(info.begin(), info.end(), [&](const Info &e) {
        total_time += e.wait_time;
    });
    cout << setiosflags(ios::fixed) << setprecision(1)
         << double(total_time) / N << '\n'; // 平均等待时间
}

int main() {
    input();
    calc();
    return 0;
}