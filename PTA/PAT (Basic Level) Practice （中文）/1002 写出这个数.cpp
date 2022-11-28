/**
 * @file 1002 写出这个数.cpp
 * @date 2022-11-28
 */

/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include "cstdio"
#include "string"
using namespace std;

string int_s(105, '\0');
char map_print[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void input() {
    scanf("%s", &int_s[0]);
    for (int i = 0; i < int_s.size(); i++)
        if (int_s[i] == '\0')
            int_s.resize(i);
}

int calc() {
    int res = 0;
    for (auto &&c : int_s) {
        // printf("%c\n", c - '0');
        res += c - '0';
    }
    // printf("%d\n", res);
    return res;
}

void print(int num) {
    string &&num_s = to_string(num);
    printf("%s", map_print[num_s[0] - '0']);
    for (int i = 1; i < num_s.length(); i++)
        printf(" %s", map_print[num_s[i] - '0']);
}

int main() {
    input();
    // printf("%s\n", int_s.c_str());
    print(calc());
    return 0;
}