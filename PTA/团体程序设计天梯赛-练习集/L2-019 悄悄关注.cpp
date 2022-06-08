/**
 * @file L2-019 悄悄关注.cpp
 * @date 2022-06-08
 */

/*
新浪微博上有个“悄悄关注”，一个用户悄悄关注的人，不出现在这个用户的关注列表上，但系统会推送其悄悄关注的人发表的微博给该用户。现在我们来做一回网络侦探，根据某人的关注列表和其对其他用户的点赞情况，扒出有可能被其悄悄关注的人。

输入格式：
输入首先在第一行给出某用户的关注列表，格式如下：

人数N 用户1 用户2 …… 用户N
其中N是不超过5000的正整数，每个用户i（i=1, ..., N）是被其关注的用户的ID，是长度为4位的由数字和英文字母组成的字符串，各项间以空格分隔。

之后给出该用户点赞的信息：首先给出一个不超过10000的正整数M，随后M行，每行给出一个被其点赞的用户ID和对该用户的点赞次数（不超过1000），以空格分隔。注意：用户ID是一个用户的唯一身份标识。题目保证在关注列表中没有重复用户，在点赞信息中也没有重复用户。

输出格式：
我们认为被该用户点赞次数大于其点赞平均数、且不在其关注列表上的人，很可能是其悄悄关注的人。根据这个假设，请你按用户ID字母序的升序输出可能是其悄悄关注的人，每行1个ID。如果其实并没有这样的人，则输出“Bing Mei You”。

输入样例1：
10 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao
8
Magi 50
Pota 30
LLao 3
Ammy 48
Dave 15
GAO3 31
Zoro 1
Cath 60
输出样例1：
Ammy
Cath
Pota
输入样例2：
11 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao Pota
7
Magi 50
Pota 30
LLao 48
Ammy 3
Dave 15
GAO3 31
Zoro 29
输出样例2：
Bing Mei You
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
*/

/* 直接模拟即可 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

unordered_set<string> guanzhu;
vector<pair<string, int>> dianzan;

int main() {

    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s(4, '\0');
        scanf("%s", &s[0]);
        guanzhu.insert(s);
    }

    int m = 0;
    scanf("%d", &m);
    dianzan.resize(m);
    double avg = 0;
    for (auto &e : dianzan) {
        e.first.resize(4);
        scanf("%s %d", &e.first[0], &e.second);
        avg += e.second;
    }
    avg /= m;
    sort(dianzan.begin(), dianzan.end(), [](const pair<string, int> &e1, const pair<string, int> &e2) {
        return e1.first < e2.first;
    });

    bool f = false;
    for (const auto &e : dianzan) {
        if (e.second > avg && guanzhu.find(e.first) == guanzhu.end()) {
            f = true;
            printf("%s\n", e.first.c_str());
        }
    }
    if (!f) printf("Bing Mei You");

    return 0;
}