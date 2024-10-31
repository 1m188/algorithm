/*
 * @lc app=leetcode.cn id=LCR 145 lang=golang
 * @lcpr version=30204
 *
 * [LCR 145] 判断对称二叉树
 *
 * https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/
 *
 * algorithms
 * Easy (57.68%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    319.5K
 * Total Submissions: 553.9K
 * Testcase Example:  '[6,7,7,8,9,9,8]'
 *
 * 请设计一个函数判断一棵二叉树是否 轴对称 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [6,7,7,8,9,9,8]
 * 输出：true
 * 解释：从图中可看出树是轴对称的。
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 解释：从图中可看出最后一层的节点不对称。
 *
 *
 *
 * 提示：
 *
 * 0 <= 节点个数 <= 1000
 *
 * 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/
 *
 *
 *
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func checkSymmetricTree(root *TreeNode) bool {

	var check func(*TreeNode, *TreeNode) bool
	check = func(p, q *TreeNode) bool {
		if p == nil && q == nil {
			return true
		}
		if p == nil || q == nil {
			return false
		}
		return p.Val == q.Val && check(p.Left, q.Right) && check(p.Right, q.Left)
	}

	return check(root, root)

}

// @lc code=end

/*
// @lcpr case=start
// [6,7,7,8,9,9,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

*/
