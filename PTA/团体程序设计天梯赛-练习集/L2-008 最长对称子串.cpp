/**
 * @file L2-008 最长对称子串.cpp
 * @date 2022-05-23
 */

/*
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，于是你应该输出11。

输入格式：
输入在一行中给出长度不超过1000的非空字符串。

输出格式：
在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?
输出样例：
11
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

/* manacher算法，O(n)线性时间复杂度求字符串中最大回文子串 */

#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief manacher算法求解字符串最长回文子串
 * @param s 待求解的母串
 * @return string 最长回文子串
 */
string manacher(string s) {

    // 特殊情况排除
    if (s.empty() || s.size() == 1)
        return s;

    // 预处理，在每个字符之间加入特殊字符（‘#’），
    // 在首尾加入特殊字符（‘#’），
    for (int i = 0; i < s.size(); i += 2)
        s.insert(i, "#");
    s.push_back('#');

    vector<int> p(s.size()); // i索引处最长半径（不包括i）
    p[0] = 0;                // 初始化第一个元素
    int r = 0;               // 最大右边界索引
    int c = 0;               // 最大右边界所对应的中心索引

    // 遍历每个字符
    for (int i = 1; i < s.size(); i++) {

        // 如果i在r半径里面的话
        if (i < r) {
            p[i] = min(p[2 * c - i], r - i); // 能拿到的至少最大对称半径
        } else {
            p[i] = 0; // 否则只好从零开始
        }

        // 中心扩展
        while (i + p[i] + 1 < s.size() &&
               i - p[i] - 1 >= 0 &&
               s[i + p[i] + 1] == s[i - p[i] - 1])
            p[i]++;

        // 更新最大右边界和其中心索引
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
    }

    // 求出最大回文子串并且去掉所有的特殊字符

    int idx = 0;
    for (int i = 0; i < p.size(); i++)
        if (p[i] > p[idx])
            idx = i;

    string ans = s.substr(idx - p[idx], p[idx] * 2 + 1);
    for (int i = 0; i < ans.size();)
        if (ans[i] == '#')
            ans.erase(i, 1);
        else
            i++;

    return ans;
}

int main() {

    string s;
    for (char c; (c = getchar()) != '\n';)
        s.push_back(c);
    printf("%zu", manacher(s).size());

    return 0;
}