/**
 * @file L1-039 古风排版.cpp
 * @date 2022-05-19
 */

/*
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：
输入在第一行给出一个正整数N（<100），是每一列的字符数。
第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：
按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。

输入样例：
4
This is a test case

输出样例：
asa T
st ih
e tsi
 ce s

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意输出格式 */

#include <cstdio>
#include <string>
using namespace std;

int main() {

    string str;
    int n = 0;

    scanf("%d\n", &n);

    for (char c = getchar(); c != '\n'; c = getchar())
        str.push_back(c);

    while (str.size() % n != 0)
        str.push_back(' ');

    int idx = str.size() - n;
    while (idx < str.size()) {
        for (int i = idx; i >= 0; i -= n)
            printf("%c", str[i]);
        printf("\n");
        idx++;
    }

    return 0;
}