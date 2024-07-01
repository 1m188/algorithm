/*
 * @lc app=leetcode.cn id=3162 lang=cpp
 *
 * [3162] 优质数对的总数 I
 *
 * https://leetcode.cn/problems/find-the-number-of-good-pairs-i/description/
 *
 * algorithms
 * Easy (81.79%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 6.9K
 * Testcase Example:  '[1,3,4]\n[1,3,4]\n1'
 *
 * 给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你一个正整数 k。
 *
 * 如果 nums1[i] 可以被 nums2[j] * k 整除，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j
 * <= m - 1）。
 *
 * 返回 优质数对 的总数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3,4], nums2 = [1,3,4], k = 1
 *
 * 输出：5
 *
 * 解释：
 *
 * 5个优质数对分别是 (0, 0), (1, 0), (1, 1), (2, 0), 和 (2, 2)。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2,4,12], nums2 = [2,4], k = 3
 *
 * 输出：2
 *
 * 解释：
 *
 * 2个优质数对分别是 (3, 0) 和 (3, 1)。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, m <= 50
 * 1 <= nums1[i], nums2[j] <= 50
 * 1 <= k <= 50
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {

        int res = 0;
        int n = nums1.size(), m = nums2.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] % (nums2[j] * k) == 0) res++;
            }
        }

        return res;
    }
};
// @lc code=end
