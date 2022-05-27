/**
 * @file JZ50 第一个只出现一次的字符.cpp
 * @date 2022-05-27
 */

/*
描述
在一个长为 字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）


数据范围：0 \le n \le 100000≤n≤10000，且字符串只有字母组成。
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
"google"
复制
返回值：
4
复制
示例2
输入：
"aa"
复制
返回值：
-1
*/

/* 哈希表，存储每个字符出现的次数，之后再次从头开始遍历字符串，
第一次出现次数为1的字符即为结果，如果没有，返回-1 */

#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int FirstNotRepeatingChar(string str) {

        vector<vector<int>> vec(2, vector<int>(26));

        for (const char &c : str) {
            if (isupper(c))
                vec[0][c - 'A']++;
            else
                vec[1][c - 'a']++;
        }

        for (int i = 0; i < str.size(); i++) {
            if ((isupper(str[i]) && vec[0][str[i] - 'A'] == 1) ||
                (islower(str[i]) && vec[1][str[i] - 'a'] == 1))
                return i;
        }

        return -1;
    }
};