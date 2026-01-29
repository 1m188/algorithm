/**
 * @file JZ38 字符串的排列.cpp
 * @date 2022-05-11
 */

/*
描述
输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
例如输入字符串ABC,则输出由字符A,B,C所能排列出来的所有字符串ABC,ACB,BAC,BCA,CBA和CAB。

数据范围：n<10
要求：空间复杂度 O(n!)，时间复杂度 O(n!)
输入描述：
输入一个字符串,长度不超过10,字符只包括大小写字母。
示例1
输入：
"ab"

返回值：
["ab","ba"]

说明：
返回["ba","ab"]也是正确的         
示例2
输入：
"aab"

返回值：
["aab","aba","baa"]

示例3
输入：
"abc"

返回值：
["abc","acb","bac","bca","cab","cba"]

示例4
输入：
""

返回值：
[]
*/

/* dfs求所有组合可能，注意对重复的字符串进行剔除 */

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  private:
    vector<bool> flags; // 当前字符是否被使用的标志
    unordered_set<string> ans; // 集合剔除重复，unordered不排序更快

    /**
     * @brief dfs递归
     * @param tmpt 用于排序的字符的集合
     * @param str 当前中间结果
     * @param n 已使用多少字符
     */
    void dfs(const string &tmpt, string &&str = "", int n = 0) {
        if (n >= flags.size()) {
            ans.insert(str);
            return;
        }

        for (int i = 0; i < flags.size(); i++) {
            if (!flags[i]) {
                flags[i] = true;
                str.push_back(tmpt[i]);
                dfs(tmpt, move(str), n + 1);
                str.pop_back();
                flags[i] = false;
            }
        }
    }

  public:
    vector<string> Permutation(string str) {
        if (str.empty())
            return {};

        flags.resize(str.size());
        dfs(str);
        return vector<string>(ans.begin(), ans.end());
    }
};