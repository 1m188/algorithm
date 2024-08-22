/*
 * @lc app=leetcode.cn id=LCR 069 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 069] 山脉数组的峰顶索引
 *
 * https://leetcode.cn/problems/B1IidL/description/
 *
 * algorithms
 * Easy (70.94%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 105.4K
 * Testcase Example:  '[0,1,0]'
 *
 * 符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：
 *
 *
 * arr.length >= 3
 * 存在 i（0 < i < arr.length - 1）使得：
 *
 * arr[0] < arr[1] < ... arr[i-1] < arr[i]
 * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 *
 *
 *
 *
 * 给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i +
 * 1] > ... > arr[arr.length - 1] 的下标 i ，即山峰顶部。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [0,1,0]
 * 输出：1
 *
 *
 * 示例 2：
 *
 * 输入：arr = [1,3,5,4,2]
 * 输出：2
 *
 *
 * 示例 3：
 *
 * 输入：arr = [0,10,5,2]
 * 输出：1
 *
 *
 * 示例 4：
 *
 * 输入：arr = [3,4,5,1]
 * 输出：2
 *
 *
 * 示例 5：
 *
 * 输入：arr = [24,69,100,99,79,78,67,36,26,19]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^6
 * 题目数据保证 arr 是一个山脉数组
 *
 *
 *
 *
 * 进阶：很容易想到时间复杂度 O(n) 的解决方案，你可以设计一个 O(log(n)) 的解决方案吗？
 *
 *
 *
 * 注意：本题与主站 852
 * 题相同：https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
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
    int peakIndexInMountainArray(vector<int> &arr) {
        int i = 1;
        for (; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) break;
        }
        return i - 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [24,69,100,99,79,78,67,36,26,19]\n
// @lcpr case=end

 */
