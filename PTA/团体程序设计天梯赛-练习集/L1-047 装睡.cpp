/**
 * @file L1-047 装睡.cpp
 * @date 2022-05-19
 */

/*
你永远叫不醒一个装睡的人 —— 但是通过分析一个人的呼吸频率和脉搏，你可以发现谁在装睡！
医生告诉我们，正常人睡眠时的呼吸频率是每分钟15-20次，脉搏是每分钟50-70次。
下面给定一系列人的呼吸频率与脉搏，请你找出他们中间有可能在装睡的人，即至少一项指标不在正常范围内的人。

输入格式：
输入在第一行给出一个正整数N（≤10）。
随后N行，每行给出一个人的名字（仅由英文字母组成的、长度不超过3个字符的串）、
其呼吸频率和脉搏（均为不超过100的正整数）。

输出格式：
按照输入顺序检查每个人，如果其至少一项指标不在正常范围内，则输出其名字，每个名字占一行。

输入样例：
4
Amy 15 70
Tom 14 60
Joe 18 50
Zoe 21 71

输出样例：
Tom
Zoe

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

    int n = 0;
    scanf("%d", &n);
    getchar();

    while (n--) {
        string name;
        int breath = 0, pulse = 0;

        for (char c; scanf("%c", &c) && c != ' ';)
            name.push_back(c);
        scanf("%d %d", &breath, &pulse);
        getchar();

        bool f1 = breath >= 15 && breath <= 20;
        bool f2 = pulse >= 50 && pulse <= 70;

        if (!(f1 && f2))
            printf("%s\n", name.c_str());
    }

    return 0;
}