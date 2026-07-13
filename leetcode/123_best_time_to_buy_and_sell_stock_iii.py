#
# @lc app=leetcode.cn id=123 lang=python3
# @lcpr version=30204
#
# [123] 买卖股票的最佳时机 III
#
# https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
#
# algorithms
# Hard (62.79%)
# Likes:    1935
# Dislikes: 0
# Total Accepted:    468.6K
# Total Submissions: 746.2K
# Testcase Example:  '[3,3,5,0,0,3,1,4]'
#
# 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
#
# 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
#
# 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
#
#
#
# 示例 1:
#
# 输入：prices = [3,3,5,0,0,3,1,4]
# 输出：6
# 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
# 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
#
# 示例 2：
#
# 输入：prices = [1,2,3,4,5]
# 输出：4
# 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
# 。
# 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
# 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
#
#
# 示例 3：
#
# 输入：prices = [7,6,4,3,1]
# 输出：0
# 解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
#
# 示例 4：
#
# 输入：prices = [1]
# 输出：0
#
#
#
#
# 提示：
#
#
# 1 <= prices.length <= 10^5
# 0 <= prices[i] <= 10^5
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        前后缀扫描 + 枚举分割点

        核心思路：
        - left[i] = [0..i] 内最多一笔交易的最大利润
        - right[i] = [i..n-1] 内最多一笔交易的最大利润
        - 答案 = max(left[i] + right[i])，其中两笔交易在 i 处分隔
        - 注意：right[i] 包含第 i 天，所以 left[i] + right[i+1] 也行；
          这里直接 left[i] + right[i] 并理解为一笔在 [0,i] 一笔在 [i,n-1]
          可能重叠在第 i 天卖出并买入，相当于只做了一笔，结果正确
        """
        n = len(prices)
        if n < 2:
            return 0

        # 从左到右：left[i] = [0..i] 内单笔交易最大利润
        left = [0] * n
        min_price = prices[0]
        for i in range(1, n):
            left[i] = max(left[i - 1], prices[i] - min_price)
            if prices[i] < min_price:
                min_price = prices[i]

        # 从右到左：right[i] = [i..n-1] 内单笔交易最大利润
        right = [0] * n
        max_price = prices[-1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], max_price - prices[i])
            if prices[i] > max_price:
                max_price = prices[i]

        # 枚举分割点，两笔交易分别在 [0..i] 和 [i..n-1]
        ans = 0
        for i in range(n):
            ans = max(ans, left[i] + right[i])

        return ans


# @lc code=end


#
# @lcpr case=start
# [3,3,5,0,0,3,1,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,4,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#
