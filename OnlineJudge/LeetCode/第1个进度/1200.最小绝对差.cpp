/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (65.90%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 9.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 * 
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */

#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = 2 * 1e6;
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int nDiff = abs(arr[i + 1] - arr[i]);
            if (nDiff < diff)
            {
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
                diff = nDiff;
            }
            else if (nDiff == diff)
            {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
// @lc code=end
