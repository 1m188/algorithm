/**
 * @file L1-043 阅览室.cpp
 * @date 2022-05-19
 */

/*
天梯图书阅览室请你编写一个简单的图书借阅统计程序。当读者借书时，管理员输入书号并按下S键，程序开始计时；
当读者还书时，管理员输入书号并按下E键，程序结束计时。书号为不超过1000的正整数。
当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。

注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，
系统应能自动忽略这种无效纪录。另外，题目保证书号是书的唯一标识，
同一本书在任何时间区间内只可能被一位读者借阅。

输入格式：
输入在第一行给出一个正整数N（≤10），随后给出N天的纪录。每天的纪录由若干次借阅操作组成，
每次操作占一行，格式为：

书号（[1, 1000]内的整数） 键值（S或E） 发生时间（hh:mm，其中hh是[0,23]内的整数，mm是[0, 59]内整数）

每一天的纪录保证按时间递增的顺序给出。

输出格式：
对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。

输入样例：
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00

输出样例：
2 196
0 0
1 60

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <cmath>
#include <cstdio>
#include <unordered_map>
using namespace std;

void input() {
    int day = 0;
    scanf("%d", &day);

    while (day--) {

        unordered_map<int, int> ump;

        int bnum = 0, btime = 0;

        int bid = 0;
        char beh = 0;
        int hour = 0, minute = 0;

        while (scanf("%d %c %d:%d", &bid, &beh, &hour, &minute) && bid) {
            if (beh == 'S')
                ump[bid] = hour * 60 + minute;
            else {
                auto it = ump.find(bid);
                if (it == ump.end())
                    continue;
                bnum++;
                btime += hour * 60 + minute - it->second;
                ump.erase(it);
            }
        }

        // 注意输出的时候要记得四舍五入
        printf("%d %d\n", bnum, bnum ? int(round(double(btime) / bnum)) : 0);
    }
}

int main() {
    input();
    return 0;
}