/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 *
 * https://leetcode-cn.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (49.40%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 31.6K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * 给一非空的单词列表，返回前 k 个出现次数最多的单词。
 * 
 * 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
 * 
 * 示例 1：
 * 
 * 
 * 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * 输出: ["i", "love"]
 * 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
 * ⁠   注意，按字母顺序 "i" 在 "love" 之前。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
 * k = 4
 * 输出: ["the", "is", "sunny", "day"]
 * 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
 * ⁠   出现次数依次为 4, 3, 2 和 1 次。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
 * 输入的单词均由小写字母组成。
 * 
 * 
 * 
 * 
 * 扩展练习：
 * 
 * 
 * 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
 * 
 * 
 */

#include "functional"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    static int cmp(const pair<string, int> &p1, const pair<string, int> &p2)
    {
        if (p1.second != p2.second)
        {
            return p1.second > p2.second ? 1 : -1;
        }
        else if (p1.first != p2.first)
        {
            return p1.first < p2.first ? 1 : -1;
        }
        return 0;
    }

    template <typename T>
    void adjust_heap(vector<T> &vec, const function<int(const T &, const T &)> &cmp, int left, int right)
    {
        auto tmp = vec[left];
        int m = left * 2 + 1;
        while (m <= right)
        {
            if (m + 1 <= right && cmp(vec[m + 1], vec[m]) > 0)
                m++;
            if (cmp(vec[m], tmp) > 0)
            {
                vec[left] = vec[m];
                left = m;
                m = left * 2 + 1;
            }
            else
                break;
        }
        vec[left] = tmp;
    }

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> um;
        for (const string &e : words)
            um[e]++;
        vector<pair<string, int>> vec;
        vec.assign(um.begin(), um.end());
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            adjust_heap<pair<string, int>>(vec, cmp, i, vec.size() - 1);
        vector<string> res;
        swap(vec[0], vec.back());
        res.push_back(vec.back().first);
        vec.pop_back();
        k--;
        while (k--)
        {
            adjust_heap<pair<string, int>>(vec, cmp, 0, vec.size() - 1);
            swap(vec[0], vec.back());
            res.push_back(vec.back().first);
            vec.pop_back();
        }
        return res;
    }
};
// @lc code=end
