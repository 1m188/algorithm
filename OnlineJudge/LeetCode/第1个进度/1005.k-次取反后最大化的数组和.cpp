/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 *
 * https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (50.90%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 12.9K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * 给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K
 * 次。（我们可以多次选择同一个索引 i。）
 * 
 * 以这种方式修改数组后，返回数组可能的最大和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [4,2,3], K = 1
 * 输出：5
 * 解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [3,-1,0,2], K = 3
 * 输出：6
 * 解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [2,-3,-1,5,-4], K = 2
 * 输出：13
 * 解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 1 <= K <= 10000
 * -100 <= A[i] <= 100
 * 
 * 
 */

#include "vector"
#include "numeric"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        if (A.size() == 1)
        {
            return -A[0];
        }
        else
        {
            sort(A.begin(), A.end());
            int index = 0;
            while (A[index] < 0 && K > 0)
            {
                A[index++] *= -1;
                K--;
            }
            if (A[index] != 0 && K % 2)
            {
                sort(A.begin(), A.end());
                A[0] *= -1;
            }
            return accumulate(A.begin(), A.end(), 0);
        }
    }
};
// @lc code=end
