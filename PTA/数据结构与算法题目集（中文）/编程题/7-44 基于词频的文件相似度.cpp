/**
 * @file 7-44 基于词频的文件相似度.cpp
 * @date 2022-05-15
 */

/*
实现一种简单原始的文件相似度计算，即以两文件的公共词汇占总词汇的比例来定义相似度。
为简化问题，这里不考虑中文（因为分词太难了），只考虑长度不小于3、且不超过10的英文单词，
长度超过10的只考虑前10个字母。

输入格式:
输入首先给出正整数N（≤100），为文件总数。随后按以下格式给出每个文件的内容：
首先给出文件正文，最后在一行中只给出一个字符#，表示文件结束。在N个文件内容结束之后，
给出查询总数M（≤10^4），随后M行，每行给出一对文件编号，其间以空格分隔。
这里假设文件按给出的顺序从1到N编号。

输出格式:
针对每一条查询，在一行中输出两文件的相似度，即两文件的公共词汇量占两文件总词汇量的百分比，
精确到小数点后1位。注意这里的一个“单词”只包括仅由英文字母组成的、长度不小于3、且不超过10的英文单词，
长度超过10的只考虑前10个字母。单词间以任何非英文字母隔开。
另外，大小写不同的同一单词被认为是相同的单词，例如“You”和“you”是同一个单词。

输入样例:
3
Aaa Bbb Ccc
#
Bbb Ccc Ddd
#
Aaa2 ccc Eee
is at Ddd@Fff
#
2
1 2
1 3

输出样例:
50.0%
33.3%

代码长度限制
16 KB

时间限制
2000 ms

内存限制
64 MB
*/

/* 对散列的应用，其实在这一题里面用C++自带的散列数据结构即可，关键在于对于单词的处理和分割，
对于单词的查找和比率的计算 */

#include <cctype>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int N = 0, // 文件数目
    M = 0; // 待查找数

// 这里用vector是可以方便和文件数目进行查找
// 用set是为了对其中的string自动排序，这样就可以直接线性查找了
// （虽然是线性查找，但是插入却要耗费时间，而另一种unordered_set插入不需要耗费排序的时间
// 但查找需要在树上查找，不清楚这两种哪个消耗的时间更多，这里就用线性查找的方法了，最后最慢的
// 也只是300+ms）
vector<set<string>> files; // 所有文件

/**
 * @brief 处理单词，并将其插入到相应文件的set中去
 * @param str 待处理的单词
 * @param n 待插入的文件编号
 */
void handle(string &str, int n) {
    if (str.size() < 3) // 长度过小的文件就不浪费时间了
        return;
    for (char &c : str) // 大小写不敏感，全部改小写
        if (isalpha(c) && isupper(c))
            c = tolower(c);

    string tmp;
    for (const char &c : str) {
        if (isalpha(c)) // 所有的英文字母都加入
            tmp.push_back(c);
        else if (!tmp.empty()) { // 临时单词非空的时候
            if (tmp.size() > 10) // 过长截断
                tmp = tmp.substr(0, 10);
            if (tmp.size() >= 3) // 过短忽略
                files[n].insert(tmp);
            tmp.clear(); // 清空
        }
    }
    if (!tmp.empty()) { // 最后出来之后可能还有剩余的单词没处理完
        if (tmp.size() > 10)
            tmp = tmp.substr(0, 10);
        if (tmp.size() >= 3)
            files[n].insert(tmp);
    }
}

/**
 * @brief 计算比率
 * @param n1 待计算的文件编号
 * @param n2 待计算的文件编号
 * @return double 比率
 */
double rate(int n1, int n2) {
    int total = files[n1].size() + files[n2].size(); // 总的数目，包含重复内容
    int ans = 0;                                     // 重复内容

    /* 这里就是所谓的线性查找，因为已经按照顺序排好了 */
    auto it1 = files[n1].begin(), it2 = files[n2].begin();
    while (it1 != files[n1].end() && it2 != files[n2].end()) {
        if (*it1 == *it2) {
            ans++;
            it1++, it2++;
        } else if (*it1 > *it2)
            it2++;
        else
            it1++;
    }

    // 计算比率的时候记得要从总的包含重复的数目中减去重复内容
    return double(ans) / (total - ans);
}

/**
 * @brief 输入，虽说是输入但其实已经把所有事情做完了
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    files.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        string s;
        // 对于每个由空格分割的部分，拿进去处理（题目中说单词由所有非英文字母分割，
        // 所以空格分割的部分不可能连接同一个英文单词，在里面再对其他的字符做划分）
        while (cin >> s && s != "#") {
            handle(s, i);
        }
    }

    // 对所有输入查找数据进行查找并按格式输出
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << setiosflags(ios::fixed) << setprecision(1)
             << rate(a, b) * 100 << "%\n";
    }
}

int main() {
    input();
    return 0;
}