/*
 * @lc app=leetcode.cn id=5348 lang=cpp
 *
 * [5348] 两个数组间的距离值
 *
 * https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays/description/
 *
 * algorithms
 * Easy (73.79%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 2.4K
 * Testcase Example:  '[4,5,8]\n[10,9,1,8]\n2'
 *
 * 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
 * 
 * 「距离值」 定义为符合此描述的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * 输出：2
 * 解释：
 * 对于 arr1[0]=4 我们有：
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * 对于 arr1[1]=5 我们有：
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * 对于 arr1[2]=8 我们有：
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 500
 * -10^3 <= arr1[i], arr2[j] <= 10^3
 * 0 <= d <= 100
 * 
 * 
 */

#include "vector"
#include "cmath"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int res = 0;
        for (const int &num1 : arr1)
        {
            for (const int &num2 : arr2)
            {
                if (abs(num1 - num2) <= d)
                {
                    goto next;
                }
            }
            res++;
        next:;
        }
        return res;
    }
};
// @lc code=end
