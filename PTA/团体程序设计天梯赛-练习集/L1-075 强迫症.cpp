/**
 * @file L1-075 强迫症.cpp
 * @date 2022-05-21
 */

/*
小强在统计一个小区里居民的出生年月，但是发现大家填写的生日格式不统一，例如有的人写 199808，有的人只写 9808。有强迫症的小强请你写个程序，把所有人的出生年月都整理成 年年年年-月月 格式。对于那些只写了年份后两位的信息，我们默认小于 22 都是 20 开头的，其他都是 19 开头的。

输入格式：
输入在一行中给出一个出生年月，为一个 6 位或者 4 位数，题目保证是 1000 年 1 月到 2021 年 12 月之间的合法年月。

输出格式：
在一行中按标准格式 年年年年-月月 将输入的信息整理输出。

输入样例 1：
9808
输出样例 1：
1998-08
输入样例 2：
0510
输出样例 2：
2005-10
输入样例 3：
196711
输出样例 3：
1967-11
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
#include <string>
using namespace std;

int main() {

    string s;
    for (char c; (c = getchar()) != '\n';)
        s.push_back(c);

    if (s.size() == 4) {
        int x = (s[0] - '0') * 10 + s[1] - '0';
        if (x < 22)
            s.insert(0, "20");
        else
            s.insert(0, "19");
    }
    s.insert(4, "-");

    printf("%s", s.c_str());

    return 0;
}