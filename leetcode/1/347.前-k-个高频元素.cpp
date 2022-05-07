/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.68%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 118.5K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */

#include "algorithm"
#include "unordered_map"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    void adjust_heap(vector<pair<int, int>> &vec, int left, int right)
    {
        auto tmp = vec[left];
        int m = left * 2 + 1;
        while (m <= right)
        {
            if (m + 1 <= right && vec[m + 1].second > vec[m].second)
                m++;
            if (vec[m].second > tmp.second)
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // unordered_map<int, int> um;
        // for (const int &e : nums)
        //     um[e]++;
        // vector<pair<int, int>> vec;
        // vec.assign(um.begin(), um.end());
        // vector<int> res;
        // while (k--)
        // {
        //     auto it = max_element(vec.begin(), vec.end(), [](const pair<int, int> &e1, const pair<int, int> &e2) { return e1.second < e2.second; });
        //     res.push_back(it->first);
        //     vec.erase(it);
        // }
        // return res;

        unordered_map<int, int> um;
        for (const int &e : nums)
            um[e]++;
        vector<pair<int, int>> vec;
        vec.assign(um.begin(), um.end());
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            adjust_heap(vec, i, vec.size() - 1);
        vector<int> res;
        swap(vec[0], vec.back());
        res.push_back(vec.back().first);
        vec.pop_back();
        k--;
        while (k--)
        {
            adjust_heap(vec, 0, vec.size() - 1);
            swap(vec[0], vec.back());
            res.push_back(vec.back().first);
            vec.pop_back();
        }
        return res;
    }
};
// @lc code=end
