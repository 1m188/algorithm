/**
 * @file L1-086 斯德哥尔摩火车上的题.cpp
 * @date 2022-05-21
 */

/*
tt.png
上图是新浪微博上的一则趣闻，是瑞典斯德哥尔摩火车上的一道题，看上去是段伪代码：

s = ''
a = '1112031584'
for (i = 1; i < length(a); i++) {
  if (a[i] % 2 == a[i-1] % 2) {
    s += max(a[i], a[i-1])
  }
}
goto_url('www.multisoft.se/' + s)
其中字符串的 + 操作是连接两个字符串的意思。所以这道题其实是让大家访问网站 www.multisoft.se/112358（注意：比赛中千万不要访问这个网址！！！）。

当然，能通过上述算法得到 112358 的原始字符串 a 是不唯一的。本题就请你判断，两个给定的原始字符串，能否通过上述算法得到相同的输出？

输入格式：
输入为两行仅由数字组成的非空字符串，长度均不超过 10 
4
 ，以回车结束。

输出格式：
对两个字符串分别采用上述斯德哥尔摩火车上的算法进行处理。如果两个结果是一样的，则在一行中输出那个结果；否则分别输出各自对应的处理结果，每个占一行。题目保证输出结果不为空。

输入样例 1：
1112031584
011102315849
输出样例 1：
112358
输入样例 2：
111203158412334
12341112031584
输出样例 2：
1123583
112358
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

    string s1;

    int pre = getchar() - '0';
    for (char c; (c = getchar()) != '\n';) {
        int n = c - '0';
        if (n % 2 == pre % 2)
            s1.push_back(max(pre, n) + '0');
        pre = n;
    }

    string s2;

    pre = getchar() - '0';
    for (char c; (c = getchar()) != '\n';) {
        int n = c - '0';
        if (n % 2 == pre % 2)
            s2.push_back(max(pre, n) + '0');
        pre = n;
    }

    if (s1 == s2)
        printf("%s", s1.c_str());
    else
        printf("%s\n%s", s1.c_str(), s2.c_str());

    return 0;
}