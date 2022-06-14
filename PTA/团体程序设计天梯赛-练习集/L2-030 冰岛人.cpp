/**
 * @file L2-030 冰岛人.cpp
 * @date 2022-06-14
 */

/*
2018年世界杯，冰岛队因1:1平了强大的阿根廷队而一战成名。好事者发现冰岛人的名字后面似乎都有个“松”（son），于是有网友科普如下：

iceland.JPG

冰岛人沿用的是维京人古老的父系姓制，孩子的姓等于父亲的名加后缀，如果是儿子就加 sson，女儿则加 sdottir。因为冰岛人口较少，为避免近亲繁衍，本地人交往前先用个 App 查一下两人祖宗若干代有无联系。本题就请你实现这个 App 的功能。

输入格式：
输入首先在第一行给出一个正整数 N（1<N≤10 
5
 ），为当地人口数。随后 N 行，每行给出一个人名，格式为：名 姓（带性别后缀），两个字符串均由不超过 20 个小写的英文字母组成。维京人后裔是可以通过姓的后缀判断其性别的，其他人则是在姓的后面加 m 表示男性、f 表示女性。题目保证给出的每个维京家族的起源人都是男性。

随后一行给出正整数 M，为查询数量。随后 M 行，每行给出一对人名，格式为：名1 姓1 名2 姓2。注意：这里的姓是不带后缀的。四个字符串均由不超过 20 个小写的英文字母组成。

题目保证不存在两个人是同名的。

输出格式：
对每一个查询，根据结果在一行内显示以下信息：

若两人为异性，且五代以内无公共祖先，则输出 Yes；
若两人为异性，但五代以内（不包括第五代）有公共祖先，则输出 No；
若两人为同性，则输出 Whatever；
若有一人不在名单内，则输出 NA。
所谓“五代以内无公共祖先”是指两人的公共祖先（如果存在的话）必须比任何一方的曾祖父辈分高。

输入样例：
15
chris smithm
adam smithm
bob adamsson
jack chrissson
bill chrissson
mike jacksson
steve billsson
tim mikesson
april mikesdottir
eric stevesson
tracy timsdottir
james ericsson
patrick jacksson
robin patricksson
will robinsson
6
tracy tim james eric
will robin tracy tim
april mike steve bill
bob adam eric steve
tracy tim tracy tim
x man april mikes
输出样例：
Yes
No
No
Whatever
Whatever
NA
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 没有人同名——指的是单独的“名”没有重复的，因此可以用名做key，value为性别和父亲的名，
这样可以通过一个人的名找到他的父亲，找到他父亲的父亲...直到最开始的祖宗，此外，
两者之间的祖宗判定需要注意一下，此外，只有维京姓制才是本地人，其他人都是外来人，不必
求其祖先 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

void input_str(string &s) {
    s.resize(20, '\0');
    scanf("%s", &s[0]);
    for (int i = 0; i < 20; i++) {
        if (s[i] == '\0') {
            s.resize(i);
            break;
        }
    }
}

struct Node {
    string father;
    char sex;
};

int n = 0, m = 0;
unordered_map<string, Node> ump;

void input() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string a, b;
        input_str(a), input_str(b);
        if (b.back() == 'n') {
            ump[a] = {b.substr(0, b.size() - 4), 'm'};
        } else if (b.back() == 'r') {
            ump[a] = {b.substr(0, b.size() - 7), 'f'};
        } else
            ump[a].sex = b.back();
    }
}

bool check(const string &a, const string &b) {
    int i = 1;
    for (string s = a; !s.empty() && i < 5; s = ump[s].father, i++) {
        for (string ss = b; !ss.empty(); ss = ump[ss].father) {
            if (s == ss) return false;
        }
    }
    i = 1;
    for (string s = b; !s.empty() && i < 5; s = ump[s].father, i++) {
        for (string ss = a; !ss.empty(); ss = ump[ss].father) {
            if (s == ss) return false;
        }
    }
    return true;
}

void calc() {
    scanf("%d", &m);
    while (m--) {
        string a, b, t;
        input_str(a), input_str(t), input_str(b), input_str(t);

        if (ump.find(a) == ump.end() || ump.find(b) == ump.end()) {
            printf("NA\n");
        } else if (ump[a].sex == ump[b].sex) {
            printf("Whatever\n");
        } else if (check(a, b)) {
            printf("Yes\n");
        } else
            printf("No\n");
    }
}

int main() {
    input();
    calc();
    return 0;
}