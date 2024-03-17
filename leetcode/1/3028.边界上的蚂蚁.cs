/*
 * @lc app=leetcode.cn id=3028 lang=csharp
 *
 * [3028] 边界上的蚂蚁
 *
 * https://leetcode.cn/problems/ant-on-the-boundary/description/
 *
 * algorithms
 * Easy (86.43%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 6.2K
 * Testcase Example:  '[2,3,-5]'
 *
 * 边界上有一只蚂蚁，它有时向 左 走，有时向 右 走。
 * 
 * 给你一个 非零 整数数组 nums 。蚂蚁会按顺序读取 nums 中的元素，从第一个元素开始直到结束。每一步，蚂蚁会根据当前元素的值移动：
 * 
 * 
 * 如果 nums[i] < 0 ，向 左 移动 -nums[i]单位。
 * 如果 nums[i] > 0 ，向 右 移动 nums[i]单位。
 * 
 * 
 * 返回蚂蚁 返回 到边界上的次数。
 * 
 * 注意：
 * 
 * 
 * 边界两侧有无限的空间。
 * 只有在蚂蚁移动了 |nums[i]| 单位后才检查它是否位于边界上。换句话说，如果蚂蚁只是在移动过程中穿过了边界，则不会计算在内。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,-5]
 * 输出：1
 * 解释：第 1 步后，蚂蚁距边界右侧 2 单位远。
 * 第 2 步后，蚂蚁距边界右侧 5 单位远。
 * 第 3 步后，蚂蚁位于边界上。
 * 所以答案是 1 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,-3,-4]
 * 输出：0
 * 解释：第 1 步后，蚂蚁距边界右侧 3 单位远。
 * 第 2 步后，蚂蚁距边界右侧 5 单位远。
 * 第 3 步后，蚂蚁距边界右侧 2 单位远。
 * 第 4 步后，蚂蚁距边界左侧 2 单位远。
 * 蚂蚁从未返回到边界上，所以答案是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * -10 <= nums[i] <= 10
 * nums[i] != 0
 * 
 * 
 */

// @lc code=start
public class Solution
{
    public int ReturnToBoundaryCount(int[] nums)
    {
        int res = 0, tmp = 0;
        foreach (var num in nums)
        {
            tmp += num;
            if (tmp == 0) res++;
        }
        return res;
    }
}
// @lc code=end

