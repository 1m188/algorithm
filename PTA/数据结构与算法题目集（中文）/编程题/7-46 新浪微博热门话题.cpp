/**
 * @file 7-46 新浪微博热门话题.cpp
 * @date 2022-05-16
 */

/*
新浪微博可以在发言中嵌入“话题”，即将发言中的话题文字写在一对“#”之间，就可以生成话题链接，
点击链接可以看到有多少人在跟自己讨论相同或者相似的话题。
新浪微博还会随时更新热门话题列表，并将最热门的话题放在醒目的位置推荐大家关注。

本题目要求实现一个简化的热门话题推荐功能，从大量英文（因为中文分词处理比较麻烦）微博中解析出话题，
找出被最多条微博提到的话题。

输入格式:
输入说明：输入首先给出一个正整数N（≤10^5），随后N行，每行给出一条英文微博，其长度不超过140个字符。
任何包含在一对最近的#中的内容均被认为是一个话题，输入保证#成对出现。

输出格式:
第一行输出被最多条微博提到的话题，第二行输出其被提到的微博条数。
如果这样的话题不唯一，则输出按字母序最小的话题，并在第三行输出And k more ...，
其中k是另外几条热门话题的条数。输入保证至少存在一条话题。

注意：两条话题被认为是相同的，如果在去掉所有非英文字母和数字的符号、并忽略大小写区别后，
它们是相同的字符串；同时它们有完全相同的分词。输出时除首字母大写外，只保留小写英文字母和数字，
并用一个空格分隔原文中的单词。

输入样例:
4
This is a #test of topic#.
Another #Test of topic.#
This is a #Hot# #Hot# topic
Another #hot!# #Hot# topic

输出样例:
Hot
2
And 1 more ...

代码长度限制
16 KB

时间限制
300 ms

内存限制
64 MB
*/

/* 麻烦却不难，散列表的应用，关键在于如何对原始话题进行处理 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

unordered_map<string, int> ump; // 用来存储 处理后的话题-出现的微博的条数 这个映射

/**
 * @brief 将原始话题进行处理，干掉其中非数字和字母的字符，并且将所有分词之间变成一个空格。
          主要就是把所有的字母变成小写，把数字不变，其他的所有东西变成空格，然后去除头尾
          空格，合并所有重复空格，然后把首字母大写即可
 * @param s 待处理字符串
 */
void sformat(string &s) {
    for (char &c : s) {
        if (isalpha(c))
            c = tolower(c); // 字母变小写
        else if (!isdigit(c))
            c = ' '; //
    }

    while (s.front() == ' ') // 去掉头部空格
        s.erase(s.begin());
    while (s.back() == ' ') // 去掉尾部空格
        s.pop_back();

    s[0] = toupper(s[0]); // 首字母大写

    for (int i = 0; i < s.size(); i++) { // 合并多余空格
        if (s[i] == ' ') {
            int end = i + 1;
            while (s[end] == ' ')
                end++;
            s.erase(i + 1, end - i - 1);
        }
    }
}

/**
 * @brief 对每一行中提取出原始话题字符串，并且处理之后对其去重，提到的话题其被提到微博数都+1
 * @param line 读取的一行
 */
void handle(const string &line) {
    unordered_set<string> uset; // 用来去重
    string tmp;
    bool flag = false;

    for (const char &c : line) {
        if (c == '#') {
            if (!flag)
                flag = true;
            else {
                flag = false;
                sformat(tmp);
                uset.insert(tmp);
                tmp.clear();
            }
        } else if (flag) {
            tmp.push_back(c);
        }
    }

    for (const string &e : uset)
        ump[e]++;
}

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    cin.get();

    while (n--) {
        string line;
        getline(cin, line);
        handle(line);
    }
}

/**
 * @brief 对所有话题及其出现次数进行排序并输出
 */
void calc() {
    vector<pair<string, int>> vec(ump.begin(), ump.end());

    // 出现次数多的排前面，次数相同的按照字典序排
    sort(vec.begin(), vec.end(), [](const pair<string, int> &e1, const pair<string, int> &e2) {
        if (e1.second != e2.second)
            return e1.second > e2.second;
        else
            return e1.first < e2.first;
    });

    // 求出现相同最多次数的话题数
    int k = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].second == vec[0].second)
            k++;
        else
            break;
    }

    // 输出
    cout << vec[0].first << '\n'
         << vec[0].second;
    if (k)
        cout << "\nAnd " << k << " more ...";
}

int main() {
    input();
    calc();
    return 0;
}