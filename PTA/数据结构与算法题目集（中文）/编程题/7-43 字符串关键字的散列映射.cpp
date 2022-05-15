/**
 * @file 7-43 字符串关键字的散列映射.cpp
 * @date 2022-05-15
 */

/*
给定一系列由大写英文字母组成的字符串关键字和素数P，
用移位法定义的散列函数H(Key)将关键字Key中的最后3个字符映射为整数，每个字符占5位；
再用除留余数法将整数映射到长度为P的散列表中。
例如将字符串AZDEG插入长度为1009的散列表中，我们首先将26个大写英文字母顺序映射到整数0~25；
再通过移位将其映射为3×32^2+4×32+6=3206；然后根据表长得到3206，即是该字符串的散列映射位置。

发生冲突时请用平方探测法解决。

输入格式:
输入第一行首先给出两个正整数N（≤500）和P（≥2N的最小素数），分别为待插入的关键字总数、以及散列表的长度。
第二行给出N个字符串关键字，每个长度不超过8位，其间以空格分隔。

输出格式:
在一行内输出每个字符串关键字在散列表中的位置。数字间以空格分隔，但行末尾不得有多余空格。

输入样例1:
4 11
HELLO ANNK ZOE LOLI

输出样例1:
3 10 4 0

输入样例2:
6 11
LLO ANNA NNK ZOJ INNK AAA

输出样例2:
3 0 10 9 6 1

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 关键在于平方探测法的理解，注意对于负地址的处理 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int N = 0,                     // 多少个数据
    P = 0;                     // 散列表长度
vector<string> hasht;          // 散列表
vector<pair<string, int>> ins; // 待插入散列表的数据及其插入的索引

/**
 * @brief 输入处理
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;
    hasht.resize(P, string(9, '0')); // 因为每个测试数据的长度都不会超过8位，所以用9位的字符串代表当前位置为空
    ins.resize(N);

    for (int i = 0; i < N; i++)
        cin >> ins[i].first;
}

/**
 * @brief 通过key获取其在散列表中的索引
 * @param str key
 * @return int 索引
 */
int hkey(const string &str) {
    int idx = 0;

    // 注意对于长度在3以下的字符串的处理
    switch (str.size()) {
    case 0:
        idx = 0;
        break;
    case 1:
        idx = str[0] - 'A';
        break;
    case 2:
        idx = (str[0] - 'A') * 32 + (str[1] - 'A');
        break;
    default:
        idx = (str[str.size() - 3] - 'A') * 32 * 32 +
              (str[str.size() - 2] - 'A') * 32 +
              (str[str.size() - 1] - 'A');
        break;
    }
    idx %= P; // 得到对散列表的直接映射地址

    // 如果有冲突的话
    // 这里注意当i=0的时候其实就是在判断当前元素在散列表里的直接映射地址
    // o不ok，不ok的话i++开始平方探测
    for (int i = 0; i <= P / 2; i++) {

        int ti = (idx + i * i) % P;                   // 注意往右边探测的时候超过散列表长度的情况，对P求余使其从左边重新开始
        if (hasht[ti].size() > 8 || hasht[ti] == str) // 字符串长度>8看作空，如果不为空的话或者和当前待插入字符串相等，相同元素返回相同索引
            return ti;

        /* 注意！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
        /* 当平方探测法，对地址  addr-q^2   的时候，有可能超出左边的边界，这个时候
        需要加散列表长度直到>=0之后再对散列表长度求余（当然也许不求余也可以，这里
        求余是为了统筹超出边界和没超出边界的两种情况），负数还是难得求余，最好不要
        去做这种事情，虽然我们都知道这是什么意思，还是慢慢加吧 */
        ti = (idx - i * i + P) % P;

        if (hasht[ti].size() > 8 || hasht[ti] == str)
            return ti;
    }

    return -1;
}

/**
 * @brief 计算每个元素的散列地址
 */
void calc() {
    for (auto &e : ins) {
        int idx = hkey(e.first);
        hasht[idx] = e.first;
        e.second = idx;
    }
}

/**
 * @brief 按格式输出
 */
void print() {
    cout << ins[0].second;
    for (int i = 1; i < N; i++)
        cout << ' ' << ins[i].second;
}

int main() {
    input();
    calc();
    print();
    return 0;
}