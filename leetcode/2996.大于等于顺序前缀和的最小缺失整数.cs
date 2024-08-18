/*
 * @lc app=leetcode.cn id=2996 lang=csharp
 *
 * [2996] 大于等于顺序前缀和的最小缺失整数
 *
 * https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/
 *
 * algorithms
 * Easy (36.87%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 8.8K
 * Testcase Example:  '[1,2,3,2,5]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 * 
 * 如果一个前缀 nums[0..i] 满足对于 1 <= j <= i 的所有元素都有 nums[j] = nums[j - 1] + 1
 * ，那么我们称这个前缀是一个 顺序前缀 。特殊情况是，只包含 nums[0] 的前缀也是一个 顺序前缀 。
 * 
 * 请你返回 nums 中没有出现过的 最小 整数 x ，满足 x 大于等于 最长 顺序前缀的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,2,5]
 * 输出：6
 * 解释：nums 的最长顺序前缀是 [1,2,3] ，和为 6 ，6 不在数组中，所以 6 是大于等于最长顺序前缀和的最小整数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,5,1,12,14,13]
 * 输出：15
 * 解释：nums 的最长顺序前缀是 [3,4,5] ，和为 12 ，12、13 和 14 都在数组中，但 15 不在，所以 15
 * 是大于等于最长顺序前缀和的最小整数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 * 
 * 
 */

// @lc code=start
using System;
using System.Linq;

public class Solution
{
    public int MissingInteger(int[] nums)
    {
        // 寻找最长顺序前缀的和
        int sum = nums[0];
        int length = 1;
        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                length++;
                sum += nums[i];
            }
            else
            {
                break;
            }
        }

        var li = nums.ToList();
        li.Sort();

        // 二分查找到目前的和
        int idx = BinaryFind(li.ToArray(), sum);
        if (idx != -1)
        {
            for (int i = idx; i < li.Count; i++)
            {
                if (li[i] == sum) sum++;
                else if (li[i] > sum) break;
            }
        }
        return sum;
    }

    public int BinaryFind(int[] nums, int target)
    {
        int left = 0, right = nums.Length - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
}
// @lc code=end

