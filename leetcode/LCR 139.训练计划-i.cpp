/*
 * @lc app=leetcode.cn id=LCR 139 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 139] 训练计划 I
 *
 * https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/description/
 *
 * algorithms
 * Easy (65.02%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    409.9K
 * Total Submissions: 630.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 教练使用整数数组 actions
 * 记录一系列核心肌群训练项目编号。为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。请将调整后的训练项目编号以 数组
 * 形式返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：actions = [1,2,3,4,5]
 * 输出：[1,3,5,2,4]
 * 解释：为正确答案之一
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= actions.length <= 50000
 * 0 <= actions[i] <= 10000
 *
 *
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
    vector<int> trainingPlan(vector<int> &actions) {
        vector<int> vec1, vec2;
        for (const int &i : actions) {
            if (i & 0x1)
                vec1.push_back(i);
            else
                vec2.push_back(i);
        }
        for (const int &i : vec2)
            vec1.push_back(i);
        return vec1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
