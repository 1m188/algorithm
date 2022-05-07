/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.04%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    98.8K
 * Total Submissions: 156.4K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

#include "cstdint"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.empty())
            return {};

        vector<vector<string>> res;
        const vector<uint> a{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

        unordered_map<uint64_t, vector<string>> umap;
        for (const string &str : strs)
        {
            uint64_t aa = 1;
            for (const char &c : str)
                aa *= a[c - 'a'];
            umap[aa].push_back(str);
        }

        for (const auto &e : umap)
            res.push_back(e.second);

        return res;
    }
};
// @lc code=end
