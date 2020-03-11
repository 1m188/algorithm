/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode-cn.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (54.78%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 22.9K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
 * 
 * 如果不能形成任何面积不为零的三角形，返回 0。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1,2]
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,1]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：[3,2,3,4]
 * 输出：10
 * 
 * 
 * 示例 4：
 * 
 * 输入：[3,6,2,3]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 1 <= A[i] <= 10^6
 * 
 * 
 */

// 方法：排序
// 思路
// 不失一般性的，我们假设三角形的边长满足 a \leq b \leq ca≤b≤c。那么这三条边组成三角形的面积非零的充分必要条件是 a + b > c。
// 再假设我们已经知道 cc 的长度了，我们没有理由不从数组中选择尽可能大的 aa 与 bb。因为当且仅当 a + b > c 的时候，它们才能组成一个三角形。
// 算法
// 基于这种想法，一个简单的算法就呼之欲出：排序数组。对于数组内任意的 c，我们选择满足条件的最大的 a≤b≤c，也就是大到小排序，位于 c 后面的两个元素。 从大到小枚举 c，如果能组成三角形的话，我们就返回答案。

// 看了官网题解才明白，但是不明白的是如果按照这个代码，倘若最后三个不能够组成三角形，但是倒数第三个和第四个以及倒数第一个能够组成的三角形的周长比倒数第二个开始往前三个所组成的
// 三角形的周长更长的话？

// ↑ 明白了，如果两个小的边长之和无法大于第三边的话，那么更小的两边之长必会小于第三边，所以这种情况下的三角形不存在，最大边必须变小。

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = A.size() - 1; i >= 2; i--)
        {
            if (A[i - 2] + A[i - 1] > A[i])
            {
                res = A[i - 2] + A[i - 1] + A[i];
                break;
            }
        }
        return res;
    }
};
// @lc code=end
