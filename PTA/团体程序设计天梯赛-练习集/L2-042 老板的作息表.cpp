/**
 * @file L2-042 老板的作息表.cpp
 * @date 2022-06-20
 */

/*
zcy.png
新浪微博上有人发了某老板的作息时间表，表示其每天 4:30 就起床了。但立刻有眼尖的网友问：这时间表不完整啊，早上九点到下午一点干啥了？

本题就请你编写程序，检查任意一张时间表，找出其中没写出来的时间段。

输入格式：
输入第一行给出一个正整数 N，为作息表上列出的时间段的个数。随后 N 行，每行给出一个时间段，格式为：

hh:mm:ss - hh:mm:ss
其中 hh、mm、ss 分别是两位数表示的小时、分钟、秒。第一个时间是开始时间，第二个是结束时间。题目保证所有时间都在一天之内（即从 00:00:00 到 23:59:59）；每个区间间隔至少 1 秒；并且任意两个给出的时间区间最多只在一个端点有重合，没有区间重叠的情况。

输出格式：
按照时间顺序列出时间表中没有出现的区间，每个区间占一行，格式与输入相同。题目保证至少存在一个区间需要输出。

输入样例：
8
13:00:00 - 18:00:00
00:00:00 - 01:00:05
08:00:00 - 09:00:00
07:10:59 - 08:00:00
01:00:05 - 04:30:00
06:30:00 - 07:10:58
05:30:00 - 06:30:00
18:00:00 - 19:00:00
输出样例：
04:30:00 - 05:30:00
07:10:58 - 07:10:59
09:00:00 - 13:00:00
19:00:00 - 23:59:59
代码长度限制
16 KB
Java (javac)
时间限制
900 ms
内存限制
128 MB
Python (python3)
时间限制
300 ms
内存限制
64 MB
其他编译器
时间限制
200 ms
内存限制
64 MB
*/

/* 注意时间转换为一般形式后再做比较，比较完后输出时需要格式化输出 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int start = 0;
    int end = 0;

    bool operator<(const Node &e) const {
        return start < e.start;
    }
};

int n = 0;
vector<Node> vec;

void outtime(int start, int end) {
    int sh = start / 3600;
    start %= 3600;
    int sm = start / 60;
    start %= 60;
    int eh = end / 3600;
    end %= 3600;
    int em = end / 60;
    end %= 60;
    printf("%02d:%02d:%02d - %02d:%02d:%02d\n", sh, sm, start, eh, em, end);
}

int main() {

    scanf("%d", &n);
    vec.resize(n);
    for (Node &e : vec) {
        int sh = 0, sm = 0, ss = 0, eh = 0, em = 0, es = 0;
        scanf("%d:%d:%d - %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);
        e.start = sh * 60 * 60 + sm * 60 + ss;
        e.end = eh * 60 * 60 + em * 60 + es;
    }

    sort(vec.begin(), vec.end());

    if (vec[0].start != 0) {
        outtime(0, vec[0].start);
    }

    for (int i = 1; i < n; i++) {
        if (vec[i].start != vec[i - 1].end) {
            outtime(vec[i - 1].end, vec[i].start);
        }
    }
    if (vec.back().end != 23 * 60 * 60 + 59 * 60 + 59) {
        outtime(vec.back().end, 23 * 60 * 60 + 59 * 60 + 59);
    }

    return 0;
}