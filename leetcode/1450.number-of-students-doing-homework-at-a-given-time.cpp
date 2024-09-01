/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 * @lcpr version=30204
 *
 * [1450] 在既定时间做作业的学生人数
 *
 * https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/description/
 *
 * algorithms
 * Easy (82.42%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    68K
 * Total Submissions: 82.2K
 * Testcase Example:  '[1,2,3]\n[3,2,7]\n4'
 *
 * 给你两个整数数组 startTime（开始时间）和 endTime（结束时间），并指定一个整数 queryTime 作为查询时间。
 *
 * 已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。
 *
 * 请返回在查询时间 queryTime 时正在做作业的学生人数。形式上，返回能够使 queryTime 处于区间 [startTime[i],
 * endTime[i]]（含）的学生人数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
 * 输出：1
 * 解释：一共有 3 名学生。
 * 第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
 * 第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
 * 第三名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。
 *
 *
 * 示例 2：
 *
 * 输入：startTime = [4], endTime = [4], queryTime = 4
 * 输出：1
 * 解释：在查询时间只有一名学生在做作业。
 *
 *
 * 示例 3：
 *
 * 输入：startTime = [4], endTime = [4], queryTime = 5
 * 输出：0
 *
 *
 * 示例 4：
 *
 * 输入：startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
 * 输出：0
 *
 *
 * 示例 5：
 *
 * 输入：startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10],
 * queryTime = 5
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * startTime.length == endTime.length
 * 1 <= startTime.length <= 100
 * 1 <= startTime[i] <= endTime[i] <= 1000
 * 1 <= queryTime <= 1000
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
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        int res = 0;
        for (int i = 0; i < startTime.size(); i++) {
            res += queryTime >= startTime[i] && queryTime <= endTime[i];
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[3,2,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [4]\n[4]\n4\n
// @lcpr case=end

// @lcpr case=start
// [4]\n[4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n[1,3,2,4]\n7\n
// @lcpr case=end

// @lcpr case=start
// [9,8,7,6,5,4,3,2,1]\n[10,10,10,10,10,10,10,10,10]\n5\n
// @lcpr case=end

 */
