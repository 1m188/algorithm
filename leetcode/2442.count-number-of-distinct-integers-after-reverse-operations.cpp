/*
 * @lc app=leetcode.cn id=2442 lang=cpp
 * @lcpr version=30204
 *
 * [2442] 反转之后不同整数的数目
 *
 * https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations/description/
 *
 * algorithms
 * Medium (75.75%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 16.3K
 * Testcase Example:  '[1,13,10,12,31]'
 *
 * 给你一个由 正 整数组成的数组 nums 。
 *
 * 你必须取出数组中的每个整数，反转其中每个数位，并将反转后得到的数字添加到数组的末尾。这一操作只针对 nums 中原有的整数执行。
 *
 * 返回结果数组中 不同 整数的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,13,10,12,31]
 * 输出：6
 * 解释：反转每个数字后，结果数组是 [1,13,10,12,31,1,31,1,21,13] 。
 * 反转后得到的数字添加到数组的末尾并按斜体加粗表示。注意对于整数 10 ，反转之后会变成 01 ，即 1 。
 * 数组中不同整数的数目为 6（数字 1、10、12、13、21 和 31）。
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2]
 * 输出：1
 * 解释：反转每个数字后，结果数组是 [2,2,2,2,2,2] 。
 * 数组中不同整数的数目为 1（数字 2）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 */
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countDistinctIntegers(vector<int> &nums) {
        unordered_set<int> uset;
        for (const int &e : nums) {
            uset.insert(e);
            string s = to_string(e);
            reverse(s.begin(), s.end());
            int x = stoi(s);
            uset.insert(x);
        }
        return uset.size();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,13,10,12,31]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

 */
