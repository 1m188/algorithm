/**
 * @file L2-028 秀恩爱分得快.cpp
 * @date 2022-06-12
 */

/*
古人云：秀恩爱，分得快。

互联网上每天都有大量人发布大量照片，我们通过分析这些照片，可以分析人与人之间的亲密度。如果一张照片上出现了 K 个人，这些人两两间的亲密度就被定义为 1/K。任意两个人如果同时出现在若干张照片里，他们之间的亲密度就是所有这些同框照片对应的亲密度之和。下面给定一批照片，请你分析一对给定的情侣，看看他们分别有没有亲密度更高的异性朋友？

输入格式：
输入在第一行给出 2 个正整数：N（不超过1000，为总人数——简单起见，我们把所有人从 0 到 N-1 编号。为了区分性别，我们用编号前的负号表示女性）和 M（不超过1000，为照片总数）。随后 M 行，每行给出一张照片的信息，格式如下：

K P[1] ... P[K]
其中 K（≤ 500）是该照片中出现的人数，P[1] ~ P[K] 就是这些人的编号。最后一行给出一对异性情侣的编号 A 和 B。同行数字以空格分隔。题目保证每个人只有一个性别，并且不会在同一张照片里出现多次。

输出格式：
首先输出 A PA，其中 PA 是与 A 最亲密的异性。如果 PA 不唯一，则按他们编号的绝对值递增输出；然后类似地输出 B PB。但如果 A 和 B 正是彼此亲密度最高的一对，则只输出他们的编号，无论是否还有其他人并列。

输入样例 1：
10 4
4 -1 2 -3 4
4 2 -3 -5 -6
3 2 4 -5
3 -6 0 2
-3 2
输出样例 1：
-3 2
2 -5
2 -6
输入样例 2：
4 4
4 -1 2 -3 0
2 0 -3
2 2 -3
2 -1 2 
-3 2
输出样例 2：
-3 2
代码长度限制
16 KB
时间限制
500 ms
内存限制
64 MB
*/

/* 仍然是小细节困扰一大堆的原因，因为有0的存在，其正负都是一样的，之前只考虑到了输入，
用字符串输入，但是没有考虑输出，仍然是输出正负数，搞了一上午都没找出原因，后来好不容易才
发现，需要注意。此外就是通用的思路了，不计算所有的亲密度，会超时，只计算给出两者的亲密度即可，
还需要考虑给出的两个人没在相片上的情况 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> photo;
vector<bool> sex;
vector<double> qma, qmb;
int n = 0, m = 0;
int a = 0, b = 0;

int read_a_person() {
    string s(10, '\0');
    scanf("%s", &s[0]);
    for (int i = 0; i < 10; i++) {
        if (s[i] == '\0') {
            s.resize(i);
            break;
        }
    }
    bool f = s[0] != '-';
    if (s[0] == '-') s.erase(s.begin());
    int ans = stoi(s);
    sex[ans] = f;
    return ans;
}

void input() {
    scanf("%d %d", &n, &m);
    photo.resize(m);
    sex.resize(n);
    qma.resize(n);
    qmb.resize(n);

    for (auto &e : photo) {
        int k = 0;
        scanf("%d", &k);
        e.resize(k);
        for (auto &n : e) {
            n = read_a_person();
        }
    }

    a = read_a_person(), b = read_a_person();
}

void output(int x, int y) {
    if (!sex[x]) printf("-");
    printf("%d ", x);
    if (!sex[y]) printf("-");
    printf("%d\n", y);
}

void calc() {
    for (const auto &e : photo) {
        bool f1 = find(e.begin(), e.end(), a) != e.end(),
             f2 = find(e.begin(), e.end(), b) != e.end();
        if (f1 || f2) {
            double t = 1.0 / e.size();
            for (const auto &n : e) {
                if (f1 && sex[a] != sex[n])
                    qma[n] += t;
                if (f2 && sex[b] != sex[n])
                    qmb[n] += t;
            }
        }
    }

    double vala = 0;
    vector<int> veca;
    for (int i = 0; i < n; i++) {
        if (sex[a] == sex[i]) continue;
        if (qma[i] > vala) {
            vala = qma[i];
            veca = {i};
        } else if (qma[i] == vala) { // 这里判断相等直接用了等于号，应该是精度没到需要判定差的绝对值的情况吧
            veca.push_back(i);
        }
    }

    double valb = 0;
    vector<int> vecb;
    for (int i = 0; i < n; i++) {
        if (sex[b] == sex[i]) continue;
        if (qmb[i] > valb) {
            valb = qmb[i];
            vecb = {i};
        } else if (qmb[i] == valb) {
            vecb.push_back(i);
        }
    }

    if (find(veca.begin(), veca.end(), b) != veca.end() && find(vecb.begin(), vecb.end(), a) != vecb.end()) {
        output(a, b);
    } else {
        for (const auto &i : veca) {
            output(a, i);
        }
        for (const auto &i : vecb) {
            output(b, i);
        }
    }
}

int main() {
    input();
    calc();
    return 0;
}