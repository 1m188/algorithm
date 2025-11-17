/*
 * @lc app=leetcode.cn id=3731 lang=csharp
 * @lcpr version=30204
 *
 * [3731] 找出缺失的元素
 *
 * https://leetcode.cn/problems/find-missing-elements/description/
 *
 * algorithms
 * Easy (81.66%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 3.9K
 * Testcase Example:  '[1,4,2,5]'
 *
 * 给你一个整数数组 nums ，数组由若干 互不相同 的整数组成。
 * 
 * 数组 nums 原本包含了某个范围内的 所有整数 。但现在，其中可能 缺失 部分整数。
 * 
 * 该范围内的 最小 整数和 最大 整数仍然存在于 nums 中。
 * 
 * 返回一个 有序 列表，包含该范围内缺失的所有整数，并 按从小到大排序。如果没有缺失的整数，返回一个 空 列表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,4,2,5]
 * 
 * 输出： [3]
 * 
 * 解释：
 * 
 * 最小整数为 1，最大整数为 5，因此完整的范围应为 [1,2,3,4,5]。其中只有 3 缺失。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [7,8,6,9]
 * 
 * 输出： []
 * 
 * 解释：
 * 
 * 最小整数为 6，最大整数为 9，因此完整的范围为 [6,7,8,9]。所有整数均已存在，因此没有缺失的整数。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： nums = [5,1]
 * 
 * 输出： [2,3,4]
 * 
 * 解释：
 * 
 * 最小整数为 1，最大整数为 5，因此完整的范围应为 [1,2,3,4,5]。缺失的整数为 2、3 和 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
public class Solution
{
    public IList<int> FindMissingElements(int[] nums)
    {
        var min = nums.Min();
        var max = nums.Max();
        var length = max - min + 1;

        var res = new bool[length];
        foreach (var num in nums)
        {
            res[num - min] = true;
        }

        return [.. res.Select((b, i) => b ? -1 : i + min).Where(x => x != -1)];
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,4,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1]\n
// @lcpr case=end

 */

