/*
 * @lc app=leetcode.cn id=LCR 006 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 006] 两数之和 II - 输入有序数组
 *
 * https://leetcode.cn/problems/kLl5u1/description/
 *
 * algorithms
 * Easy (67.20%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 111.1K
 * Testcase Example:  '[1,2,4,6,10]\n8'
 *
 * 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 *
 * 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 0 开始计数 ，所以答案数组应当满足 0 <=
 * answer[0] < answer[1] < numbers.length 。
 *
 * 假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。
 *
 *
 *
 * 示例 1：
 *
 * 输入：numbers = [1,2,4,6,10], target = 8
 * 输出：[1,3]
 * 解释：2 与 6 之和等于目标数 8 。因此 index1 = 1, index2 = 3 。
 *
 *
 * 示例 2：
 *
 * 输入：numbers = [2,3,4], target = 6
 * 输出：[0,2]
 *
 *
 * 示例 3：
 *
 * 输入：numbers = [-1,0], target = -1
 * 输出：[0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers 按 非递减顺序 排列
 * -1000 <= target <= 1000
 * 仅存在一个有效答案
 *
 *
 *
 *
 * 注意：本题与主站 167
 * 题相似（下标起点不同）：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
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
    vector<int> twoSum(vector<int> &numbers, int target) {
        auto func = [&](int left, int right, int target) {
            while (left <= right) {
                int mid = (left + right) / 2;
                if (numbers[mid] == target) return mid;
                if (numbers[mid] < target) left = mid + 1;
                if (numbers[mid] > target) right = mid - 1;
            }
            return -1;
        };

        for (int i = 0; i < numbers.size(); i++) {
            int j = func(i + 1, numbers.size() - 1, target - numbers[i]);
            if (j != -1) return {i, j};
        }
        return {-1, -1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4,6,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
