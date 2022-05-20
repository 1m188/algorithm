/**
 * @file L1-064 估值一亿的AI核心代码.cpp
 * @date 2022-05-20
 */

/*
AI.jpg
以上图片来自新浪微博。

本题要求你实现一个稍微更值钱一点的 AI 英文问答程序，规则是：

无论用户说什么，首先把对方说的话在一行中原样打印出来；
消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把行首尾的空格全部删掉，把标点符号前面的空格删掉；
把原文中所有大写英文字母变成小写，除了 I；
把原文中所有独立的 can you、could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词；
把原文中所有独立的 I 和 me 换成 you；
把原文中所有的问号 ? 换成惊叹号 !；
在一行中输出替换后的句子作为 AI 的回答。
输入格式：
输入首先在第一行给出不超过 10 的正整数 N，随后 N 行，每行给出一句不超过 1000 个字符的、以回车结尾的用户的对话，对话为非空字符串，仅包括字母、数字、空格、可见的半角标点符号。

输出格式：
按题面要求输出，每个 AI 的回答前要加上 AI: 和一个空格。

输入样例：
6
Hello ?
 Good to chat   with you
can   you speak Chinese?
Really?
Could you show me 5
What Is this prime? I,don 't know
输出样例：
Hello ?
AI: hello!
 Good to chat   with you
AI: good to chat with you
can   you speak Chinese?
AI: I can speak chinese!
Really?
AI: really!
Could you show me 5
AI: I could show you 5
What Is this prime? I,don 't know
AI: what Is this prime! you,don't know
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 细节很多，注意细节。另外就是改动字符串不能够多次扫描，可能后面扫描的会把前面
改动的部分当作字符串原本的一部分，应该是从头扫一遍到尾按照需求更改。 */

#include <cctype>
#include <cstdio>
#include <string>
using namespace std;

void handle(string &str) {

    // 把原文中所有大写英文字母变成小写，除了 I；
    for (char &c : str) {
        if (isalpha(c) && isupper(c) && c != 'I')
            c = tolower(c);
    }

    // 把原文中所有的问号 ? 换成惊叹号 !；
    for (char &c : str) {
        if (c == '?')
            c = '!';
    }

    /* 消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把行首尾的空格全部删掉，
    把标点符号前面的空格删掉； */
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ')
            continue;

        int j = i + 1;
        if (j < str.size() && str[j] == ' ') {
            int idx = str.find_first_not_of(' ', j);
            str.erase(j, idx - j);
        }
    }
    for (int i = 1; i < str.size();) {
        if (ispunct(str[i]) && str[i - 1] == ' ')
            str.erase(i - 1, 1);
        else
            i++;
    }

    for (int i = 0; i < str.size();) {

        // 把原文中所有独立的 I 和 me 换成 you；
        if (str[i] == 'I') {
            if (i - 1 >= 0 && str[i - 1] != ' ' && !ispunct(str[i - 1])) {
                i++;
                continue;
            }
            if (i + 1 < str.size() && str[i + 1] != ' ' && !ispunct(str[i + 1])) {
                i++;
                continue;
            }
            str.replace(i, 1, "you");
            i++;
        } else if (i + 1 < str.size() && str.substr(i, 2) == "me") {
            if (i - 1 >= 0 && str[i - 1] != ' ' && !ispunct(str[i - 1])) {
                i++;
                continue;
            }
            if (i + 2 < str.size() && str[i + 2] != ' ' && !ispunct(str[i + 2])) {
                i++;
                continue;
            }
            str.replace(i, 2, "you");
            i++;
        }
        // 把原文中所有独立的 can you、could you 对应地换成 I can、I could——
        // 这里“独立”是指被空格或标点符号分隔开的单词；
        else if (i + 6 < str.size() && str.substr(i, 7) == "can you") {
            if (i - 1 >= 0 && str[i - 1] != ' ' && !ispunct(str[i - 1])) {
                i++;
                continue;
            }
            if (i + 7 < str.size() && str[i + 7] != ' ' && !ispunct(str[i + 7])) {
                i++;
                continue;
            }
            str.replace(i, 7, "I can");
            i++;
        } else if (i + 8 < str.size() && str.substr(i, 9) == "could you") {
            if (i - 1 >= 0 && str[i - 1] != ' ' && !ispunct(str[i - 1])) {
                i++;
                continue;
            }
            if (i + 9 < str.size() && str[i + 9] != ' ' && !ispunct(str[i + 9])) {
                i++;
                continue;
            }
            str.replace(i, 9, "I could");
            i++;
        } else
            i++;
    }
}

int main() {

    int n = 0;
    scanf("%d", &n);
    getchar();

    while (n--) {
        string str;
        for (char c; (c = getchar()) != '\n';)
            str.push_back(c);
        printf("%s\n", str.c_str());
        handle(str);
        printf("AI: %s\n", str.c_str());
    }

    return 0;
}