/**
 * @file L1-044 稳赢.cpp
 * @date 2022-05-19
 */

/*
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：



现要求你编写一个稳赢不输的程序，根据对方的出招，给出对应的赢招。但是！
为了不让对方输得太惨，你需要每隔K次就让一个平局。

输入格式：
输入首先在第一行给出正整数K（≤10），即平局间隔的次数。随后每行给出对方的一次出招：
ChuiZi代表“锤子”、JianDao代表“剪刀”、Bu代表“布”。End代表输入结束，这一行不要作为出招处理。

输出格式：
对每一个输入的出招，按要求输出稳赢或平局的招式。每招占一行。

输入样例：
2
ChuiZi
JianDao
Bu
JianDao
Bu
ChuiZi
ChuiZi
End

输出样例：
Bu
ChuiZi
Bu
ChuiZi
JianDao
ChuiZi
Bu

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意输入和计数 */

#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> ump = {{"ChuiZi", "Bu"},
                                     {"JianDao", "ChuiZi"},
                                     {"Bu", "JianDao"}};

int main() {

    int k = 0;
    scanf("%d", &k);
    getchar();

    int num = 0;

    while (true) {

        string str;
        for (char c; scanf("%c", &c) && c != '\n';)
            str.push_back(c);

        if (str == "End")
            break;

        if (num >= k) {
            num = 0;
            printf("%s\n", str.c_str());
        } else {
            num++;
            printf("%s\n", ump[str].c_str());
        }
    }

    return 0;
}