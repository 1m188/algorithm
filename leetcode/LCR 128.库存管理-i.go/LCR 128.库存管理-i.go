/*
 * @lc app=leetcode.cn id=LCR 128 lang=golang
 * @lcpr version=30204
 *
 * [LCR 128] 库存管理 I
 *
 * https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (49.57%)
 * Likes:    872
 * Dislikes: 0
 * Total Accepted:    517.7K
 * Total Submissions: 1M
 * Testcase Example:  '[4,5,8,3,4]'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。原库存表按商品 id
 * 升序排列。现因突发情况需要进行商品紧急调拨，管理员将这批商品 id 提前依次整理至库存表最后。请你找到并返回库存表中编号的 最小的元素
 * 以便及时记录本次调拨。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stock = [4,5,8,3,4]
 * 输出：3
 *
 *
 * 示例 2：
 *
 * 输入：stock = [5,7,9,1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= stock.length <= 5000
 * -5000 <= stock[i] <= 5000
 *
 *
 *
 *
 * 注意：本题与主站 154
 * 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func inventoryManagement(stock []int) int {

	for i := 0; i < len(stock)-1; i++ {
		if stock[i] > stock[i+1] {
			return stock[i+1]
		}
	}
	return stock[0]

}

// @lc code=end

/*
// @lcpr case=start
// [4,5,8,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,9,1,2]\n
// @lcpr case=end

*/
