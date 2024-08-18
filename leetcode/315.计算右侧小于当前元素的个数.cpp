/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (37.16%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 80.5K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于
 * nums[i] 的元素的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[5,2,6,1]
 * 输出：[2,1,1,0] 
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    int insert(vector<int> &vec, int num)
    {
        // for (int i = 0; i < vec.size(); i++)
        //     if (vec[i] >= num)
        //     {
        //         vec.insert(vec.begin() + i, num);
        //         return i;
        //     }
        // vec.push_back(num);
        // return vec.size() - 1;

        if (vec.empty())
        {
            vec.push_back(num);
            return 0;
        }

        int left = 0, right = vec.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            if (vec[mid] < num)
                left = mid + 1;
            else
                right = mid;
            mid = (left + right) / 2;
        }

        if (vec[mid] < num)
            mid++;
        vec.insert(vec.begin() + mid, num);
        return mid;
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> res(nums.size()), avec;
        for (int i = nums.size() - 1; i >= 0; i--)
            res[i] = insert(avec, nums[i]);
        return res;
    }
};
// @lc code=end
