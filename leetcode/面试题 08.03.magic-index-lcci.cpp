/*
 * @lc app=leetcode.cn id=面试题 08.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.03] 魔术索引
 *
 * https://leetcode.cn/problems/magic-index-lcci/description/
 *
 * LCCI
 * Easy (67.29%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    65.7K
 * Total Submissions: 97.6K
 * Testcase Example:  '[0, 2, 3, 4, 5]'
 *
 * 魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] =
 * i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
 *
 * 示例1:
 *
 * ⁠输入：nums = [0, 2, 3, 4, 5]
 * ⁠输出：0
 * ⁠说明: 0下标的元素为0
 *
 *
 * 示例2:
 *
 * ⁠输入：nums = [1, 1, 1]
 * ⁠输出：1
 *
 *
 * 说明:
 *
 *
 * nums长度在[1, 1000000]之间
 * 此题为原书中的 Follow-up，即数组中可能包含重复元素的版本
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findMagicIndex(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) return i;
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0, 2, 3, 4, 5]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1]\n
// @lcpr case=end

 */
