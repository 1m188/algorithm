/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (75.19%)
 * Likes:    779
 * Dislikes: 0
 * Total Accepted:    127.3K
 * Total Submissions: 169.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现
 * 两次 的整数，并以数组形式返回。
 *
 * 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：[1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * nums 中的每个元素出现 一次 或 两次
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {

        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        for (const int &n : nums)
            cnt[n]++;

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] >= 2) res.push_back(i);
        }
        return std::move(res);
    }
};
// @lc code=end
