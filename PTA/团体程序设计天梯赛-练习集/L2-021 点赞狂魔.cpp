/**
 * @file L2-021 点赞狂魔.cpp
 * @date 2022-06-10
 */

/*
微博上有个“点赞”功能，你可以为你喜欢的博文点个赞表示支持。每篇博文都有一些刻画其特性的标签，而你点赞的博文的类型，也间接刻画了你的特性。然而有这么一种人，他们会通过给自己看到的一切内容点赞来狂刷存在感，这种人就被称为“点赞狂魔”。他们点赞的标签非常分散，无法体现出明显的特性。本题就要求你写个程序，通过统计每个人点赞的不同标签的数量，找出前3名点赞狂魔。

输入格式：
输入在第一行给出一个正整数N（≤100），是待统计的用户数。随后N行，每行列出一位用户的点赞标签。格式为“Name K F 
1
​
 ⋯F 
K
​
 ”，其中Name是不超过8个英文小写字母的非空用户名，1≤K≤1000，F 
i
​
 （i=1,⋯,K）是特性标签的编号，我们将所有特性标签从 1 到 10 
7
  编号。数字间以空格分隔。

输出格式：
统计每个人点赞的不同标签的数量，找出数量最大的前3名，在一行中顺序输出他们的用户名,其间以1个空格分隔,且行末不得有多余空格。如果有并列，则输出标签出现次数平均值最小的那个，题目保证这样的用户没有并列。若不足3人，则用-补齐缺失，例如mike jenny -就表示只有2人。

输入样例：
5
bob 11 101 102 103 104 105 106 107 108 108 107 107
peter 8 1 2 3 4 3 2 5 1
chris 12 1 2 3 4 5 6 7 8 9 1 2 3
john 10 8 7 6 5 4 3 2 1 7 5
jack 9 6 7 8 9 10 11 12 13 14
输出样例：
jack chris john
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

/* 堆排序求前k大的元素 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
    string name;
    int k = 0;
    int num = 0;

    bool operator>(const Node &e) const {
        if (num != e.num) return num > e.num;
        return k < e.k;
    }

    bool operator<(const Node &e) const {
        return !((*this) > e);
    }
};

template <typename T>
void adjust(vector<T> &vec, int x) {
    for (int k = x * 2 + 1; k < vec.size(); k = x * 2 + 1) {
        if (k + 1 < vec.size() && vec[k + 1] < vec[k])
            k = k + 1;
        if (vec[k] < vec[x])
            swap(vec[k], vec[x]);
        else
            break;

        x = k;
    }
}

template <typename T>
void build_heap(vector<T> &vec) {
    for (int i = (vec.size() - 1 - 1) / 2; i >= 0; i--)
        adjust(vec, i);
}

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<Node> vec;

    while (n--) {
        Node e;
        e.name.resize(8, '\0');
        scanf("%s %d", &e.name[0], &e.k);
        for (int i = 0; i < 8; i++) {
            if (e.name[i] == '\0') {
                e.name.resize(i);
                break;
            }
        }
        unordered_set<int> uset;
        for (int i = 0; i < e.k; i++) {
            int a = 0;
            scanf("%d", &a);
            uset.insert(a);
        }
        e.num = uset.size();

        if (vec.size() < 3) {
            vec.push_back(e);
            if (vec.size() >= 3) build_heap(vec);
        } else if (e > vec[0]) {
            vec[0] = e;
            adjust(vec, 0);
        }
    }

    sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) {
        return e1 > e2;
    });

    if (vec.size() >= 3) {
        printf("%s %s %s", vec[0].name.c_str(), vec[1].name.c_str(), vec[2].name.c_str());
    } else {
        printf("%s", vec[0].name.c_str());
        for (int i = 1; i < vec.size(); i++)
            printf(" %s", vec[i].name.c_str());
        for (int i = 0; i < 3 - vec.size(); i++)
            printf(" -");
    }

    return 0;
}