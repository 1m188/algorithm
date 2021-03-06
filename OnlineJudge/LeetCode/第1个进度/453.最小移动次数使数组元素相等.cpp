/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (53.09%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 15.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [1,2,3]
 * 
 * 输出:
 * 3
 * 
 * 解释:
 * 只需要3次移动（注意每次移动会增加两个元素的值）：
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // 首先,我们知道,为了在最小移动内使所有元素相等，我们需要在数组的最大元素之外的所有元素中执行增加。因此,在暴力法中，我们扫描整个数组以查找最大值和最小元素。此后，我们将 11 添加到除最大元素之外的所有元素，并增加移动数的计数。同样，我们重复相同的过程，直到最大元素和最小元素彼此相等。

        // 在上一方法中，每一步对每个元素增加 11。我们可以在一定程度上改进这一方法。为了让最小元素等于最大元素，至少需要加 kk 次。在那之后，最大元素可能发生变化。因此，我们一次性增加增量 k=max-min，并将移动次数增加 k。然后，对整个数组进行扫描，找到新的最大值和最小值，重复这一过程直到最大元素和最小元素相等。

        //         如果对数组进行排序得到有序数列 aa，可以有效地简化问题。类似于方法二，我们用 diff=max-min 更新数列。但不同的是，我们不需要每次都遍历整个数组来得到最大和最小值，而是可以利用数组的有序性在 O(1)O(1) 时间内找到更新后的最大值和最小值。此外，我们也不需要真的更新数组的值。
        // 为了便于理解，下面逐步讲解该算法。

        // 首先，假设我们在每一步计算 diff 之后正在更新有序数组的元素。下面展示如何在不遍历数组的情况下找到最大最小值。在第一步中，最后的元素即为最大值，因此 diff=a[n-1]-a[0]。我们对除了最后一个元素以外所有元素增加 diff。

        // 现在，更新后的数组开头元素 a'[0] 变成了 a[0]+diff=a[n-1]。因此，a'[0] 等于上一步中最大的元素 a[n-1]。由于数组排过序，直到 i-2 的元素都满足 a[j]>=a[j-1]。因此，更新之后，a'[n-2] 即为最大元素。而 a[0] 依然是最小元素。

        // 于是，在第二次更新时，diff=a[n-2]-a[0]。更新后 a''[0] 会成为 a'[n-2]，与上一次迭代类似。

        // 然后，由于 a'[0] 和 a'[n-1] 相等，在第二次更新后，a''[0]=a''[n-1]=a'[n-2]。于是，最大的元素为 a[n-3]。

        // 于是，我们可以继续这样，在每一步用最大最小值差更新数组。

        // 下面进入第二步。第一步中，我们假设每一步会更新数组 aa 中的元素。但事实上，我们不需要这么做。这是因为，即使是在更新元素之后，我们要登记的 diff 差值也不变，因为 max 和 min 增加的数字相同。

        // 于是，我们可以简单的将数组排序一次， moves=\sum_{i=1}^{n-1} (a[i]-a[0])moves=∑
        // i=1
        // n−1
        // ​
        //  (a[i]−a[0])。

        // AC
        // int res = 0;
        // sort(nums.begin(), nums.end());
        // for (int i = nums.size() - 1; i >= 0; i--)
        // {
        //     res += nums[i] - nums[0];
        // }
        // return res;

        // 题意可理解位每次让一个值减去1，使得所有的值相等，那理想情况就是每个值最终等于最小值。
        // 那么题目就转换为所有值减去最小值的和。
        // AC
        int res = 0;
        auto minit = min_element(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res += nums[i] - *minit;
        }
        return res;
    }
};
// @lc code=end
