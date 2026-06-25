#
# @lc app=leetcode.cn id=2202 lang=python3
# @lcpr version=30204
#
# [2202] K 次操作后最大化顶端元素
#
# https://leetcode.cn/problems/maximize-the-topmost-element-after-k-moves/description/
#
# algorithms
# Medium (23.27%)
# Likes:    38
# Dislikes: 0
# Total Accepted:    11.8K
# Total Submissions: 50.9K
# Testcase Example:  '[5,2,2,4,0,6]\n4'
#
# 给你一个下标从 0 开始的整数数组 nums ，它表示一个 堆 ，其中 nums[0] 是堆顶的元素。
#
# 每一次操作中，你可以执行以下操作 之一 ：
#
#
# 如果堆非空，那么 删除 堆顶端的元素。
# 如果存在 1 个或者多个被删除的元素，你可以从它们中选择任何一个，添加 回堆顶，这个元素成为新的堆顶元素。
#
#
# 同时给你一个整数 k ，它表示你总共需要执行操作的次数。
#
# 请你返回 恰好 执行 k 次操作以后，堆顶元素的 最大值 。如果执行完 k 次操作以后，堆一定为空，请你返回 -1 。
#
#
#
# 示例 1：
#
# 输入：nums = [5,2,2,4,0,6], k = 4
# 输出：5
# 解释：
# 4 次操作后，堆顶元素为 5 的方法之一为：
# - 第 1 次操作：删除堆顶元素 5 ，堆变为 [2,2,4,0,6] 。
# - 第 2 次操作：删除堆顶元素 2 ，堆变为 [2,4,0,6] 。
# - 第 3 次操作：删除堆顶元素 2 ，堆变为 [4,0,6] 。
# - 第 4 次操作：将 5 添加回堆顶，堆变为 [5,4,0,6] 。
# 注意，这不是最后堆顶元素为 5 的唯一方式。但可以证明，4 次操作以后 5 是能得到的最大堆顶元素。
#
#
# 示例 2：
#
# 输入：nums = [2], k = 1
# 输出：-1
# 解释：
# 第 1 次操作中，我们唯一的选择是将堆顶元素弹出堆。
# 由于 1 次操作后无法得到一个非空的堆，所以我们返回 -1 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# 0 <= nums[i], k <= 10^9
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        n = len(nums)
        # 只有一个元素时：奇数次操作必然清空堆，偶数次可以弹了再放回
        if n == 1:
            return -1 if k % 2 == 1 else nums[0]

        # 0 次操作，堆顶就是 nums[0]
        if k == 0:
            return nums[0]

        # 1 次操作只能弹出堆顶，不能放回（因为弹出前没有已删除元素）
        if k == 1:
            return nums[1]

        # k < n：两种策略取最大值
        #   1) 连续弹出 k 次，堆顶变成 nums[k]
        #   2) 弹出前 k-1 个元素，然后把其中的最大值放回堆顶
        if k < n:
            # 取 max(nums[k], max(nums[0..k-2]))
            ans = nums[k]
            for i in range(k - 1):
                if nums[i] > ans:
                    ans = nums[i]
            return ans

        # k == n：不能弹出全部 n 个元素（最后堆会空），
        # 最多弹出前 n-1 个，再把其中的最大值放回
        if k == n:
            return max(nums[: n - 1])

        # k > n：有足够的操作次数，总能通过合理的弹出/放回
        # 序列让全局最大值出现在堆顶
        return max(nums)


# @lc code=end


#
# @lcpr case=start
# [5,2,2,4,0,6]\n4\n
# @lcpr case=end

# @lcpr case=start
# [2]\n1\n
# @lcpr case=end

#
